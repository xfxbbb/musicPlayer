#pragma once
// �����϶���
#include <QWidget>
#include "ui_VolumeWgt.h"

class VolumeWgt : public QWidget
{
	Q_OBJECT

public:
	VolumeWgt(QWidget *parent = nullptr);
	~VolumeWgt();
private:
	virtual void mousePressEvent(QMouseEvent* e);  // ��д��갴���¼�
public:
	void init();  // ��ʼ��������
signals:
	void signal_slider_moved(int);
public slots:
	void slots_change_volume_num(int num);
private:
	Ui::VolumeWgtClass ui;
};
