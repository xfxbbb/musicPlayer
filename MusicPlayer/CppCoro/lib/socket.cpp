///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Lewis Baker
// Licenced under MIT license. See LICENSE.txt for details.
///////////////////////////////////////////////////////////////////////////////

#include <cppcoro/net/socket.hpp>

#include <cppcoro/net/socket_accept_operation.hpp>
#include <cppcoro/net/socket_connect_operation.hpp>
#include <cppcoro/net/socket_disconnect_operation.hpp>
#include <cppcoro/net/socket_recv_operation.hpp>
#include <cppcoro/net/socket_send_operation.hpp>

#include <cppcoro/io_service.hpp>
#include <cppcoro/on_scope_exit.hpp>

#include "socket_helpers.hpp"

#if CPPCORO_OS_WINNT
# include <WinSock2.h>
# include <WS2tcpip.h>
# include <MSWSock.h>
# include <Windows.h>
#define last_error WSAGetLastError()
#elif CPPCORO_OS_LINUX
#include <cstring>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#define last_error errno
#endif

namespace
{
	namespace local
	{
#if CPPCORO_OS_WINNT
		std::tuple<SOCKET, bool> create_socket(
			int addressFamily,
			int socketType,
			int protocol,
			HANDLE ioCompletionPort)
		{
			// Enumerate available protocol providers for the specified socket type.

			WSAPROTOCOL_INFOW stackInfos[4];
			std::unique_ptr<WSAPROTOCOL_INFOW[]> heapInfos;
			WSAPROTOCOL_INFOW* selectedProtocolInfo = nullptr;

			{
				INT protocols[] = { protocol, 0 };
				DWORD bufferSize = sizeof(stackInfos);
				WSAPROTOCOL_INFOW* infos = stackInfos;

				int protocolCount = ::WSAEnumProtocolsW(protocols, infos, &bufferSize);
				if (protocolCount == SOCKET_ERROR)
				{
					int errorCode = ::WSAGetLastError();
					if (errorCode == WSAENOBUFS)
					{
						DWORD requiredElementCount = bufferSize / sizeof(WSAPROTOCOL_INFOW);
						heapInfos = std::make_unique<WSAPROTOCOL_INFOW[]>(requiredElementCount);
						bufferSize = requiredElementCount * sizeof(WSAPROTOCOL_INFOW);
						infos = heapInfos.get();
						protocolCount = ::WSAEnumProtocolsW(protocols, infos, &bufferSize);
						if (protocolCount == SOCKET_ERROR)
						{
							errorCode = ::WSAGetLastError();
						}
					}

					if (protocolCount == SOCKET_ERROR)
					{
						throw std::system_error(
							errorCode,
							std::system_category(),
							"Error creating socket: WSAEnumProtocolsW");
					}
				}

				if (protocolCount == 0)
				{
					throw std::system_error(
						std::make_error_code(std::errc::protocol_not_supported));
				}

				for (int i = 0; i < protocolCount; ++i)
				{
					auto& info = infos[i];
					if (info.iAddressFamily == addressFamily && info.iProtocol == protocol && info.iSocketType == socketType)
					{
						selectedProtocolInfo = &info;
						break;
					}
				}

				if (selectedProtocolInfo == nullptr)
				{
					throw std::system_error(
						std::make_error_code(std::errc::address_family_not_supported));
				}
			}

			// WSA_FLAG_NO_HANDLE_INHERIT for SDKs earlier than Windows 7.
			constexpr DWORD flagNoInherit = 0x80;

			const DWORD flags = WSA_FLAG_OVERLAPPED | flagNoInherit;

			const SOCKET socketHandle = ::WSASocketW(
				addressFamily, socketType, protocol, selectedProtocolInfo, 0, flags);
			if (socketHandle == INVALID_SOCKET)
			{
				const int errorCode = ::WSAGetLastError();
				throw std::system_error(
					errorCode,
					std::system_category(),
					"Error creating socket: WSASocketW");
			}

			auto closeSocketOnFailure = cppcoro::on_scope_failure([&]
			{
				::closesocket(socketHandle);
			});

			// This is needed on operating systems earlier than Windows 7 to prevent
			// socket handles from being inherited. On Windows 7 or later this is
			// redundant as the WSA_FLAG_NO_HANDLE_INHERIT flag passed to creation
			// above causes the socket to be atomically created with this flag cleared.
			if (!::SetHandleInformation((HANDLE)socketHandle, HANDLE_FLAG_INHERIT, 0))
			{
				const DWORD errorCode = ::GetLastError();
				throw std::system_error(
					errorCode,
					std::system_category(),
					"Error creating socket: SetHandleInformation");
			}

			// Associate the socket with the I/O completion port.
			{
				const HANDLE result = ::CreateIoCompletionPort(
					(HANDLE)socketHandle,
					ioCompletionPort,
					ULONG_PTR(0),
					DWORD(0));
				if (result == nullptr)
				{
					const DWORD errorCode = ::GetLastError();
					throw std::system_error(
						static_cast<int>(errorCode),
						std::system_category(),
						"Error creating socket: CreateIoCompletionPort");
				}
			}

			const bool skipCompletionPortOnSuccess =
				(selectedProtocolInfo->dwServiceFlags1 & XP1_IFS_HANDLES) != 0;

			{
				UCHAR completionModeFlags = FILE_SKIP_SET_EVENT_ON_HANDLE;
				if (skipCompletionPortOnSuccess)
				{
					completionModeFlags |= FILE_SKIP_COMPLETION_PORT_ON_SUCCESS;
				}

				const BOOL ok = ::SetFileCompletionNotificationModes(
					(HANDLE)socketHandle,
					completionModeFlags);
				if (!ok)
				{
					const DWORD errorCode = ::GetLastError();
					throw std::system_error(
						static_cast<int>(errorCode),
						std::system_category(),
						"Error creating socket: SetFileCompletionNotificationModes");
				}
			}

			if (socketType == SOCK_STREAM)
			{
				// Turn off linger so that the destructor doesn't block while closing
				// the socket or silently continue to flush remaining data in the
				// background after ::closesocket() is called, which could fail and
				// we'd never know about it.
				// We expect clients to call Disconnect() or use CloseSend() to cleanly
				// shut-down connections instead.
				BOOL value = TRUE;
				const int result = ::setsockopt(socketHandle,
					SOL_SOCKET,
					SO_DONTLINGER,
					reinterpret_cast<const char*>(&value),
					sizeof(value));
				if (result == SOCKET_ERROR)
				{
					const int errorCode = ::WSAGetLastError();
					throw std::system_error(
						errorCode,
						std::system_category(),
						"Error creating socket: setsockopt(SO_DONTLINGER)");
				}
			}

			return std::make_tuple(socketHandle, skipCompletionPortOnSuccess);
		}
#else
		int create_socket(int domain, int type, int protocol) {
			int sock = socket(domain, type, protocol);
			if (sock < 0)
			{
                throw std::system_error(
                    last_error, std::system_category(), "Error creating socket: socket");
			}
			return sock;
		}
#endif
	}  // namespace local
}  // namespace

cppcoro::net::socket cppcoro::net::socket::create_tcpv4(io_service& ioSvc)
{
#if CPPCORO_OS_WINNT
	ioSvc.ensure_winsock_initialised();

	auto[socketHandle, skipCompletionPortOnSuccess] = local::create_socket(
		AF_INET, SOCK_STREAM, IPPROTO_TCP, ioSvc.native_iocp_handle());

	socket result(socketHandle, skipCompletionPortOnSuccess);

#elif CPPCORO_OS_LINUX
	auto socketHandle = local::create_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	socket result(ioSvc.io_queue(), socketHandle);
#endif

	result.m_localEndPoint = ipv4_endpoint();
	result.m_remoteEndPoint = ipv4_endpoint();
	return result;
}

cppcoro::net::socket cppcoro::net::socket::create_tcpv6(io_service& ioSvc)
{
#if CPPCORO_OS_WINNT
	ioSvc.ensure_winsock_initialised();

	auto[socketHandle, skipCompletionPortOnSuccess] = local::create_socket(
		AF_INET6, SOCK_STREAM, IPPROTO_TCP, ioSvc.native_iocp_handle());

	socket result(socketHandle, skipCompletionPortOnSuccess);

#elif CPPCORO_OS_LINUX
	auto socketHandle = local::create_socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
    socket result(ioSvc.io_queue(), socketHandle);
#endif

	result.m_localEndPoint = ipv6_endpoint();
	result.m_remoteEndPoint = ipv6_endpoint();
	return result;
}

cppcoro::net::socket cppcoro::net::socket::create_udpv4(io_service& ioSvc)
{
#if CPPCORO_OS_WINNT
	ioSvc.ensure_winsock_initialised();

	auto[socketHandle, skipCompletionPortOnSuccess] = local::create_socket(
		AF_INET, SOCK_DGRAM, IPPROTO_UDP, ioSvc.native_iocp_handle());

	socket result(socketHandle, skipCompletionPortOnSuccess);

#elif CPPCORO_OS_LINUX
	auto socketHandle = local::create_socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	socket result(ioSvc.io_queue(), socketHandle);
	// we use MSG_TRUNC flag to detect whatever the incoming datagram
	// fits within size, linux does not a MORE_DATA like error code.
	result.m_recvFlags = MSG_TRUNC;
#endif

	result.m_localEndPoint = ipv4_endpoint();
	result.m_remoteEndPoint = ipv4_endpoint();
	return result;
}

cppcoro::net::socket cppcoro::net::socket::create_udpv6(io_service& ioSvc)
{
#if CPPCORO_OS_WINNT
	ioSvc.ensure_winsock_initialised();

	auto[socketHandle, skipCompletionPortOnSuccess] = local::create_socket(
		AF_INET6, SOCK_DGRAM, IPPROTO_UDP, ioSvc.native_iocp_handle());

	socket result(socketHandle, skipCompletionPortOnSuccess);

#elif CPPCORO_OS_LINUX
	auto socketHandle = local::create_socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP);
	socket result(ioSvc.io_queue(), socketHandle);
	// we use MSG_TRUNC flag to detect whatever the incoming datagram
	// fits within size, linux does not a MORE_DATA like error code.
	result.m_recvFlags = MSG_TRUNC;
#endif

	result.m_localEndPoint = ipv6_endpoint();
	result.m_remoteEndPoint = ipv6_endpoint();
	return result;
}

cppcoro::net::socket::socket(socket&& other) noexcept
	: m_handle(std::exchange(other.m_handle, INVALID_SOCKET))
#if CPPCORO_OS_WINNT
	, m_skipCompletionOnSuccess(other.m_skipCompletionOnSuccess)
#elif CPPCORO_OS_LINUX
	, m_ioQueue(other.m_ioQueue)
	, m_recvFlags(other.m_recvFlags)
#endif
	, m_localEndPoint(std::move(other.m_localEndPoint))
	, m_remoteEndPoint(std::move(other.m_remoteEndPoint))
{}

cppcoro::net::socket::~socket()
{
	if (m_handle != INVALID_SOCKET)
	{
		::closesocket(m_handle);
	}
}

cppcoro::net::socket&
cppcoro::net::socket::operator=(socket&& other) noexcept
{
	auto handle = std::exchange(other.m_handle, INVALID_SOCKET);
	if (m_handle != INVALID_SOCKET)
	{
		::closesocket(m_handle);
	}

	m_handle = handle;
#if CPPCORO_OS_WINNT
	m_skipCompletionOnSuccess = other.m_skipCompletionOnSuccess;
#elif CPPCORO_OS_LINUX
	m_recvFlags = other.m_recvFlags;
#endif
	m_localEndPoint = other.m_localEndPoint;
	m_remoteEndPoint = other.m_remoteEndPoint;

	return *this;
}

void cppcoro::net::socket::bind(const ip_endpoint& localEndPoint)
{
	SOCKADDR_STORAGE sockaddrStorage = { 0 };
	SOCKADDR* sockaddr = reinterpret_cast<SOCKADDR*>(&sockaddrStorage);
	if (localEndPoint.is_ipv4())
	{
		SOCKADDR_IN& ipv4Sockaddr = *reinterpret_cast<SOCKADDR_IN*>(sockaddr);
		ipv4Sockaddr.sin_family = AF_INET;
		std::memcpy(&ipv4Sockaddr.sin_addr, localEndPoint.to_ipv4().address().bytes(), 4);
		ipv4Sockaddr.sin_port = htons(localEndPoint.to_ipv4().port());
	}
	else
	{
		SOCKADDR_IN6& ipv6Sockaddr = *reinterpret_cast<SOCKADDR_IN6*>(sockaddr);
		ipv6Sockaddr.sin6_family = AF_INET6;
		std::memcpy(&ipv6Sockaddr.sin6_addr, localEndPoint.to_ipv6().address().bytes(), 16);
		ipv6Sockaddr.sin6_port = htons(localEndPoint.to_ipv6().port());
	}

	int result = ::bind(m_handle, sockaddr, sizeof(sockaddrStorage));
	if (result != 0)
	{
		// WSANOTINITIALISED: WSAStartup not called
		// WSAENETDOWN: network subsystem failed
		// WSAEACCES: access denied
		// WSAEADDRINUSE: port in use
		// WSAEADDRNOTAVAIL: address is not an address that can be bound to
		// WSAEFAULT: invalid pointer passed to bind()
		// WSAEINPROGRESS: a callback is in progress
		// WSAEINVAL: socket already bound
		// WSAENOBUFS: system failed to allocate memory
		// WSAENOTSOCK: socket was not a valid socket.
		throw std::system_error(
            last_error,
			std::system_category(),
			"Error binding to endpoint: bind()");
	}

	socklen_t sockaddrLen = sizeof(sockaddrStorage);
	result = ::getsockname(m_handle, sockaddr, &sockaddrLen);
	if (result == 0)
	{
		m_localEndPoint = cppcoro::net::detail::sockaddr_to_ip_endpoint(*sockaddr);
	}
	else
	{
		m_localEndPoint = localEndPoint;
	}
}

void cppcoro::net::socket::listen()
{
	int result = ::listen(m_handle, SOMAXCONN);
	if (result != 0)
	{
		throw std::system_error(
			last_error,
			std::system_category(),
			"Failed to start listening on bound endpoint: listen");
	}
}

void cppcoro::net::socket::listen(std::uint32_t backlog)
{
	if (backlog > 0x7FFFFFFF)
	{
		backlog = 0x7FFFFFFF;
	}

	int result = ::listen(m_handle, (int)backlog);
	if (result != 0)
	{
		// WSANOTINITIALISED: WSAStartup not called
		// WSAENETDOWN: network subsystem failed
		// WSAEADDRINUSE: port in use
		// WSAEINPROGRESS: a callback is in progress
		// WSAEINVAL: socket not yet bound
		// WSAEISCONN: socket already connected
		// WSAEMFILE: no more socket descriptors available
		// WSAENOBUFS: system failed to allocate memory
		// WSAENOTSOCK: socket was not a valid socket.
		// WSAEOPNOTSUPP: The socket does not support listening

		throw std::system_error(
			last_error,
			std::system_category(), "Failed to start listening on bound endpoint: listen");
	}
}

cppcoro::net::socket_accept_operation
cppcoro::net::socket::accept(socket& acceptingSocket) noexcept
{
	return socket_accept_operation
	{
#if CPPCORO_OS_LINUX
		m_ioQueue,
#endif
        *this, acceptingSocket
	};
}

cppcoro::net::socket_accept_operation_cancellable
cppcoro::net::socket::accept(socket& acceptingSocket, cancellation_token ct) noexcept
{
	return socket_accept_operation_cancellable
	{
#if CPPCORO_OS_LINUX
        m_ioQueue,
#endif
        *this, acceptingSocket, std::move(ct)
	};
}

cppcoro::net::socket_connect_operation
cppcoro::net::socket::connect(const ip_endpoint& remoteEndPoint) noexcept
{
	return socket_connect_operation
	{
#if CPPCORO_OS_LINUX
        m_ioQueue,
#endif
        *this, remoteEndPoint
	};
}

cppcoro::net::socket_connect_operation_cancellable
cppcoro::net::socket::connect(const ip_endpoint& remoteEndPoint, cancellation_token ct) noexcept
{
	return socket_connect_operation_cancellable
	{
#if CPPCORO_OS_LINUX
        m_ioQueue,
#endif
			*this, remoteEndPoint, std::move(ct)
	};
}

cppcoro::net::socket_disconnect_operation cppcoro::net::socket::disconnect() noexcept
{
	return socket_disconnect_operation(
#if CPPCORO_OS_LINUX
		m_ioQueue,
#endif
		*this);
}

cppcoro::net::socket_disconnect_operation_cancellable
cppcoro::net::socket::disconnect(cancellation_token ct) noexcept
{
	return socket_disconnect_operation_cancellable
	{
#if CPPCORO_OS_LINUX
        m_ioQueue,
#endif
        *this, std::move(ct)
	};
}

cppcoro::net::socket_send_operation
cppcoro::net::socket::send(const void* buffer, std::size_t byteCount) noexcept
{
	return socket_send_operation
	{
#if CPPCORO_OS_LINUX
		m_ioQueue,
#endif
        *this, buffer, byteCount
	};
}

cppcoro::net::socket_send_operation_cancellable cppcoro::net::socket::send(
	const void* buffer, std::size_t byteCount, cancellation_token ct) noexcept
{
	return socket_send_operation_cancellable
	{
#if CPPCORO_OS_LINUX
        m_ioQueue,
#endif
        *this, buffer, byteCount, std::move(ct)
	};
}

cppcoro::net::socket_recv_operation
cppcoro::net::socket::recv(void* buffer, std::size_t byteCount) noexcept
{
	return socket_recv_operation
	{
#if CPPCORO_OS_LINUX
		m_ioQueue,
#endif
        *this, buffer, byteCount
	};
}

cppcoro::net::socket_recv_operation_cancellable
cppcoro::net::socket::recv(void* buffer, std::size_t byteCount, cancellation_token ct) noexcept
{
	return socket_recv_operation_cancellable
	{
#if CPPCORO_OS_LINUX
        m_ioQueue,
#endif
        *this, buffer, byteCount, std::move(ct)
	};
}

cppcoro::net::socket_recv_from_operation
cppcoro::net::socket::recv_from(void* buffer, std::size_t byteCount) noexcept
{
	return socket_recv_from_operation
	{
#if CPPCORO_OS_LINUX
		m_ioQueue,
#endif
        *this, buffer, byteCount
	};
}

cppcoro::net::socket_recv_from_operation_cancellable
cppcoro::net::socket::recv_from(void* buffer, std::size_t byteCount, cancellation_token ct) noexcept
{
	return socket_recv_from_operation_cancellable
	{
#if CPPCORO_OS_LINUX
		m_ioQueue,
#endif
        *this, buffer, byteCount, std::move(ct)
	};
}

cppcoro::net::socket_send_to_operation cppcoro::net::socket::send_to(
	const ip_endpoint& destination, const void* buffer, std::size_t byteCount) noexcept
{
	return socket_send_to_operation
	{
#if CPPCORO_OS_LINUX
        m_ioQueue,
#endif
        *this, destination, buffer, byteCount
	};
}

cppcoro::net::socket_send_to_operation_cancellable cppcoro::net::socket::send_to(
	const ip_endpoint& destination,
	const void* buffer,
	std::size_t byteCount,
	cancellation_token ct) noexcept
{
	return socket_send_to_operation_cancellable
	{
#if CPPCORO_OS_LINUX
        m_ioQueue,
#endif
        *this, destination, buffer, byteCount, std::move(ct)
	};
}

void cppcoro::net::socket::close_send()
{
	int result = ::shutdown(m_handle, SD_SEND);
	if (result == SOCKET_ERROR)
	{
		throw std::system_error(
			last_error, std::system_category(), "failed to close socket send stream: shutdown(SD_SEND)");
	}
}

void cppcoro::net::socket::close_recv()
{
	int result = ::shutdown(m_handle, SD_RECEIVE);
	if (result == SOCKET_ERROR)
	{
		throw std::system_error(
			last_error,
			std::system_category(),
			"failed to close socket receive stream: shutdown(SD_RECEIVE)");
	}
}

#if CPPCORO_OS_WINNT
cppcoro::net::socket::socket(
	cppcoro::detail::win32::socket_t handle, bool skipCompletionOnSuccess) noexcept
	: m_handle(handle)
	, m_skipCompletionOnSuccess(skipCompletionOnSuccess)
#elif CPPCORO_OS_LINUX
cppcoro::net::socket::socket(
	cppcoro::detail::lnx::io_queue& ioQueue, cppcoro::detail::lnx::fd_t handle) noexcept
	: m_handle(handle)
	, m_ioQueue(ioQueue)
#endif
{
}
