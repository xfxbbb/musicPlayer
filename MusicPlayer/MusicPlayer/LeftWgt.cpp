#include "LeftWgt.h"
#include <qpainter.h>
#include <qimage.h>


CLeftWgt::CLeftWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// 切换
	connect(ui.allMusicBtn, &QPushButton::clicked, [=]() {
		emit signal_switch_wgt(PublicData::MUSICWGTE::E_ALLMUSIC);  // 所有音乐界面
		});

	connect(ui.favouriteMusicBtn, &QPushButton::clicked, [=]() {
		emit signal_switch_wgt(PublicData::MUSICWGTE::E_FAVOURITEMUSIC);  // 收藏音乐界面
		});

	// 设置组
	_btnGroup = new QButtonGroup(this);
	_btnGroup->addButton(ui.allMusicBtn);
	_btnGroup->addButton(ui.favouriteMusicBtn);
	_btnGroup->setExclusive(true);
}

CLeftWgt::~CLeftWgt()
{}

void CLeftWgt::paintEvent(QPaintEvent * event)
{
	/*auto opt = _skia_draw.draw(width(), height(), [](SkCanvas& canvas) {
		SkPaint paint;
		paint.setColor(SkColorSetRGB(255, 50, 50));
		canvas.drawCircle(50,50,50, paint);
		});
	if (opt.has_value()) {
		auto buffer = opt.value();
		QPainter painter{ this };
		QImage image{ reinterpret_cast<uchar*>(buffer), width(), height(), QImage::Format_ARGB32_Premultiplied };
		painter.drawImage(0, 0, image);
	}*/
	QWidget::paintEvent(event);
}
