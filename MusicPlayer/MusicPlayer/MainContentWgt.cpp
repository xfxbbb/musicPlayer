#include "MainContentWgt.h"

CMainContentWgt::CMainContentWgt(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	_stackedWgt = ui.stackedWidget;
	_localMusicWgt = qobject_cast<CLocalMusicWgt*>(ui.stackedWidget->widget(0));
	_wgt2 = qobject_cast<CFavouriteMusicWgt*>(ui.stackedWidget->widget(1));
}

CMainContentWgt::~CMainContentWgt()
{}
