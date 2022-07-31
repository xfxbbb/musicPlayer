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
	ui.closeBtn->hide();
	ui.maxBtn->hide();
	ui.minBtn->hide();
	this->resize(1250, 840);
	connect(ui.closeBtn, &QPushButton::clicked, this, &MusicPlayer::slots_closeBtn_clicked);
	connect(ui.maxBtn, &QPushButton::clicked, this, &MusicPlayer::slots_maxBtn_clicked);
	connect(ui.minBtn, &QPushButton::clicked, this, &MusicPlayer::slots_minBtn_clicked);
	connect(ui.leftWgt, &CLeftWgt::signal_switch_wgt, this, &MusicPlayer::slots_switch_musicWgt);
	ui.titleWgt->installEventFilter(this);

	// bottomWgt播放按钮槽函数
	connect(ui.bottomWgt->_startBtn, &QPushButton::clicked, this, [=]() {
		if (!_songStatus)  //  默认为暂停 点击后播放
		{

		} else {

		}
		_songStatus = !_songStatus;
		});

	// 展示音乐小列表
	connect(ui.bottomWgt->_songListBtn, &QPushButton::clicked, this, [=]() {
		if (_songListWgt) 
		{
			//_songListWgt->move(QCursor::pos());
			_songListWgt->show();
		}
		});
}

void MusicPlayer::setSongPlayerPath(QString strMusicPath)
{
	///设置///
}

void MusicPlayer::slots_closeBtn_clicked()
{
	///title栏的关闭按钮槽函数///
	this->close();
}

void MusicPlayer::slots_maxBtn_clicked()
{
	///title栏的最大化按钮槽函数 ///
	if (!_bIsMaxWindow) {

		_beforeRec = this->geometry();  // 放大之前记录当前屏幕尺寸
		this->setGeometry(QApplication::desktop()->availableGeometry(this));
		QString strSheet = " \
            #maxBtn{ \
                border-image:url(:/MusicPlayer/img/recover.png); \
             } \
            #maxBtn:hover{ \
                border-image:url(:/MusicPlayer/img/recover_hover.png); \
             }";

		ui.maxBtn->setStyleSheet(strSheet);
		_bIsMaxWindow = true;
	} else {
		this->setGeometry(_beforeRec);
		QString strSheet2 = " \
            #maxBtn{ \
                border-image:url(:/MusicPlayer/img/max.png); \
             } \
            #maxBtn:hover{ \
                border-image:url(:/MusicPlayer/img/max_hover.png); \
             }";
		ui.maxBtn->setStyleSheet(strSheet2);
		_bIsMaxWindow = false;
	}
}

void MusicPlayer::slots_minBtn_clicked()
{
	///title栏的最小化按钮槽函数///
	qDebug() << "最小化";
	showMinimized();
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