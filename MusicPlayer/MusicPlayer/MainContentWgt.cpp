#include "MainContentWgt.h"

CMainContentWgt::CMainContentWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_stackedWgt = ui.stackedWidget;
}

CMainContentWgt::~CMainContentWgt()
{}
