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
	void init(); // ��ʼ��һЩ��Ϣ

private:
	int iX = 56;
	qint64 m_druntime;//�ܽ���
	qint64 m_positontime;//��ǰ����
	QLabel* m_liftLabel;//��ʱ����ʾ
	QLabel* m_rightLabel;//�ұ�ʱ����ʾ
	QTimer* m_timer;//ˢ��
	QString m_s = "6:0";  // label��ʼ��ʱ���
	QString m_t = "0:6";
protected:
	virtual void paintEvent(QPaintEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);
signals:
	void changeX();//�Զ���һ���ź�
public slots:
	void updatepos();  // ��������
};
