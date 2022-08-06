#include "SongListSmallWgt.h"

CSongListSmallWgt::CSongListSmallWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	connect(ui.backBtn, &QPushButton::clicked, this, [=]() {
		this->close();
		});
	this->setFixedSize(300, 300);
}

CSongListSmallWgt::~CSongListSmallWgt()
{}
