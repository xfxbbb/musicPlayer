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
	CLocalMusicWgt* _localMusicWgt;
	CFavouriteMusicWgt* _wgt2;
private:
	Ui::CMainContentWgtClass ui;
};
