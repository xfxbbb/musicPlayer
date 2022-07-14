#include "LeftWgt.h"

CLeftWgt::CLeftWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// 切换
	connect(ui.allMusicBtn, &QPushButton::clicked, [=]() {
		emit signal_switch_wgt(PublicData::MUSICWGTE::E_ALLMUSIC);  // 所有音乐界面
		});

	connect(ui.favouriteMusicBtn, &QPushButton::clicked, [=]() {
		emit signal_switch_wgt(PublicData::MUSICWGTE::E_FAVOURITEMUSIC);  // 收藏音乐界面
		});

	// 设置组
	_btnGroup = new QButtonGroup(this);
	_btnGroup->addButton(ui.allMusicBtn);
	_btnGroup->addButton(ui.favouriteMusicBtn);
	_btnGroup->setExclusive(true);
}

CLeftWgt::~CLeftWgt()
{}
