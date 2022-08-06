#include "MusicPlayer.h"
#include "LocalMusicWgt.h"
#include <QStringListModel>
#include <QFileDialog>
#include <QDir>

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
	_pPlayList = new QMediaPlaylist(this);
	_pMusicPlayer = new QMediaPlayer(this);
	_pPlayList->setPlaybackMode(QMediaPlaylist::Loop);

	this->resize(1250, 840);

	connect(ui.leftWgt, &CLeftWgt::signal_switch_wgt, this, &MusicPlayer::slots_switch_musicWgt);

	// bottomWgt播放按钮槽函数
	connect(ui.bottomWgt->_startBtn, &QPushButton::clicked, this, [=]() {
		if (!_songStatus)  //  默认为暂停 点击后播放
		{

		}
		else {

		}
		_songStatus = !_songStatus;
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