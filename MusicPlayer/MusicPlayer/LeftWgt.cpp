#include "LeftWgt.h"

CLeftWgt::CLeftWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.allMusicBtn->setIcon(QIcon(":/MusicPlayer/img/24gl-playlistMusic2.png"));
	ui.favouriteMusicBtn->setIcon(QIcon(":/MusicPlayer/img/24gl-playlistHeart2.png"));
}

CLeftWgt::~CLeftWgt()
{}
