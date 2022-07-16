#pragma once
// 音乐列表类
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
	void init();  // 初始化一些数据
protected:
	// 重写需要的事件
	virtual void dragEnterEvent(QDragEnterEvent* event);
	virtual void dragMoveEvent(QDragMoveEvent* event);
	virtual void dropEvent(QDropEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);
signals:
	void signal_dropEvent(QPoint pos);  // 发送拖拽结束的信号
	void signal_openMusicInfo(QPoint pos);  // 右键点击
	void signal_musicPlayl(int row);  // 双击播放音乐信号
	void signal_musicLeftRelease();  // 左键单击
private:
	QTimer* _leftDoubleClick;  // 左键双击启动的定时器
	QTimer* _autoUpWheel;  // 滚轮启动的定时器
	QTimer* _autoDownWheel;  
	int _leftClickFlag{ 0 };  // 鼠标左键点击的标志 默认为0 ，1为双击
};
