#include "VolumeWgt.h"

VolumeWgt::VolumeWgt(QWidget *parent)
	: QWidget(parent)
{

	ui.setupUi(this);
	init();
}

VolumeWgt::~VolumeWgt()
{}

void VolumeWgt::mousePressEvent(QMouseEvent * e)
{
	/// 鼠标按下事件 ///
	setAttribute(Qt::WA_NoMouseReplay);
	QWidget::mousePressEvent(e);
}

void VolumeWgt::init()
{
	/// 初始化 ///
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
	this->setFixedSize(40, 150);
	//this->hide();
	ui.VolumeSlider->setValue(99);
	ui.VolumeNum->setText("100");
	connect(ui.VolumeSlider, &QSlider::sliderMoved, this, &VolumeWgt::slots_change_volume_num);
	connect(ui.VolumeSlider, &QSlider::sliderMoved, this, &VolumeWgt::signal_slider_moved);

}

void VolumeWgt::slots_change_volume_num(int num)
{
	ui.VolumeNum->setText(QString::number(num));
}