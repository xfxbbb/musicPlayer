#include "SkiaView.h"

namespace SkiaUi {

	SkiaView::SkiaView(RenderType type) :_render_type{ type }, _cur_random_timer_id{ static_cast<int>(std::random_device{}() >> 1) }
	{
		sk_app::DisplayParams params;
		// MakeRasterForWin  MakeVulkanOfflineForWin
		if (type == RenderType::Cpu) {
			_draw_context = sk_app::window_context_factory::MakeRasterForWin(
				params, [this](void* buffer, size_t size, int width, int height) {
					_buffer = reinterpret_cast<std::byte*>(buffer);
					_buffer_size = size;
					_width = width;
					_height = height;
				});
		} else { //Gpu
			_draw_context = sk_app::window_context_factory::MakeVulkanOfflineForWin(
				params, [this](void* buffer, size_t size, int width, int height) {
					_buffer = reinterpret_cast<std::byte*>(buffer);
					_buffer_size = size;
					_width = width;
					_height = height;
				});
		}

	}
	SkiaView::~SkiaView() {
		if (_attr_obj.has_value()) {
			removeView(this);
		}
	}

	void SkiaView::registerTimer(std::chrono::system_clock::time_point time)
	{
		for (auto& it : _timer_data) {
			if (std::chrono::duration_cast<std::chrono::milliseconds>(time - it._cur_time) >= it._interval) {
				SkiaTimerEvent temp{ it._timer_id };
				onTimerEvent(temp);
				it._cur_time = time;
			}
		}

	}
	void SkiaView::registerMousePress(SkiaMouseEvent& evt) {
		onMousePressEvent(evt);
	}
	void SkiaView::registerMouseRelease(SkiaMouseEvent& evt) {
		onMouseReleaseEvent(evt);
	}
	void SkiaView::registerMouseDoubleClick(SkiaMouseEvent& evt) {
		onMouseDoubleClickEvent(evt);
	}
	void SkiaView::registerMouseMove(SkiaMouseEvent& evt) {
		onMouseMoveEvent(evt);
	}
	void SkiaView::registerWheel(SkiaWheelEvent& evt) {
		onWheelEvent(evt);
	}
	void SkiaView::registerKeyPress(SkiaKeyEvent& evt) {
		onKeyPressEvent(evt);
	}
	void SkiaView::registerKeyRelease(SkiaKeyEvent& evt) {
		onKeyReleaseEvent(evt);
	}
	void SkiaView::registerFocusOut(SkiaFocusEvent& evt) {
		onFocusOutEvent(evt);
	}
	void SkiaView::registerFocusIn(SkiaFocusEvent& evt) {
		onFocusInEvent(evt);
	}
	void SkiaView::registerEnter(SkiaEvent& evt) {
		onEnterEvent(evt);
	}
	void SkiaView::registerLeave(SkiaEvent& evt) {
		onLeaveEvent(evt);
	}
	void SkiaView::registerMove(SkiaMoveEvent& evt) {
		onMoveEvent(evt);
	}

	void SkiaView::registerPaint(std::function<void(SkiaView*, std::byte*, size_t, size_t, size_t)> fun) {
		auto surface = _draw_context->getBackbufferSurface();
		if (surface) {
			SkCanvas* skcanvas = surface->getCanvas();
			SkiaPaintEvent temp{ *skcanvas };
			onPaintEvent({ temp });
			surface->flushAndSubmit();
			_draw_context->swapBuffers();
			fun(this, _buffer, _buffer_size, _width, _height);

		}
	}

	void SkiaView::registerResize(SkiaResizeEvent& evt) {
		_width = static_cast<int>(evt.size().width());
		_height = static_cast<int>(evt.size().height());
		_draw_context->resize(_width, _height);
		onResizeEvent(evt);
	}
	void SkiaView::registerShow(SkiaShowEvent& evt) {
		onShowEvent(evt);
	}
	void SkiaView::registerHide(SkiaHideEvent& evt) {
		onHideEvent(evt);
	}

	void SkiaView::registerUpdate(std::function<void()> fun)
	{
		_update_fun = fun;
	}

	void SkiaView::killTimer(int timerId) {
		_timer_data.erase(_timer_data.begin(), std::find_if(_timer_data.begin(), _timer_data.end(), [&timerId](TimerOP& it) {
			return it._timer_id == timerId;
			}));
	}

	void SkiaView::setProperty(std::string key, std::any value) {
		_propertys.insert(std::make_pair(key, value));
	}
	std::any SkiaView::getProperty(std::string key) {
		if (hasProperty(key)) {
			return _propertys[key];
		} else {
			return {};
		}
	}

	bool SkiaView::hasProperty(std::string key) {
		return _propertys.contains(key);
	}

	RenderType SkiaView::getRenderType() {
		return _render_type;
	}

	void SkiaView::onTimerEvent(SkiaTimerEvent& evt) {}
	void SkiaView::onMousePressEvent(SkiaMouseEvent& evt) {}
	void SkiaView::onMouseReleaseEvent(SkiaMouseEvent& evt) {}
	void SkiaView::onMouseDoubleClickEvent(SkiaMouseEvent& evt) {}
	void SkiaView::onMouseMoveEvent(SkiaMouseEvent& evt) {}
	void SkiaView::onWheelEvent(SkiaWheelEvent& evt) {}
	void SkiaView::onKeyPressEvent(SkiaKeyEvent& evt) {}
	void SkiaView::onKeyReleaseEvent(SkiaKeyEvent& evt) {}
	void SkiaView::onFocusOutEvent(SkiaFocusEvent& evt) {}
	void SkiaView::onFocusInEvent(SkiaFocusEvent& evt) {}
	void SkiaView::onEnterEvent(SkiaEvent& evt) {}
	void SkiaView::onLeaveEvent(SkiaEvent& evt) {}
	void SkiaView::onMoveEvent(SkiaMoveEvent& evt) {}
	void SkiaView::onPaintEvent(SkiaPaintEvent& evt) {}
	void SkiaView::onResizeEvent(SkiaResizeEvent& evt) {}
	void SkiaView::onShowEvent(SkiaShowEvent& evt) {}
	void SkiaView::onHideEvent(SkiaHideEvent& evt) {}
	void SkiaView::update()
	{
		if (_update_fun) {
			_update_fun();
		}
	}
}