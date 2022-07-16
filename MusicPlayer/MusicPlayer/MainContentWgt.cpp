#include "MainContentWgt.h"

CMainContentWgt::CMainContentWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	_stackedWgt = ui.stackedWidget;
	_localMusicWgt = ui.stackedWidget->widget(0);
	_wgt2 = ui.stackedWidget->widget(1);  
}

CMainContentWgt::~CMainContentWgt()
{}
