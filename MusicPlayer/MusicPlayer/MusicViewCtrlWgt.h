#pragma once

#include <QWidget>
#include "ui_MusicViewCtrlWgt.h"

class MusicViewCtrlWgt : public QWidget
{
	Q_OBJECT

public:
	MusicViewCtrlWgt(QWidget *parent = nullptr);
	~MusicViewCtrlWgt();

private:
	Ui::MusicViewCtrlWgtClass ui;
};
