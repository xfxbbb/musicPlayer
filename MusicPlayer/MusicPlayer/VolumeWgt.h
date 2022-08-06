#pragma once
// 声音拖动条
#include <QWidget>
#include "ui_VolumeWgt.h"

class VolumeWgt : public QWidget
{
	Q_OBJECT

public:
	VolumeWgt(QWidget *parent = nullptr);
	~VolumeWgt();
private:
	virtual void mousePressEvent(QMouseEvent* e);  // 重写鼠标按下事件
public:
	void init();  // 初始化音量条
signals:
	void signal_slider_moved(int);
public slots:
	void slots_change_volume_num(int num);
private:
	Ui::VolumeWgtClass ui;
};
