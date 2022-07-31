#pragma once

#include <concepts>
#include <type_traits>
#include <memory>
#include <functional>
#include <eventpp/eventqueue.h>
#include <eventpp/callbacklist.h>
#include "QCoroHandle.h"

constexpr auto live_data_queue_event = 0x22;

template<typename T>
concept pure_type = requires(T) {
	!std::is_const_v<T>;
	!std::is_reference_v<T>;
	!std::is_volatile_v<T>;
	std::is_constructible_v<T>;
	std::is_copy_constructible_v<T>;
};

enum class LiveDateWay {
	DirectWay,
	QueuedUIWay,
};

template<typename T>
class LiveDataImpl;

template<typename T>
using LiveData = std::shared_ptr<LiveDataImpl<T>>;

template<typename T>
class LiveDataImpl {
public:

	struct Token {
	private:
		Token() {
		}
		template<typename LD, typename... Args>
			requires pure_type<LD>
		friend LiveData<LD> makeLiveData(Args&&... args);
		friend class LiveDataImpl;
	};

	template<typename... Args>
	LiveDataImpl(Token token, Args&&... args) {
		_data = std::make_unique<T>(std::forward<Args>(args)...);
		handle = coro::QCoroHandle::instance()._callbackList.append([this]() {
			_queue_list.process();
			});
	}

	LiveDataImpl(const LiveDataImpl&) = delete;
	void operator=(const LiveDataImpl&) = delete;

	~LiveDataImpl() {
		coro::QCoroHandle::instance()._callbackList.remove(handle);
	}
	
	template<typename NValue>
	requires std::is_convertible_v<NValue, T>
	void setValue(NValue&& t) {
		*_data = t;
		_callback_list(*_data);
		_queue_list.enqueue(live_data_queue_event, *_data);
	}

	const T& getValue() {
		return *_data;
	}

	void observe(std::function<void(const T&)> fun, LiveDateWay way = LiveDateWay::DirectWay) {
		if (way == LiveDateWay::DirectWay) {
			_callback_list.append(fun);
			return;
		}
		if (way == LiveDateWay::QueuedUIWay) {
			_queue_list.appendListener(live_data_queue_event,fun);
		}
	}

private:

	std::unique_ptr<T> _data;
	eventpp::CallbackList<void(const T&)> _callback_list;
	eventpp::EventQueue<int, void(const T&)> _queue_list;
	eventpp::CallbackList<void()>::Handle handle;
};

template<typename LD, typename... Args>
requires pure_type<LD>
LiveData<LD> makeLiveData(Args&&... args) {
	LiveData lv_data = std::make_shared<LiveDataImpl<LD>>(typename LiveDataImpl<LD>::Token{}, std::forward<Args>(args)...);
	return lv_data;
}