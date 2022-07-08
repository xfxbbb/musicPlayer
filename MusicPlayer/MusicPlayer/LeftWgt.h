#pragma once
//  ◊Û±ﬂΩÁ√Ê¿‡
#include <QWidget>
#include "ui_LeftWgt.h"

class CLeftWgt : public QWidget
{
	Q_OBJECT

public:
	CLeftWgt(QWidget *parent = nullptr);
	~CLeftWgt();

private:
	Ui::CLeftWgtClass ui;
};
