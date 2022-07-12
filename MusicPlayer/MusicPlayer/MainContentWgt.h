#pragma once
// 右侧工作区主要界面类
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
	QStackedWidget* m_stackedWgt;
private:
	Ui::CMainContentWgtClass ui;
};
