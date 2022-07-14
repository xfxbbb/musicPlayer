#include "MusicPlayer.h"

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
    m_bIsMaxWindow = false;
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
}

void MusicPlayer::slots_closeBtn_clicked()
{
    ///title���Ĺرհ�ť�ۺ���///
    this->close();
}

void MusicPlayer::slots_maxBtn_clicked()
{
    ///title������󻯰�ť�ۺ��� ///
    if (!m_bIsMaxWindow)
    {
        
        m_beforeRec = this->geometry();  // �Ŵ�֮ǰ��¼��ǰ��Ļ�ߴ�
        this->setGeometry(QApplication::desktop()->availableGeometry(this));
        QString strSheet = " \
            #maxBtn{ \
                border-image:url(:/MusicPlayer/img/recover.png); \
             } \
            #maxBtn:hover{ \
                border-image:url(:/MusicPlayer/img/recover_hover.png); \
             }";
            
        ui.maxBtn->setStyleSheet(strSheet);
        m_bIsMaxWindow = true;
    }
    else
    {
        this->setGeometry(m_beforeRec);
        QString strSheet2 = " \
            #maxBtn{ \
                border-image:url(:/MusicPlayer/img/max.png); \
             } \
            #maxBtn:hover{ \
                border-image:url(:/MusicPlayer/img/max_hover.png); \
             }";
        ui.maxBtn->setStyleSheet(strSheet2);
        m_bIsMaxWindow = false;
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
        ui.contentWgt->m_stackedWgt->setCurrentIndex(PublicData::MUSICWGTE::E_ALLMUSIC);
    }
    else if (e == PublicData::MUSICWGTE::E_FAVOURITEMUSIC)
    {
         // ��ʾ�ղ����ֽ���
        ui.contentWgt->m_stackedWgt->setCurrentIndex(PublicData::MUSICWGTE::E_FAVOURITEMUSIC);
    }

}