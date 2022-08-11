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
	///�����ʼ��һЩ��Ϣ��������///
	_bIsMaxWindow = false;
	_songListWgt = new CSongListSmallWgt;
	//this->setWindowFlag(Qt::FramelessWindowHint);
	//this->setWindowFlag(Qt::FramelessWindowHint);
	_pPlayList = new QMediaPlaylist(this);  // �����б�
	_pMusicPlayer = new QMediaPlayer(this);  // ������
	_pPlayList->setPlaybackMode(QMediaPlaylist::Loop);

	this->resize(1250, 840);

	connect(ui.leftWgt, &CLeftWgt::signal_switch_wgt, this, &MusicPlayer::slots_switch_musicWgt);
	// �������ֲ����б�
	connect(GlobalSig::GetInstance(),&GlobalSig::signal_update_musiclist, this, &MusicPlayer::slots_handel_musicPlayerList);

	// ��������
	connect(GlobalSig::GetInstance(), &GlobalSig::signal_update_volume, this, &MusicPlayer::slots_update_volume);
	// bottomWgt���Ű�ť�ۺ���
	connect(ui.bottomWgt->_startBtn, &QPushButton::clicked, this, [=]() {
		std::cout << "���Ű�ť����.." << std::endl;
		pauseOrPlayMusic();
		});

	// ��һ��
	connect(ui.bottomWgt->_inSongBtn, &QPushButton::clicked, this, [=]() {
		QString str = ui.contentWgt->_localMusicWgt->_view->currentIndex().data().toString();
		ui.bottomWgt->_musicNameLabel->setText(str);
			if (_pMusicPlayer->state() == QMediaPlayer::PausedState)  // ����ǲ���״̬����ͣ
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

	// ��һ��
	connect(ui.bottomWgt->_nextSongBtn, &QPushButton::clicked, this, [=]() {
		QString str = ui.contentWgt->_localMusicWgt->_view->currentIndex().data().toString();
		ui.bottomWgt->_musicNameLabel->setText(str);
		if (_pMusicPlayer->state() == QMediaPlayer::PlayingState)//�ж������Ƿ񲥷�״̬������isaudioavaliable
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
		//�л��б�ѡ��״̬
		ui.contentWgt->_localMusicWgt->_view->selectRow(_pPlayList->currentIndex());
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

void MusicPlayer::pauseOrPlayMusic()
{
	/// ��ͣ/���� ///
	QString str = ui.contentWgt->_localMusicWgt->_view->currentIndex().data().toString();
	ui.bottomWgt->_musicNameLabel->setText(str);
	if (_pMusicPlayer->state() == QMediaPlayer::PlayingState)  // ����ǲ���״̬����ͣ
	{
		_pMusicPlayer->pause(); 
		std::cout << "������ͣ" << std::endl;
	}
	else {
		_pMusicPlayer->play();
		std::cout << "��������" << std::endl;
	}

}

void MusicPlayer::slots_handel_musicPlayerList(QStringList strMusicPath)
{
	/// ���������б� ///
	if (!strMusicPath.isEmpty()) 
	{
		for (int i = 0; i < strMusicPath.size(); ++i)
		{
			//QString personName = m_pModel->record(i).value("����").toString();
			QString strLocalFile = strMusicPath[i];
			qDebug() << strLocalFile << endl;

			_pPlayList->addMedia(QUrl::fromLocalFile(strLocalFile));

			QString Tmpstr = tr("����:%1").arg(_pPlayList->mediaCount());
			if (Tmpstr.contains(".mp3"))
				Tmpstr.remove(".mp3");
		}
		_pMusicPlayer->setMedia(_pPlayList);
	}
	
}

void MusicPlayer::slots_update_volume(int iValue)
{
	/// �������� ///
	_pMusicPlayer->setVolume(iValue);
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