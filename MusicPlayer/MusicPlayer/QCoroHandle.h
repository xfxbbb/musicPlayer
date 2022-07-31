#pragma once

#include <QObject>
#include <cppcoro/io_service.hpp>
#include <cppcoro/task.hpp>
#include <cppcoro/when_all.hpp>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/detail/is_awaiter.hpp>
#include "Utils.hpp"
#include <eventpp/eventqueue.h>
#include <eventpp/callbacklist.h>

template<typename T>
class LiveDataImpl;

namespace coro {

	struct AsyncAction {

		struct promise_type {

			AsyncAction get_return_object() { return AsyncAction{}; }

			std::suspend_never initial_suspend() const noexcept { return {}; }

			std::suspend_never final_suspend() const noexcept { return {}; }

			void return_void() noexcept {}

			void unhandled_exception() { std::rethrow_exception(std::current_exception()); }
		};
	};

	//验证是否是协成任务回调函数
	template<typename Fun>
	concept is_awaiter_task = requires(Fun&&) {
		typename cppcoro::awaitable_traits<typename util::function_traits<std::decay_t<Fun>>::result_type>::awaiter_t;
		typename cppcoro::awaitable_traits<typename util::function_traits<std::decay_t<Fun>>::result_type>::await_result_t;
	};

	template<typename Fun>
	concept is_not_awaiter_task = !is_awaiter_task<Fun>;

	class QCoroHandle : private QObject {
		Q_OBJECT

	public:

		template<typename T>
		friend class LiveDataImpl;

		class token {
		private:
			token() {}
			friend class QCoroHandle;
		};

		QCoroHandle(token);
		~QCoroHandle();

		QCoroHandle(const QCoroHandle&) = delete;
		QCoroHandle& operator=(const QCoroHandle&) = delete;

		static void init();
		static QCoroHandle& instance() {
			return *_coro_handle;
		};
		cppcoro::io_service& io_service() { return _io_service; }

	protected:
		void timerEvent(QTimerEvent* event) override;

	private:
		static std::unique_ptr<QCoroHandle> _coro_handle;
		cppcoro::io_service _io_service;
		eventpp::CallbackList<void()> _callbackList;
	};
}
