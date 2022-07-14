#include "BottomWgt.h"

CBottomWgt::CBottomWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.startBtn, &QPushButton::clicked, this, [=]() {
		if (!_bSongStatue)  // Ä¬ÈÏ Ò²ÊÇÔÝÍ£
		{
			_player = new QMediaPlayer;
			//_player->setMedia(QUrl::fromLocalFile(PublicData::_strMusicPath + "/" + PublicData::_strMusicName));
			_player->setMedia(QUrl::fromLocalFile("D:/music/MusicSound.mp3"));
			_player->play();
			_player->setVolume(50);
		}
		else 
		{
			_player->stop();
		}
		_bSongStatue = !_bSongStatue;
	});

	


}

CBottomWgt::~CBottomWgt()
{}
