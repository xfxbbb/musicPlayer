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
	QStackedWidget* m_stackedWgt;
private:
	Ui::CMainContentWgtClass ui;
};
