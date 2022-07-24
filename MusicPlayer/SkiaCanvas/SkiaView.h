#pragma once

#include <exception>
#include <iostream>
#include <cstddef>
#include <functional>
#include <chrono>
#include <vector>
#include "WindowContext.h"
#include <any>
#include <random>
#include <tools/sk_app/DisplayParams.h>
#include <tools/sk_app/win/WindowContextFactory_win.h>
#include <memory>
#include <core/SkImage.h>
#include <core/SkSurface.h>
#include <core/SkCanvas.h>
#include <any>
#include <concepts>
#include <map>
#include "SkiaViewEvent.hpp"
#include "CommType.h"

namespace SkiaUi {

	class SkiaView;

	struct AbstractRegisterViewImpl {
		//to implement
		using type = void*;

		virtual void registerView(SkiaView*, std::any) = 0;

		virtual void removeView(SkiaView*) = 0;

		virtual ~AbstractRegisterViewImpl() {}
	};


	class SkiaView
	{
		template<typename T>
		friend struct RegisterViewImpl;
	public:

		struct TimerOP {
			template<typename _Rep, typename _Period>
			TimerOP(int timer_id, std::chrono::duration<_Rep, _Period> interval) :_timer_id{ timer_id }, _interval{ interval }, _cur_time{ std::chrono::system_clock::now() }{}
			int _timer_id;
			std::chrono::system_clock::time_point _cur_time;
			std::chrono::milliseconds _interval;
		};

		template<typename RegisterViewImpl, typename T>
			requires std::is_base_of_v<AbstractRegisterViewImpl, RegisterViewImpl>&&
			requires { typename RegisterViewImpl::type; }
		static void registerView(SkiaView* view, T&& t) {
			if (view->_attr_obj.has_value()) {
				removeView(view);
			}
			view->_register_view_impl = std::make_unique<RegisterViewImpl>();
			view->_register_view_impl->registerView(view, std::make_any<typename RegisterViewImpl::type>(std::forward<T>(t)));
		}

		static void removeView(SkiaView* view) {
			if (view->_register_view_impl) {
				view->_register_view_impl->removeView(view);
			}

		}

		SkiaView(RenderType type = RenderType::Cpu);
		SkiaView(const SkiaView&) = delete;
		SkiaView& operator=(const SkiaView&) = delete;
		virtual ~SkiaView();
		void registerTimer(std::chrono::system_clock::time_point time);
		void registerMousePress(SkiaMouseEvent& evt);
		void registerMouseRelease(SkiaMouseEvent& evt);
		void registerMouseDoubleClick(SkiaMouseEvent& evt);
		void registerMouseMove(SkiaMouseEvent& evt);
		void registerWheel(SkiaWheelEvent& evt);
		void registerKeyPress(SkiaKeyEvent& evt);
		void registerKeyRelease(SkiaKeyEvent& evt);
		void registerFocusOut(SkiaFocusEvent& evt);
		void registerFocusIn(SkiaFocusEvent& evt);
		void registerEnter(SkiaEvent& evt);
		void registerLeave(SkiaEvent& evt);
		void registerMove(SkiaMoveEvent& evt);

		void registerPaint(std::function<void(SkiaView*, std::byte*, size_t, size_t, size_t)> fun);

		void registerResize(SkiaResizeEvent& evt);
		void registerShow(SkiaShowEvent& evt);
		void registerHide(SkiaHideEvent& evt);
		void registerUpdate(std::function<void()> fun);

		template<typename _Rep, typename _Period>
		int startTimer(std::chrono::duration<_Rep, _Period> interval) {
			int timer_id = _cur_random_timer_id++;
			_timer_data.emplace_back(timer_id, interval);
			return timer_id;
		}
		void killTimer(int timerId);

		void setProperty(std::string key, std::any value);
		std::any getProperty(std::string key);
		bool hasProperty(std::string key);

		RenderType getRenderType();

		int width() {
			return _width;
		};
		int height() {
			return _height;
		}

	protected:
		virtual void onTimerEvent(SkiaTimerEvent& evt);
		virtual void onMousePressEvent(SkiaMouseEvent& evt);
		virtual void onMouseReleaseEvent(SkiaMouseEvent& evt);
		virtual void onMouseDoubleClickEvent(SkiaMouseEvent& evt);
		virtual void onMouseMoveEvent(SkiaMouseEvent& evt);
		virtual void onWheelEvent(SkiaWheelEvent& evt);
		virtual void onKeyPressEvent(SkiaKeyEvent& evt);
		virtual void onKeyReleaseEvent(SkiaKeyEvent& evt);
		virtual void onFocusOutEvent(SkiaFocusEvent& evt);
		virtual void onFocusInEvent(SkiaFocusEvent& evt);
		virtual void onEnterEvent(SkiaEvent& evt);
		virtual void onLeaveEvent(SkiaEvent& evt);
		virtual void onMoveEvent(SkiaMoveEvent& evt);
		virtual void onPaintEvent(SkiaPaintEvent& evt);
		virtual void onResizeEvent(SkiaResizeEvent& evt);
		virtual void onShowEvent(SkiaShowEvent& evt);
		virtual void onHideEvent(SkiaHideEvent& evt);

		void update();
	private:
		std::vector<TimerOP> _timer_data;
		int _cur_random_timer_id;
		std::unique_ptr<sk_app::WindowContext> _draw_context;


		std::byte* _buffer{ nullptr };
		size_t _buffer_size;
		int _width;
		int _height;

		std::any _attr_obj;
		std::unique_ptr<AbstractRegisterViewImpl> _register_view_impl;

		std::map<std::string, std::any> _propertys;

		RenderType _render_type;

		std::function<void()> _update_fun;

	};
}