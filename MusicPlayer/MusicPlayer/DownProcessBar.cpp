#include "DownProcessBar.h"

DownProcessBar::DownProcessBar(QWidget *parent)
	: QWidget(parent)
{
    //255, 255, 255
	QPalette pal;
	pal.setColor(QPalette::WindowText, QColor(0,47,167));
	QFont font("Courier", 10);
	liftLabel = new QLabel(this);
	rightLabel = new QLabel(this);
	liftLabel->setAlignment(Qt::AlignCenter);
	rightLabel->setAlignment(Qt::AlignCenter);
	liftLabel->setGeometry(0, 10, 50, 50);
	//rightLabel->setGeometry(640, 10, 50, 50);
    rightLabel->setGeometry(920, 10, 50, 50);
	rightLabel->setFont(font);
	liftLabel->setFont(font);
	liftLabel->setPalette(pal);
	rightLabel->setPalette(pal);
	timer3 = new QTimer(this);
	timer3->setInterval(1000);
    rightLabel->setText(s);
    liftLabel->setText(t);
	connect(timer3, &QTimer::timeout, this, &DownProcessBar::updatepos);
}

DownProcessBar::~DownProcessBar()
{}

void DownProcessBar::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    QColor baseColor(27, 45, 47);
    QColor inColor(123, 156, 241);
    QColor outColor(240, 240, 240);
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(baseColor);
    QRectF rect = QRectF(55, 32, 860, 6);
    painter.drawRoundedRect(rect, 3, 3);
    painter.restore();
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(inColor);

    QRectF playrect = QRectF(55, 32, X - 63, 6);
    painter.drawRoundedRect(playrect, 3, 3);
    painter.restore();
    painter.setPen(Qt::NoPen);
    painter.setBrush(outColor);
    painter.drawEllipse(X - 7, 25, 20, 20);
    painter.restore();
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(inColor);
    painter.drawEllipse(X, 32, 6, 6);
    painter.restore();
}

void DownProcessBar::mousePressEvent(QMouseEvent* event)
{
    ///鼠标按下事件 点击更新音乐进度条///
    if (event->pos().y() > 30 && event->pos().y() < 50)
    {
        int value;
        value = event->pos().x();
        if (value < 55)
        {
            X = 56;
        }
        else if (value > 920)
        {
            X = 900;
        }
        else
        {
            X = value;
        }
        if (X <= 620)
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

void DownProcessBar::mouseMoveEvent(QMouseEvent* event)//可以进行拖动
{
    int value;
    value = event->pos().x();
    if (value < 55)
    {
        X = 56;
    }
    else if (value > 920)
    {
        X = 900;
    }
    else
    {
        X = event->pos().x();
    }
    emit changeX();//自定义了一个信号
    update();
    setCursor(Qt::PointingHandCursor);
}

/*

 * 外部使用一个定时器每隔1秒触发这个程序进行更新

*/

void DownProcessBar::updatepos()//显示歌曲时间进度
{
    float a;
    a = (float)positontime / (float)druntime;
    X = a * 580 + 56;
    qint64 time = druntime;
    double secondDouble = time / 1000;
    int minint = secondDouble / 60;
    int secondint = secondDouble - minint * 60;
    double secondtime1 = positontime / 1000;
    int minint1 = secondtime1 / 60;
    int secondint1 = secondtime1 - minint1 * 60;
    t = QString("%0:%1").arg(QString::number(minint1), QString::number(secondint1));
    s = QString("%0:%1").arg(QString::number(minint), QString::number(secondint));
    rightLabel->setText(s);
    liftLabel->setText(t);
    update();
}

void DownProcessBar::changePosition(qint64 xx)//外部写入当前时间
{
    this->positontime = xx;
}