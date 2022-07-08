#pragma once
// �ײ����ƵĹ����� ��ʱ�����
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
	void changePosition(qint64 qiNum);  // �ı�λ��

	QString s = "0:0";
	QString t = "0:0";
private:

	int X = 56;
	qint64 druntime;//�ܽ���
	qint64 positontime;//��ǰ����
	QLabel* liftLabel;//��ʱ����ʾ
	QLabel* rightLabel;//�ұ�ʱ����ʾ
	QTimer* timer3;//ˢ��
	void paintEvent(QPaintEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
signals:
	void changeX();//�Զ���һ���ź�
public slots:
	void updatepos();
};
