///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Lewis Baker
// Licenced under MIT license. See LICENSE.txt for details.
///////////////////////////////////////////////////////////////////////////////

#include <cppcoro/net/socket.hpp>
#include <cppcoro/net/socket_recv_from_operation.hpp>

#include "socket_helpers.hpp"

#if CPPCORO_OS_WINNT

#include <WinSock2.h>
#include <WS2tcpip.h>

bool cppcoro::net::socket_recv_from_operation_impl::try_start(
    cppcoro::detail::io_operation_base& operation) noexcept
{
    static_assert(
        sizeof(m_sourceSockaddrStorage) >= sizeof(SOCKADDR_IN) &&
        sizeof(m_sourceSockaddrStorage) >= sizeof(SOCKADDR_IN6));
    static_assert(
        sockaddrStorageAlignment >= alignof(SOCKADDR_IN) &&
        sockaddrStorageAlignment >= alignof(SOCKADDR_IN6));

    // Need to read this flag before starting the operation, otherwise
    // it may be possible that the operation will complete immediately
    // on another thread, resume the coroutine and then destroy the
    // socket before we get a chance to read it.
    const bool skipCompletionOnSuccess = m_socket.skip_completion_on_success();

    m_sourceSockaddrLength = sizeof(m_sourceSockaddrStorage);

    DWORD numberOfBytesReceived = 0;
    DWORD flags = 0;
    int result = ::WSARecvFrom(
        m_socket.native_handle(),
        reinterpret_cast<WSABUF*>(&m_buffer),
        1,  // buffer count
        &numberOfBytesReceived,
        &flags,
        reinterpret_cast<sockaddr*>(&m_sourceSockaddrStorage),
        &m_sourceSockaddrLength,
        operation.get_overlapped(),
        nullptr);
    if (result == SOCKET_ERROR)
    {
        int errorCode = ::WSAGetLastError();
        if (errorCode != WSA_IO_PENDING)
        {
            // Failed synchronously.
            operation.m_errorCode = static_cast<DWORD>(errorCode);
            operation.m_numberOfBytesTransferred = numberOfBytesReceived;
            return false;
        }
    }
    else if (skipCompletionOnSuccess)
    {
        // Completed synchronously, no completion event will be posted to the IOCP.
        operation.m_errorCode = ERROR_SUCCESS;
        operation.m_numberOfBytesTransferred = numberOfBytesReceived;
        return false;
    }

    // Operation will complete asynchronously.
    return true;
}

void cppcoro::net::socket_recv_from_operation_impl::cancel(
    cppcoro::detail::io_operation_base& operation) noexcept
{
    (void)::CancelIoEx(
        reinterpret_cast<HANDLE>(m_socket.native_handle()), operation.get_overlapped());
}

std::tuple<std::size_t, cppcoro::net::ip_endpoint>
cppcoro::net::socket_recv_from_operation_impl::get_result(
    cppcoro::detail::io_operation_base& operation)
{
    if (operation.m_errorCode != ERROR_SUCCESS)
    {
        throw std::system_error(
            static_cast<int>(operation.m_errorCode),
            std::system_category(),
            "Error receiving message on socket: WSARecvFrom");
    }

    return std::make_tuple(
        static_cast<std::size_t>(operation.m_numberOfBytesTransferred),
        detail::sockaddr_to_ip_endpoint(*reinterpret_cast<SOCKADDR*>(&m_sourceSockaddrStorage)));
}

#elif CPPCORO_OS_LINUX

bool cppcoro::net::socket_recv_from_operation_impl::try_start(
    cppcoro::detail::io_operation_base &operation) noexcept {
    m_vec.iov_base = m_buffer.buffer;
    m_vec.iov_len = m_buffer.size;
    std::memset(&m_msgHdr, 0, sizeof(m_msgHdr));
    m_msgHdr.msg_name = &m_sourceSockaddrStorage;
    m_msgHdr.msg_namelen = sizeof(m_sourceSockaddrStorage);
    m_msgHdr.msg_iov = &m_vec;
    m_msgHdr.msg_iovlen = 1;
	return operation.m_ioQueue.transaction(operation.m_message)
		.recvmsg(m_socket.native_handle(), &m_msgHdr, m_socket.m_recvFlags)
		.commit();
}

void cppcoro::net::socket_recv_from_operation_impl::cancel(
    cppcoro::detail::io_operation_base &operation) noexcept {
    operation.m_ioQueue.transaction(operation.m_message)
        .cancel().commit();
}

std::tuple<std::size_t, cppcoro::net::ip_endpoint>
cppcoro::net::socket_recv_from_operation_impl::get_result(
    cppcoro::detail::io_operation_base &operation)
{
	auto size = operation.get_result();  // may throw errors
	if (size > m_buffer.size)
	{
		throw std::system_error{
			EAGAIN, std::generic_category()  // TODO is EAGAIN the good choice here ?
		};
	}
	return std::make_tuple(
		size,
		detail::sockaddr_to_ip_endpoint(*reinterpret_cast<SOCKADDR*>(&m_sourceSockaddrStorage)));
}

#endif
