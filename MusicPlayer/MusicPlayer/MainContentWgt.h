#pragma once
// �Ҳ๤������Ҫ������
#include <QWidget>
#include <QStackedWidget>
#include "ui_MainContentWgt.h"

class CMainContentWgt : public QWidget
{
	Q_OBJECT

public:
	CMainContentWgt(QWidget *parent = nullptr);
	~CMainContentWgt(); 

public:
	QStackedWidget* _stackedWgt;
	QWidget* _localMusicWgt;
	QWidget* _wgt2;
private:
	Ui::CMainContentWgtClass ui;
};
