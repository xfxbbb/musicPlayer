#pragma once
// С�����б������
#include <QWidget>
#include "ui_SongListSmallWgt.h"

class CSongListSmallWgt : public QWidget
{
	Q_OBJECT

public:
	CSongListSmallWgt(QWidget *parent = nullptr);
	~CSongListSmallWgt();

private:
	Ui::CSongListSmallWgtClass ui;
};
