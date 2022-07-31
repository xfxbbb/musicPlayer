#include "SkiaViewQtAdapter.hpp"
#include <vulkan/vulkan.hpp>

constexpr auto PropertySkiaView = "SkiaView";
namespace SkiaUi {

	void RegisterViewImplHelper::insert(SkiaView* key, QWidget* value) {

		SkiaView* view = reinterpret_cast<SkiaView*>(value->property(PropertySkiaView).value<void*>());
		//卸载之前的
		if (view != nullptr) {
			if (view == key) {
				return;
			}
			remove(view);
		}

		_data_skia_widget.insert(std::make_pair(key, value));
		value->installEventFilter(this);
		value->setProperty(PropertySkiaView, QVariant::fromValue(reinterpret_cast<void*>(key)));

		SkSize size = SkSize::Make(value->width(), value->height());
		SkSize old_size = SkSize::Make(0, 0);
		SkiaResizeEvent sk_resize_event{ size, old_size };
		key->registerResize(sk_resize_event);
		//注册update函数
		key->registerUpdate([value]() {
			value->update();
			});
		value->update();
	}

	void RegisterViewImplHelper::remove(SkiaView* key) {
		if (_data_skia_widget.contains(key)) {
			auto widget = _data_skia_widget[key];
			widget->removeEventFilter(this);
			_data_skia_widget.erase(key);
		}
	}

	FocusReason conversionFocusReason(Qt::FocusReason reason) {
		FocusReason skia_focus_reason = FocusReason::NoFocusReason;
		switch (reason) {
		case Qt::FocusReason::MouseFocusReason:
			skia_focus_reason = FocusReason::MouseFocusReason;
			break;
		case Qt::FocusReason::TabFocusReason:
			skia_focus_reason = FocusReason::TabFocusReason;
			break;
		case Qt::FocusReason::BacktabFocusReason:
			skia_focus_reason = FocusReason::BacktabFocusReason;
			break;
		case Qt::FocusReason::ActiveWindowFocusReason:
			skia_focus_reason = FocusReason::ActiveWindowFocusReason;
			break;
		case Qt::FocusReason::PopupFocusReason:
			skia_focus_reason = FocusReason::PopupFocusReason;
			break;
		case Qt::FocusReason::ShortcutFocusReason:
			skia_focus_reason = FocusReason::ShortcutFocusReason;
			break;
		case Qt::FocusReason::MenuBarFocusReason:
			skia_focus_reason = FocusReason::MenuBarFocusReason;
			break;
		case Qt::FocusReason::OtherFocusReason:
			skia_focus_reason = FocusReason::OtherFocusReason;
			break;
		}
		return skia_focus_reason;
	}

	MouseButton conversionMouseButton(Qt::MouseButton reason) {
		MouseButton mouse_button = MouseButton::NoButton;
		switch (reason) {
		case Qt::MouseButton::LeftButton:
			mouse_button = MouseButton::LeftButton;
			break;
		case Qt::MouseButton::RightButton:
			mouse_button = MouseButton::RightButton;
			break;
		case Qt::MouseButton::MiddleButton:
			mouse_button = MouseButton::MiddleButton;
			break;
		}
		return mouse_button;
	}

	MouseButtons conversionMouseButtons(Qt::MouseButtons reason) {
		MouseButtons mouse_buttons = MouseButton::NoButton;
		bool left_button = reason & Qt::MouseButton::LeftButton;
		bool right_button = reason & Qt::MouseButton::RightButton;
		bool middle_button = reason & Qt::MouseButton::MiddleButton;
		if (left_button) {
			mouse_buttons |= MouseButton::LeftButton;
		}
		if (right_button) {
			mouse_buttons |= MouseButton::RightButton;
		}
		if (middle_button) {
			mouse_buttons |= MouseButton::MiddleButton;
		}
		return mouse_buttons;
	}

	KeyboardModifier conversionKeyboardModifier(Qt::KeyboardModifier reason) {
		KeyboardModifier keyboard_modifier = KeyboardModifier::NoModifier;
		switch (reason) {
		case Qt::KeyboardModifier::ShiftModifier:
			keyboard_modifier = KeyboardModifier::ShiftModifier;
			break;
		case Qt::KeyboardModifier::ControlModifier:
			keyboard_modifier = KeyboardModifier::ControlModifier;
			break;
		case Qt::KeyboardModifier::AltModifier:
			keyboard_modifier = KeyboardModifier::AltModifier;
			break;
		case Qt::KeyboardModifier::MetaModifier:
			keyboard_modifier = KeyboardModifier::MetaModifier;
			break;
		case Qt::KeyboardModifier::KeypadModifier:
			keyboard_modifier = KeyboardModifier::KeypadModifier;
			break;
		case Qt::KeyboardModifier::GroupSwitchModifier:
			keyboard_modifier = KeyboardModifier::GroupSwitchModifier;
			break;
		}
		return keyboard_modifier;
	}

	KeyboardModifiers conversionKeyboardModifiers(Qt::KeyboardModifiers reason) {
		KeyboardModifiers keyboard_modifiers = KeyboardModifier::NoModifier;
		bool shift_modifier = reason & Qt::KeyboardModifier::ShiftModifier;
		bool control_modifier = reason & Qt::KeyboardModifier::ControlModifier;
		bool alt_modifier = reason & Qt::KeyboardModifier::AltModifier;
		bool meta_modifier = reason & Qt::KeyboardModifier::MetaModifier;
		bool keypad_modifier = reason & Qt::KeyboardModifier::KeypadModifier;
		bool group_wwitch_modifier = reason & Qt::KeyboardModifier::GroupSwitchModifier;
		if (shift_modifier) {
			keyboard_modifiers |= KeyboardModifier::ShiftModifier;
		}
		if (control_modifier) {
			keyboard_modifiers |= KeyboardModifier::ControlModifier;
		}
		if (alt_modifier) {
			keyboard_modifiers |= KeyboardModifier::AltModifier;
		}
		if (meta_modifier) {
			keyboard_modifiers |= KeyboardModifier::MetaModifier;
		}
		if (keypad_modifier) {
			keyboard_modifiers |= KeyboardModifier::KeypadModifier;
		}
		if (group_wwitch_modifier) {
			keyboard_modifiers |= KeyboardModifier::GroupSwitchModifier;
		}
		return keyboard_modifiers;
	}

	ScrollPhase conversionScrollPhase(Qt::ScrollPhase value) {
		ScrollPhase scroll_phase = ScrollPhase::NoScrollPhase;
		switch (value) {
		case Qt::ScrollBegin:
			scroll_phase = ScrollPhase::ScrollBegin;
			break;
		case Qt::ScrollUpdate:
			scroll_phase = ScrollPhase::ScrollUpdate;
			break;
		case Qt::ScrollEnd:
			scroll_phase = ScrollPhase::ScrollEnd;
			break;
		case Qt::ScrollMomentum:
			scroll_phase = ScrollPhase::ScrollMomentum;
			break;
		}
		return scroll_phase;
	}

	bool RegisterViewImplHelper::eventFilter(QObject* watched, QEvent* evt) {

		SkiaView* view = reinterpret_cast<SkiaView*>(watched->property(PropertySkiaView).value<void*>());

		if (view == nullptr) {
			return QObject::eventFilter(watched, evt);
		}

		bool value = false;

		switch (evt->type()) {
		case QEvent::Type::MouseButtonPress:
		{
			QMouseEvent* temp_event = dynamic_cast<QMouseEvent*>(evt);
			SkPoint pos = SkPoint::Make(temp_event->pos().x(), temp_event->pos().y());
			SkPoint global_pos = SkPoint::Make(temp_event->globalPos().x(), temp_event->globalPos().y());
			SkiaMouseEvent mouse_event{ SkiaEvent::Type::MouseButtonPress,
									   pos,
									   global_pos,
									   conversionMouseButton(temp_event->button()),
									   conversionMouseButtons(temp_event->buttons()),
									   conversionKeyboardModifiers(temp_event->modifiers()) };
			view->registerMousePress(mouse_event);
		} break;
		case QEvent::Type::MouseButtonRelease:
		{
			QMouseEvent* temp_event = dynamic_cast<QMouseEvent*>(evt);
			SkPoint pos = SkPoint::Make(temp_event->pos().x(), temp_event->pos().y());
			SkPoint global_pos = SkPoint::Make(temp_event->globalPos().x(), temp_event->globalPos().y());
			SkiaMouseEvent mouse_event{ SkiaEvent::Type::MouseButtonRelease,
									   pos,
									   global_pos,
									   conversionMouseButton(temp_event->button()),
									   conversionMouseButtons(temp_event->buttons()),
									   conversionKeyboardModifiers(temp_event->modifiers()) };
			view->registerMouseRelease(mouse_event);
		} break;
		case QEvent::Type::MouseButtonDblClick:
		{
			QMouseEvent* temp_event = dynamic_cast<QMouseEvent*>(evt);
			SkPoint pos = SkPoint::Make(temp_event->pos().x(), temp_event->pos().y());
			SkPoint global_pos = SkPoint::Make(temp_event->globalPos().x(), temp_event->globalPos().y());
			SkiaMouseEvent mouse_event{ SkiaEvent::Type::MouseButtonDblClick,
									   pos,
									   global_pos,
									   conversionMouseButton(temp_event->button()),
									   conversionMouseButtons(temp_event->buttons()),
									   conversionKeyboardModifiers(temp_event->modifiers()) };
			view->registerMouseDoubleClick(mouse_event);
		} break;
		case QEvent::Type::MouseMove:
		{
			QMouseEvent* temp_event = dynamic_cast<QMouseEvent*>(evt);
			SkPoint pos = SkPoint::Make(temp_event->pos().x(), temp_event->pos().y());
			SkPoint global_pos = SkPoint::Make(temp_event->globalPos().x(), temp_event->globalPos().y());
			SkiaMouseEvent mouse_event{ SkiaEvent::Type::MouseMove,
									   pos,
									   global_pos,
									   conversionMouseButton(temp_event->button()),
									   conversionMouseButtons(temp_event->buttons()),
									   conversionKeyboardModifiers(temp_event->modifiers()) };
			view->registerMouseMove(mouse_event);
		} break;
		case QEvent::Type::KeyPress:
		{
			QKeyEvent* temp_event = dynamic_cast<QKeyEvent*>(evt);
			SkiaKeyEvent key_event{ SkiaEvent::Type::KeyRelease,
								   temp_event->key(),
								   conversionKeyboardModifiers(temp_event->modifiers()),
								   temp_event->nativeScanCode(),
								   temp_event->nativeVirtualKey(),
								   temp_event->nativeModifiers(),
								   temp_event->text().toStdString(),
								   temp_event->isAutoRepeat(),
								   temp_event->count() };
			view->registerKeyPress(key_event);
		} break;
		case QEvent::Type::KeyRelease:
		{
			QKeyEvent* temp_event = dynamic_cast<QKeyEvent*>(evt);
			SkiaKeyEvent key_event{ SkiaEvent::Type::KeyPress,
								   temp_event->key(),
								   conversionKeyboardModifiers(temp_event->modifiers()),
								   temp_event->nativeScanCode(),
								   temp_event->nativeVirtualKey(),
								   temp_event->nativeModifiers(),
								   temp_event->text().toStdString(),
								   temp_event->isAutoRepeat(),
								   temp_event->count() };

			view->registerKeyRelease(key_event);
		} break;
		case QEvent::Type::Wheel:
		{
			QWheelEvent* temp_event = dynamic_cast<QWheelEvent*>(evt);
			SkPoint pos = SkPoint::Make(temp_event->pos().x(), temp_event->pos().y());
			SkPoint global_pos = SkPoint::Make(temp_event->globalPos().x(), temp_event->globalPos().y());
			SkPoint pixel_delta = SkPoint::Make(temp_event->pixelDelta().x(), temp_event->pixelDelta().y());
			SkPoint angle_delta = SkPoint::Make(temp_event->angleDelta().x(), temp_event->angleDelta().y());

			SkiaWheelEvent wheel_event{ pos,
									   global_pos,
									   pixel_delta,
									   angle_delta,
									   conversionMouseButtons(temp_event->buttons()),
									   conversionKeyboardModifiers(temp_event->modifiers()),
									   conversionScrollPhase(temp_event->phase()),
									   temp_event->inverted() };
			view->registerWheel(wheel_event);
		} break;
		case QEvent::Type::FocusIn:
		{
			QFocusEvent* temp_event = dynamic_cast<QFocusEvent*>(evt);
			SkiaFocusEvent focus_event{ SkiaEvent::Type::FocusIn, conversionFocusReason(temp_event->reason()) };
			view->registerFocusIn(focus_event);
		} break;
		case QEvent::Type::FocusOut:
		{
			QFocusEvent* temp_event = dynamic_cast<QFocusEvent*>(evt);
			SkiaFocusEvent focus_event{ SkiaEvent::Type::FocusOut, conversionFocusReason(temp_event->reason()) };
			view->registerFocusOut(focus_event);
		} break;
		case QEvent::Type::Enter:
		{
			SkiaEvent enter_event{ SkiaEvent::Type::Enter };
			view->registerEnter(enter_event);
		} break;
		case QEvent::Type::Leave:
		{
			SkiaEvent leave_event{ SkiaEvent::Type::Leave };
			view->registerLeave(leave_event);
		} break;
		case QEvent::Type::Paint:
		{
			view->registerPaint([this](SkiaView* view, std::byte* buffer, size_t buffer_size, size_t width, size_t height) {
				QWidget* widget = _data_skia_widget[view];
				QPainter painter{ widget };
				QImage image{ reinterpret_cast<uchar*>(buffer), static_cast<int>(width), static_cast<int>(height), QImage::Format_ARGB32_Premultiplied };
				painter.drawImage(0, 0, image);
				});
		} break;
		case QEvent::Type::Move:
		{
			QMoveEvent* temp_event = dynamic_cast<QMoveEvent*>(evt);
			SkPoint pos = SkPoint::Make(temp_event->pos().x(), temp_event->pos().y());
			SkPoint old_pos = SkPoint::Make(temp_event->oldPos().x(), temp_event->oldPos().y());
			SkiaMoveEvent move_event{ pos, old_pos };
			view->registerMove(move_event);
		} break;
		case QEvent::Type::Resize:
		{
			QResizeEvent* resize_event = dynamic_cast<QResizeEvent*>(evt);
			SkSize size = SkSize::Make(resize_event->size().width(), resize_event->size().height());
			SkSize old_size = SkSize::Make(resize_event->oldSize().width(), resize_event->oldSize().height());
			SkiaResizeEvent sk_resize_event{ size, old_size };
			view->registerResize(sk_resize_event);
		} break;
		case QEvent::Type::Show:
		{
			SkiaShowEvent show_event;
			view->registerShow(show_event);
		} break;
		case QEvent::Type::Hide:
		{
			SkiaHideEvent hide_event;
			view->registerHide(hide_event);
		} break;
		default:
		{
			value = QObject::eventFilter(watched, evt);
		} break;
		}
		return value;
	}

	void RegisterViewImplHelper::timerEvent(QTimerEvent* evt) {
		if (_main_timer == evt->timerId()) {
			auto now_time = std::chrono::system_clock::now();
			for (auto& it : _data_skia_widget) {
				it.first->registerTimer(now_time);
			}
		}
	}
}