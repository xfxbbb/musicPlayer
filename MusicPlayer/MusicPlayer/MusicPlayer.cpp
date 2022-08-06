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
	///�����ʼ��һЩ��Ϣ��������///
	_bIsMaxWindow = false;
	_songListWgt = new CSongListSmallWgt;
	//this->setWindowFlag(Qt::FramelessWindowHint);
	//this->setWindowFlag(Qt::FramelessWindowHint);
	_pPlayList = new QMediaPlaylist(this);
	_pMusicPlayer = new QMediaPlayer(this);
	_pPlayList->setPlaybackMode(QMediaPlaylist::Loop);

	this->resize(1250, 840);

	connect(ui.leftWgt, &CLeftWgt::signal_switch_wgt, this, &MusicPlayer::slots_switch_musicWgt);

	// bottomWgt���Ű�ť�ۺ���
	connect(ui.bottomWgt->_startBtn, &QPushButton::clicked, this, [=]() {
		if (!_songStatus)  //  Ĭ��Ϊ��ͣ ����󲥷�
		{

		}
		else {

		}
		_songStatus = !_songStatus;
		});

	// չʾ����С�б�
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
	///����///
}

bool MusicPlayer::eventFilter(QObject* obj, QEvent* eve)
{
	///��д�¼�������///

	static QPoint mousePoint;  // ʹ�þ�̬ ����ȡ���λ��
	QMouseEvent* event = static_cast<QMouseEvent*>(eve);

	if (event->type() == QEvent::MouseButtonPress) {
		mousePoint = event->globalPos() - this->pos();  // ͨ���¼�λ�ü�ȥ����λ�� ��������λ��
	} else if (event->type() == QEvent::MouseMove) {
		this->move(event->globalPos() - mousePoint);  // �ƶ����¼�λ�ü�ȥ�ϴ����λ�õ�ƫ��
	}
	return QMainWindow::eventFilter(obj, eve);
}

void MusicPlayer::slots_switch_musicWgt(PublicData::MUSICWGTE e)
{
	///�л�����///
	if (e == PublicData::MUSICWGTE::E_ALLMUSIC) {
		// ��ʾȫ�����ֽ���
		ui.contentWgt->_stackedWgt->setCurrentIndex(PublicData::MUSICWGTE::E_ALLMUSIC);
	} else if (e == PublicData::MUSICWGTE::E_FAVOURITEMUSIC) {
		// ��ʾ�ղ����ֽ���
		ui.contentWgt->_stackedWgt->setCurrentIndex(PublicData::MUSICWGTE::E_FAVOURITEMUSIC);
	}

}