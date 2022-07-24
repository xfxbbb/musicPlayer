#include "BottomWgt.h"
#include <QCursor>
#include <cmath>
#include <qthread.h>
#include <cppcoro/static_thread_pool.hpp>
#include <future>
#include "QCoroHandle.h"

constexpr int end_radius = 10;
constexpr int line_height = 10;
constexpr int padding = 14;

CBottomWgt::CBottomWgt(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	_songListBtn = ui.songListBtn;
	_musicNameLabel = ui.musicNameLabel;
	_startBtn = ui.startBtn;
	_inSongBtn = ui.inSongBtn;
	_nextSongBtn = ui.nextSongBtn;

	SkiaUi::SkiaView::registerView<SkiaUi::QtRegisterViewImpl>(&_sample, ui.processWidget);

	//����һ���ɹ۲�� int����
	lv_data = makeLiveData<int>();

	//�յ���������
	lv_data->observe([](int v) {
		qDebug() << "vvv: " << v;
	}, LiveDateWay::QueuedUIWay);

	QPushButton* btn = new QPushButton{ "test" ,this };
	connect(btn, &QPushButton::clicked, [this]() {
		//���ı���ֵ
		lv_data->setValue(100);
		});


	static cppcoro::static_thread_pool thread_pool{ 4 };
	//emit sig_test("hello", 26, 73.2);
	connect(this, &CBottomWgt::sig_test, [](QString name, int age, double weight)->coro::AsyncAction {
		int b = 100;
		co_await thread_pool.schedule();
		int a = 10000;
		qDebug() << "sub thread1" << ": " << QThread::currentThreadId();
		co_await coro::QCoroHandle::instance().io_service().schedule();
		qDebug() << "a: " << a;
		qDebug() << "sub thread2" << ": " << QThread::currentThreadId();

		/*auto runOnIoThread = [&]() -> cppcoro::task<> {
			co_await coro::QCoroHandle::instance().io_service().schedule();
			static int index = 0;
			qDebug() << "sub thread2" << ": " << QThread::currentThreadId();
			qDebug() << "index: " << index++;
		};

		std::vector<cppcoro::task<>> tasks;
		{
			for (int i = 0; i < 1000; ++i) {
				tasks.emplace_back(runOnIoThread());
			}
		}
		co_await cppcoro::when_all(std::move(tasks));*/
		});
}

CBottomWgt::~CBottomWgt()
{}

void MySample::onPaintEvent(SkiaUi::SkiaPaintEvent& evt)
{
	auto& ctx = evt.getCanvas();
	ctx.clear(SkColorSetARGB(255, 0, 255, 0));

	SkPaint paint;
	paint.setStyle(SkPaint::Style::kFill_Style);
	paint.setAntiAlias(true);
	paint.setColor(SkColorSetRGB(27, 45, 47));

	int hh = height();
	int ww = width();

	int total_w = ww - padding * 2;
	int line_y = (hh - line_height) / 2;

	//�ײ���
	ctx.drawRoundRect(SkRect::MakeXYWH(padding, line_y, total_w, line_height), 5, 5, paint);

	//ͨ������
	paint.setColor(SkColorSetRGB(123, 156, 241));
	float pass_x = _pass_value * total_w;
	ctx.drawRoundRect(SkRect::MakeXYWH(padding, line_y, pass_x, line_height), 5, 5, paint);

	//��ԲȦ
	//��Բ
	int __radius = end_radius;
	if (_pressed) {
		__radius += 2;
	}
	paint.setColor(SkColorSetRGB(240, 240, 240));
	ctx.drawCircle(pass_x + padding, hh / 2.0, __radius, paint);
	//СԲ
	paint.setColor(SkColorSetRGB(123, 156, 241));
	ctx.drawCircle(pass_x + padding, hh / 2.0, 4, paint);
}

void MySample::onMousePressEvent(SkiaUi::SkiaMouseEvent& evt)
{
	int hh = height();
	int ww = width();
	int __ww = ww - padding * 2;
	int __ty = (hh - end_radius * 2) / 2;
	constexpr int __extra_x = 8;
	SkRect mouse_rect = SkRect::MakeXYWH(padding - __extra_x, __ty, __ww + __extra_x * 2, end_radius * 2);

	int total_w = ww - padding * 2;
	float pass_x = _pass_value * total_w;
	float end_x = pass_x + padding;
	float end_y = (hh - line_height) / 2.0f;
	bool in_end = std::pow(evt.pos().x() - end_x, 2) + std::pow(evt.pos().y() - end_y, 2) <= std::pow(end_radius, 2);
	if (!mouse_rect.contains(evt.pos().x(), evt.pos().y()) &&
		!in_end) {
		return;
	}

	if (in_end) {
		//ѡ�е�ĩ�˵�
		_pressed = true;
	} else {
		float __value = evt.pos().x() - padding;
		_pass_value = __value / total_w;
		if (_pass_value < 0.0) {
			_pass_value = 0;
		} else if (_pass_value > 1.0) {
			_pass_value = 1.0;
		}
	}
	update();
}

void MySample::onMouseReleaseEvent(SkiaUi::SkiaMouseEvent& evt)
{
	if (_pressed) {
		_pressed = false;
		update();
	}
}

void MySample::onMouseMoveEvent(SkiaUi::SkiaMouseEvent& evt)
{
	if (_pressed) {

		int ww = width();
		int total_w = ww - padding * 2;
		float __value = evt.pos().x() - padding;
		_pass_value = __value / total_w;
		if (_pass_value < 0.0) {
			_pass_value = 0;
		} else if (_pass_value > 1.0) {
			_pass_value = 1.0;
		}
		update();
	}
}
