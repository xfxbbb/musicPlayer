#pragma once
// �Ҳ๤������Ҫ������
#include <QWidget>
#include "ui_MainContentWgt.h"

class CMainContentWgt : public QWidget
{
	Q_OBJECT

public:
	CMainContentWgt(QWidget *parent = nullptr);
	~CMainContentWgt(); 

private:
	Ui::CMainContentWgtClass ui;
};
