#include "VolumeWgt.h"
#include "GlSig.h"
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
	/// ��갴���¼� ///
	setAttribute(Qt::WA_NoMouseReplay);
	QWidget::mousePressEvent(e);
}

void VolumeWgt::init()
{
	/// ��ʼ�� ///
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
	/// ����label ///
	ui.VolumeNum->setText(QString::number(num));
	emit GlobalSig::GetInstance()->signal_update_volume(num);
}