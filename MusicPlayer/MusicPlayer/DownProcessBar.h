#pragma once
// 底部绘制的滚动条 暂时用这个
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QPalette>
#include <QTimer>
#include <QLabel>
class DownProcessBar  : public QWidget
{
	Q_OBJECT

public:
	DownProcessBar(QWidget *parent);
	~DownProcessBar();
	void changePosition(qint64 qiNum);  // 改变位置

	QString s = "0:0";
	QString t = "0:0";
private:

	int X = 56;
	qint64 druntime;//总进度
	qint64 positontime;//当前进度
	QLabel* liftLabel;//左时间显示
	QLabel* rightLabel;//右边时间显示
	QTimer* timer3;//刷新
	void paintEvent(QPaintEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
signals:
	void changeX();//自定义一个信号
public slots:
	void updatepos();
};
