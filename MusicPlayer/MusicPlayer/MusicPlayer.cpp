#include "MusicPlayer.h"
#include "LocalMusicWgt.h"
#include <QStringListModel>
#include <QFileDialog>
#include <QDir>
#include "GlSig.h"
#include <iostream>
MusicPlayer::MusicPlayer(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	init();
}

MusicPlayer::~MusicPlayer()
{}

void MusicPlayer::init()
{
	///界面初始化一些信息都在这里///
	_bIsMaxWindow = false;
	_songListWgt = new CSongListSmallWgt;
	//this->setWindowFlag(Qt::FramelessWindowHint);
	//this->setWindowFlag(Qt::FramelessWindowHint);
	_pPlayList = new QMediaPlaylist(this);  // 播放列表
	_pMusicPlayer = new QMediaPlayer(this);  // 播放器
	_pPlayList->setPlaybackMode(QMediaPlaylist::Loop);

	this->resize(1250, 840);

	connect(ui.leftWgt, &CLeftWgt::signal_switch_wgt, this, &MusicPlayer::slots_switch_musicWgt);
	// 更新音乐播放列表
	connect(GlobalSig::GetInstance(),&GlobalSig::signal_update_musiclist, this, &MusicPlayer::slots_handel_musicPlayerList);

	// 更新声音
	connect(GlobalSig::GetInstance(), &GlobalSig::signal_update_volume, this, &MusicPlayer::slots_update_volume);
	// bottomWgt播放按钮槽函数
	connect(ui.bottomWgt->_startBtn, &QPushButton::clicked, this, [=]() {
		std::cout << "播放按钮按下.." << std::endl;
		pauseOrPlayMusic();
		});

	// 上一曲
	connect(ui.bottomWgt->_inSongBtn, &QPushButton::clicked, this, [=]() {
		QString str = ui.contentWgt->_localMusicWgt->_view->currentIndex().data().toString();
		ui.bottomWgt->_musicNameLabel->setText(str);
			if (_pMusicPlayer->state() == QMediaPlayer::PausedState)  // 如果是播放状态就暂停
			{
				if (_pPlayList->currentIndex() == 0)
				{
					QStandardItemModel* m_pModel = ui.contentWgt->_localMusicWgt->_model;
					_pPlayList->setCurrentIndex(m_pModel->rowCount() - 1);
					_pMusicPlayer->play();
				}
				else
				{
					_pPlayList->setCurrentIndex(_pPlayList->currentIndex() - 1);
					_pMusicPlayer->play();
				}
			}
		});

	// 下一曲
	connect(ui.bottomWgt->_nextSongBtn, &QPushButton::clicked, this, [=]() {
		QString str = ui.contentWgt->_localMusicWgt->_view->currentIndex().data().toString();
		ui.bottomWgt->_musicNameLabel->setText(str);
		if (_pMusicPlayer->state() == QMediaPlayer::PlayingState)//判断音乐是否播放状态，不用isaudioavaliable
		{
			QStandardItemModel* m_pModel = ui.contentWgt->_localMusicWgt->_model;
			if (_pPlayList->currentIndex() == m_pModel->rowCount() - 1)
			{
				_pPlayList->setCurrentIndex(0);
				_pMusicPlayer->play();
			}
			else
			{
				_pPlayList->setCurrentIndex(_pPlayList->currentIndex() + 1);
				_pMusicPlayer->play();
			}
		}
		//切换列表选中状态
		ui.contentWgt->_localMusicWgt->_view->selectRow(_pPlayList->currentIndex());
		});
	// 展示音乐小列表
	connect(ui.bottomWgt->_songListBtn, &QPushButton::clicked, this, [=]() {
		if (_songListWgt) 
		{
			//_songListWgt->move(QCursor::pos());
			QPoint moveTo = ui.bottomWgt->_songListBtn->mapToGlobal(QPoint(0, 0));
			_songListWgt->setGeometry(moveTo.x() , moveTo.y()-300, 300, 300);
			_songListWgt->show();
		}
		});
}

void MusicPlayer::setSongPlayerPath(QString strMusicPath)
{
	///设置///
}

void MusicPlayer::pauseOrPlayMusic()
{
	/// 暂停/播放 ///
	QString str = ui.contentWgt->_localMusicWgt->_view->currentIndex().data().toString();
	ui.bottomWgt->_musicNameLabel->setText(str);
	if (_pMusicPlayer->state() == QMediaPlayer::PlayingState)  // 如果是播放状态就暂停
	{
		_pMusicPlayer->pause(); 
		std::cout << "歌曲暂停" << std::endl;
	}
	else {
		_pMusicPlayer->play();
		std::cout << "歌曲播放" << std::endl;
	}

}

void MusicPlayer::slots_handel_musicPlayerList(QStringList strMusicPath)
{
	/// 处理音乐列表 ///
	if (!strMusicPath.isEmpty()) 
	{
		for (int i = 0; i < strMusicPath.size(); ++i)
		{
			//QString personName = m_pModel->record(i).value("歌手").toString();
			QString strLocalFile = strMusicPath[i];
			qDebug() << strLocalFile << endl;

			_pPlayList->addMedia(QUrl::fromLocalFile(strLocalFile));

			QString Tmpstr = tr("歌曲:%1").arg(_pPlayList->mediaCount());
			if (Tmpstr.contains(".mp3"))
				Tmpstr.remove(".mp3");
		}
		_pMusicPlayer->setMedia(_pPlayList);
	}
	
}

void MusicPlayer::slots_update_volume(int iValue)
{
	/// 更新音量 ///
	_pMusicPlayer->setVolume(iValue);
}

bool MusicPlayer::eventFilter(QObject* obj, QEvent* eve)
{
	///重写事件过滤器///

	static QPoint mousePoint;  // 使用静态 来获取鼠标位置
	QMouseEvent* event = static_cast<QMouseEvent*>(eve);

	if (event->type() == QEvent::MouseButtonPress) {
		mousePoint = event->globalPos() - this->pos();  // 通过事件位置减去窗口位置 计算鼠标点位置
	} else if (event->type() == QEvent::MouseMove) {
		this->move(event->globalPos() - mousePoint);  // 移动到事件位置减去上次鼠标位置的偏移
	}
	return QMainWindow::eventFilter(obj, eve);
}

void MusicPlayer::slots_switch_musicWgt(PublicData::MUSICWGTE e)
{
	///切换界面///
	if (e == PublicData::MUSICWGTE::E_ALLMUSIC) {
		// 显示全部音乐界面
		ui.contentWgt->_stackedWgt->setCurrentIndex(PublicData::MUSICWGTE::E_ALLMUSIC);
	} else if (e == PublicData::MUSICWGTE::E_FAVOURITEMUSIC) {
		// 显示收藏音乐界面
		ui.contentWgt->_stackedWgt->setCurrentIndex(PublicData::MUSICWGTE::E_FAVOURITEMUSIC);
	}

}