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
    ///界面初始化一些信息都在这里///
    m_bIsMaxWindow = false;
    this->setWindowFlag(Qt::FramelessWindowHint);
    connect(ui.closeBtn,&QPushButton::clicked,this,&MusicPlayer::slots_closeBtn_clicked);
    connect(ui.maxBtn, &QPushButton::clicked, this, &MusicPlayer::slots_maxBtn_clicked);
    connect(ui.minBtn, &QPushButton::clicked, this, &MusicPlayer::slots_minBtn_clicked);

    ui.titleWgt->installEventFilter(this);
}

void MusicPlayer::slots_closeBtn_clicked()
{
    ///title栏的关闭按钮槽函数///
    this->close();
}

void MusicPlayer::slots_maxBtn_clicked()
{
    ///title栏的最大化按钮槽函数 ///
    if (!m_bIsMaxWindow)
    {
        
        m_beforeRec = this->geometry();  // 放大之前记录当前屏幕尺寸
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
    ///title栏的最小化按钮槽函数///
    qDebug() << "最小化";
    showMinimized();
}

bool MusicPlayer::eventFilter(QObject* obj, QEvent* eve)
{
    ///重写事件过滤器///

    static QPoint mousePoint;  // 使用静态 来获取鼠标位置
    QMouseEvent* event = static_cast<QMouseEvent *>(eve);

    if (event->type() == QEvent::MouseButtonPress)
    {
        mousePoint = event->globalPos() - this->pos();  // 通过事件位置减去窗口位置 计算鼠标点位置
    }
    else if (event->type() == QEvent::MouseMove)
    {
        this->move(event->globalPos() - mousePoint);  // 移动到事件位置减去上次鼠标位置的偏移
    }
    return true;
}