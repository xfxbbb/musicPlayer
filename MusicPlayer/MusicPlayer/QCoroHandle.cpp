#include "QCoroHandle.h"
#include <qdebug.h>

namespace coro {

	std::unique_ptr<QCoroHandle> QCoroHandle::_coro_handle;

	QCoroHandle::QCoroHandle(QCoroHandle::token)
		: QObject(nullptr)
	{
		startTimer(10);
	}

	QCoroHandle::~QCoroHandle()
	{}

	void QCoroHandle::init()
	{
		_coro_handle = std::make_unique<QCoroHandle>(QCoroHandle::token{});
	}

	void QCoroHandle::timerEvent(QTimerEvent* event)
	{
		_io_service.process_pending_events();
		_callbackList();
	}
}
