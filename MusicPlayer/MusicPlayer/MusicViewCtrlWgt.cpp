#include "MusicViewCtrlWgt.h"

MusicViewCtrlWgt::MusicViewCtrlWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setVisible(false);
}

MusicViewCtrlWgt::~MusicViewCtrlWgt()
{}
