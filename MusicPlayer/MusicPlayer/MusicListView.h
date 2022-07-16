#pragma once
// �����б���
#include <QObject>
#include <QWidget>
#include <QListView>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QScrollBar>
#include <QDebug>
class CMusicListView  : public QListView
{
	Q_OBJECT

public:
	CMusicListView(QWidget *parent);
	~CMusicListView();
	void init();  // ��ʼ��һЩ����
protected:
	// ��д��Ҫ���¼�
	virtual void dragEnterEvent(QDragEnterEvent* event);
	virtual void dragMoveEvent(QDragMoveEvent* event);
	virtual void dropEvent(QDropEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);
signals:
	void signal_dropEvent(QPoint pos);  // ������ק�������ź�
	void signal_openMusicInfo(QPoint pos);  // �Ҽ����
	void signal_musicPlayl(int row);  // ˫�����������ź�
	void signal_musicLeftRelease();  // �������
private:
	QTimer* _leftDoubleClick;  // ���˫�������Ķ�ʱ��
	QTimer* _autoUpWheel;  // ���������Ķ�ʱ��
	QTimer* _autoDownWheel;  
	int _leftClickFlag{ 0 };  // ����������ı�־ Ĭ��Ϊ0 ��1Ϊ˫��
};
