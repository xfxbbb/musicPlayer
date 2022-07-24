///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Lewis Baker
// Licenced under MIT license. See LICENSE.txt for details.
///////////////////////////////////////////////////////////////////////////////

#include <cppcoro/net/socket_recv_operation.hpp>
#include <cppcoro/net/socket.hpp>

#if CPPCORO_OS_WINNT
#include <WS2tcpip.h>
#include <WinSock2.h>

bool cppcoro::net::socket_recv_operation_impl::try_start(
	cppcoro::detail::io_operation_base& operation) noexcept
{
	// Need to read this flag before starting the operation, otherwise
	// it may be possible that the operation will complete immediately
	// on another thread and then destroy the socket before we get a
	// chance to read it.
	const bool skipCompletionOnSuccess = m_socket.skip_completion_on_success();

	DWORD numberOfBytesReceived = 0;
	DWORD flags = 0;
	int result = ::WSARecv(
		m_socket.native_handle(),
		reinterpret_cast<WSABUF*>(&m_buffer),
		1,  // buffer count
		&numberOfBytesReceived,
		&flags,
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

void cppcoro::net::socket_recv_operation_impl::cancel(
	cppcoro::detail::io_operation_base& operation) noexcept
{
	(void)::CancelIoEx(
		reinterpret_cast<HANDLE>(m_socket.native_handle()), operation.get_overlapped());
}

#else

bool cppcoro::net::socket_recv_operation_impl::try_start(
	cppcoro::detail::io_operation_base& operation) noexcept
{
	return operation.m_ioQueue.transaction(operation.m_message)
		.recv(m_socket.native_handle(), m_buffer.buffer, m_buffer.size, m_socket.m_recvFlags)
		.commit();
}

void cppcoro::net::socket_recv_operation_impl::cancel(
	cppcoro::detail::io_operation_base& operation) noexcept
{
    operation.m_ioQueue.transaction(operation.m_message)
		.cancel()
		.commit();
}

std::size_t
cppcoro::net::socket_recv_operation_impl::get_result(cppcoro::detail::io_operation_base& operation)
{
	auto size = operation.get_result();
	if (size > m_buffer.size)
	{
		throw std::system_error{
			EAGAIN, std::generic_category()  // TODO is EAGAIN the good choice here ?
		};
	}
	return size;
}

#endif
