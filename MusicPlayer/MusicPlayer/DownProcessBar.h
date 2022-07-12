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
	void init(); // 初始化一些信息

private:
	int iX = 56;
	qint64 m_druntime;//总进度
	qint64 m_positontime;//当前进度
	QLabel* m_liftLabel;//左时间显示
	QLabel* m_rightLabel;//右边时间显示
	QTimer* m_timer;//刷新
	QString m_s = "6:0";  // label开始的时间吧
	QString m_t = "0:6";
protected:
	virtual void paintEvent(QPaintEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);
signals:
	void changeX();//自定义一个信号
public slots:
	void updatepos();  // 先留出来
};
