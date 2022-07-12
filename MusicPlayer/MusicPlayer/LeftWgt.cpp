#include "LeftWgt.h"

CLeftWgt::CLeftWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.allMusicBtn->setIcon(QIcon(":/MusicPlayer/img/24gl-playlistMusic2.png"));
	ui.favouriteMusicBtn->setIcon(QIcon(":/MusicPlayer/img/24gl-playlistHeart2.png"));

	// �л�
	connect(ui.allMusicBtn, &QPushButton::clicked, [=]() {
		emit signal_switch_wgt(PublicData::MUSICWGTE::E_ALLMUSIC);  // �������ֽ���
		});

	connect(ui.favouriteMusicBtn, &QPushButton::clicked, [=]() {
		emit signal_switch_wgt(PublicData::MUSICWGTE::E_FAVOURITEMUSIC);  // �ղ����ֽ���
		});
}

CLeftWgt::~CLeftWgt()
{}
