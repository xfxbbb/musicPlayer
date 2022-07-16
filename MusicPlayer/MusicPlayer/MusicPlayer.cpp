#include "MusicPlayer.h"
#include "LocalMusicWgt.h"
#include <QStringListModel>
#include <QFileDialog>
#include <QDir>
MusicPlayer::MusicPlayer(QWidget *parent)
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
    ui.closeBtn->hide();
    ui.maxBtn->hide();
    ui.minBtn->hide();

    connect(ui.closeBtn,&QPushButton::clicked,this,&MusicPlayer::slots_closeBtn_clicked);
    connect(ui.maxBtn, &QPushButton::clicked, this, &MusicPlayer::slots_maxBtn_clicked);
    connect(ui.minBtn, &QPushButton::clicked, this, &MusicPlayer::slots_minBtn_clicked);
    connect(ui.leftWgt, &CLeftWgt::signal_switch_wgt, this, &MusicPlayer::slots_switch_musicWgt);
    ui.titleWgt->installEventFilter(this);

    // bottomWgt���Ű�ť�ۺ���
    connect(ui.bottomWgt->_startBtn, &QPushButton::clicked, this, [=]() {
        if (!_songStatus)  //  Ĭ��Ϊ��ͣ ����󲥷�
        {

        }
        else 
        {
                
        }
        _songStatus = !_songStatus;
        });

    // չʾ����С�б�
    connect(ui.bottomWgt->_songListBtn, &QPushButton::clicked, this, [=]() {
        if (_songListWgt)
        {
            //_songListWgt->move(QCursor::pos());
            _songListWgt->show();
        }
        });
    connect(ui.contentWgt->_localMusicWgt->_addSongBtn, &QPushButton::clicked, this, [=]() {
        QFileDialog* fileDIg = new QFileDialog;
        QString strPath = fileDIg->getExistingDirectory(this, "�������");
        QDir dir(strPath);
        QStringList strItmes = dir.entryList(QStringList() << "*.mp3");
        QStringListModel* items = new QStringListModel(strItmes);
        ui.contentWgt->_listView->setModel(items);
     });
}

void MusicPlayer::setSongPlayerPath(QString strMusicPath)
{
    ///����///
}

void MusicPlayer::slots_closeBtn_clicked()
{
    ///title���Ĺرհ�ť�ۺ���///
    this->close();
}

void MusicPlayer::slots_maxBtn_clicked()
{
    ///title������󻯰�ť�ۺ��� ///
    if (!_bIsMaxWindow)
    {
        
        _beforeRec = this->geometry();  // �Ŵ�֮ǰ��¼��ǰ��Ļ�ߴ�
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
    }
    else
    {
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
    ///title������С����ť�ۺ���///
    qDebug() << "��С��";
    showMinimized();
}

bool MusicPlayer::eventFilter(QObject* obj, QEvent* eve)
{
    ///��д�¼�������///

    static QPoint mousePoint;  // ʹ�þ�̬ ����ȡ���λ��
    QMouseEvent* event = static_cast<QMouseEvent *>(eve);

    if (event->type() == QEvent::MouseButtonPress)
    {
        mousePoint = event->globalPos() - this->pos();  // ͨ���¼�λ�ü�ȥ����λ�� ��������λ��
    }
    else if (event->type() == QEvent::MouseMove)
    {
        this->move(event->globalPos() - mousePoint);  // �ƶ����¼�λ�ü�ȥ�ϴ����λ�õ�ƫ��
    }
    return true;
}

void MusicPlayer::slots_switch_musicWgt(PublicData::MUSICWGTE e)
{
    ///�л�����///
    if (e == PublicData::MUSICWGTE::E_ALLMUSIC)
    {
        // ��ʾȫ�����ֽ���
        ui.contentWgt->_stackedWgt->setCurrentIndex(PublicData::MUSICWGTE::E_ALLMUSIC);
    }
    else if (e == PublicData::MUSICWGTE::E_FAVOURITEMUSIC)
    {
         // ��ʾ�ղ����ֽ���
        ui.contentWgt->_stackedWgt->setCurrentIndex(PublicData::MUSICWGTE::E_FAVOURITEMUSIC);
    }

}