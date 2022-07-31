#pragma once
//  ◊Û±ﬂΩÁ√Ê¿‡
#include <QWidget>
#include "ui_LeftWgt.h"
#include "PublicData.h"
#include <QButtonGroup>
#include <SkiaDraw.h>

class CLeftWgt : public QWidget
{
	Q_OBJECT

public:
	CLeftWgt(QWidget *parent = nullptr);
	~CLeftWgt();
//SIGANLS:
signals:
	void signal_switch_wgt(PublicData::MUSICWGTE);

protected:
	void paintEvent(QPaintEvent* event) override;
private:
	Ui::CLeftWgtClass ui;
	QButtonGroup* _btnGroup;

	SkiaUi::SkiaDraw _skia_draw;
};
