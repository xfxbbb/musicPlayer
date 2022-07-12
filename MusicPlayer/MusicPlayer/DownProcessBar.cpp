#include "DownProcessBar.h"

DownProcessBar::DownProcessBar(QWidget *parent)
	: QWidget(parent)
{
    init();
}

DownProcessBar::~DownProcessBar()
{}

void DownProcessBar::init()
{
    ///��ʼ��///
    //255, 255, 255
    
    QPalette pal;
    pal.setColor(QPalette::WindowText, QColor(0, 47, 167));
    QFont font("Courier", 10);
    m_liftLabel = new QLabel(this);
    m_rightLabel = new QLabel(this);
    m_liftLabel->setAlignment(Qt::AlignCenter); // labelȫ���а�
    m_rightLabel->setAlignment(Qt::AlignCenter);
    m_liftLabel->setGeometry(0, 10, 50, 50);
    //rightLabel->setGeometry(640, 10, 50, 50);
    m_rightLabel->setGeometry(920, 10, 50, 50);
    m_rightLabel->setFont(font);
    m_liftLabel->setFont(font);
    m_liftLabel->setPalette(pal);
    m_rightLabel->setPalette(pal);
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    m_rightLabel->setText(m_s);
    m_liftLabel->setText(m_t);
    connect(m_timer, &QTimer::timeout, this, &DownProcessBar::updatepos);
}
void DownProcessBar::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);  // ƽ���任
    painter.setRenderHint(QPainter::Antialiasing);  // ��ֹ����
    QColor baseColor(27, 45, 47);  // ��ɫ
    QColor inColor(123, 156, 241);
    QColor outColor(240, 240, 240);
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(baseColor);
    QRectF rect = QRectF(55, 32, 860, 6);
    painter.drawRoundedRect(rect, 3, 3);  // Բ�Ǿ���
    painter.restore();
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(inColor);

    QRectF playrect = QRectF(55, 32, iX - 63, 6);
    painter.drawRoundedRect(playrect, 3, 3);
    painter.restore();
    painter.setPen(Qt::NoPen);
    painter.setBrush(outColor);
    painter.drawEllipse(iX - 7, 25, 20, 20);
    painter.restore();
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(inColor);
    painter.drawEllipse(iX, 32, 6, 6);
    painter.restore();  
}

void DownProcessBar::mousePressEvent(QMouseEvent* event)
{
    ///��갴���¼� ����������ֽ�����///
    if (event->pos().y() > 30 && event->pos().y() < 50)
    {
        int value;
        value = event->pos().x();
        if (value < 55)
        {
            iX = 56;
        }
        else if (value > 920)
        {
            iX = 900;
        }
        else
        {
            iX = value;
        }
        if (iX <= 620)
        {
            emit changeX();
        }
        update();
        setCursor(Qt::PointingHandCursor);
    }
    else
    {
        event->ignore();
    }

}

void DownProcessBar::mouseMoveEvent(QMouseEvent* event)//���Խ����϶�
{
    int value;
    value = event->pos().x();
    if (value < 55)
    {
        iX = 56;
    }
    else if (value > 920)
    {
        iX = 900;
    }
    else
    {
        iX = event->pos().x();
    }
    emit changeX();//�Զ�����һ���ź�
    update();
    setCursor(Qt::PointingHandCursor);
}

void DownProcessBar::updatepos()
{
    ///���¸�������///
    // ��Ĳ��� �������� ������ϸ��
    float a;
    a = (float)m_positontime / (float)m_druntime;
    iX = a * 580 + 56;
    qint64 time = m_druntime;  // ����������Ͱ�
    double secondDouble = time / 1000;
    int minint = secondDouble / 60;
    int secondint = secondDouble - minint * 60;
    double secondtime1 = m_positontime / 1000;
    int minint1 = secondtime1 / 60;
    int secondint1 = secondtime1 - minint1 * 60;
    m_t = QString("%0:%1").arg(QString::number(minint1), QString::number(secondint1));
    m_s = QString("%0:%1").arg(QString::number(minint), QString::number(secondint));
    m_rightLabel->setText(m_s);
    m_liftLabel->setText(m_t);
    update();
}

void DownProcessBar::changePosition(qint64 xx)
{
    ///�Ȱѽӿ������� �����˵///
    m_positontime = xx;
}