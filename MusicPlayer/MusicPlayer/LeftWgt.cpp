#include "LeftWgt.h"

CLeftWgt::CLeftWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.allMusicBtn->setIcon(QIcon(":/MusicPlayer/img/24gl-playlistMusic2.png"));
	ui.favouriteMusicBtn->setIcon(QIcon(":/MusicPlayer/img/24gl-playlistHeart2.png"));

	// 切换
	connect(ui.allMusicBtn, &QPushButton::clicked, [=]() {
		emit signal_switch_wgt(PublicData::MUSICWGTE::E_ALLMUSIC);  // 所有音乐界面
		});

	connect(ui.favouriteMusicBtn, &QPushButton::clicked, [=]() {
		emit signal_switch_wgt(PublicData::MUSICWGTE::E_FAVOURITEMUSIC);  // 收藏音乐界面
		});
}

CLeftWgt::~CLeftWgt()
{}
