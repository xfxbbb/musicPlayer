#pragma once
//  ��߽�����
#include <QWidget>
#include "ui_LeftWgt.h"
#include "PublicData.h"
class CLeftWgt : public QWidget
{
	Q_OBJECT

public:
	CLeftWgt(QWidget *parent = nullptr);
	~CLeftWgt();
//SIGANLS:
signals:
	void signal_switch_wgt(PublicData::MUSICWGTE);
private:
	Ui::CLeftWgtClass ui;
};
