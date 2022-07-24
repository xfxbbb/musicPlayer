#pragma once


#include <SkiaView.h>
#include <qobject.h>
#include <map>
#include <qwidget.h>
#include <SkiaView.h>
#include <qpainter.h>
#include <qevent.h>

namespace SkiaUi {
	class RegisterViewImplHelper : public QObject {
		Q_OBJECT

	public:
		RegisterViewImplHelper() : QObject{ nullptr } { _main_timer = startTimer(10); }

		RegisterViewImplHelper(const RegisterViewImplHelper&) = delete;
		RegisterViewImplHelper& operator=(const RegisterViewImplHelper&) = delete;

		static RegisterViewImplHelper& getInstance() {
			static RegisterViewImplHelper helper;
			return helper;
		}

		void insert(SkiaUi::SkiaView* key, QWidget* value);
		void remove(SkiaUi::SkiaView* skia_view);

		bool eventFilter(QObject* watched, QEvent* ent) override;

	protected:
		void timerEvent(QTimerEvent* evt) override;

	private:
		std::map<SkiaUi::SkiaView*, QWidget*> _data_skia_widget;
		int _main_timer;
	};

	struct QtRegisterViewImpl : public SkiaUi::AbstractRegisterViewImpl {
		using type = QWidget*;

		void registerView(SkiaUi::SkiaView* skia_view, std::any value) override {
			auto widget = std::any_cast<type>(value);
			SkiaUi::RegisterViewImplHelper::getInstance().insert(skia_view, widget);
		}

		void removeView(SkiaUi::SkiaView* skia_view) override { SkiaUi::RegisterViewImplHelper::getInstance().remove(skia_view); }
	};
}
