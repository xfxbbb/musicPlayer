#include "MusicListView.h"

CMusicListView::CMusicListView(QWidget *parent)
	: QListView(parent)
{
	init();
}

CMusicListView::~CMusicListView()
{}

void CMusicListView::init()
{
	///初始化一些数据///
	
	// 设置当前listView的参数
	this->setFrameShape(QListView::NoFrame);  // 无边框
	this->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 不可编辑
	this->setMovement(QListView::Free);  // 设置可以移动的item
	this->setAlternatingRowColors(true);  // 交替颜色
	this->setAcceptDrops(true);  // 设置接收drag和drop
	this->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel); // 不开不能滚动 坑的一批
	this->verticalScrollBar()->setMaximum(100);
	this->verticalScrollBar()->setMinimum(0);
	this->verticalScrollBar()->setValue(0);

	// 初始化定时器
	this->_leftDoubleClick = new QTimer;
	this->_autoUpWheel = new QTimer;
	this->_autoDownWheel = new QTimer;
	
	// 鼠标左键双击定时器
	connect(_leftDoubleClick, &QTimer::timeout, this, [=]() {
		this->_leftClickFlag = 0;  // 将标志复位
	});
#if 0
	// 滚轮up定时器
	connect(_autoUpWheel, &QTimer::timeout, this, [=]() {
		qDebug() << "滚轮up statrt....";
		_autoUpWheel->stop();
		int value = this->verticalScrollBar()->value();
		int maxMum = this->verticalScrollBar()->maximum();
		
		//  如果当前小于最大
		if (value < maxMum)
		{
			this->verticalScrollBar()->setValue(value + 5);
			this->_autoUpWheel->start(50);
		}
		else 
		{
			this->_autoUpWheel->stop();
		}
	});

	// 滚轮down定时器
	connect(_autoDownWheel, &QTimer::timeout, this, [=]() {
		qDebug() << "滚轮up statrt....";
		_autoDownWheel->stop();
		int value = this->verticalScrollBar()->value();
		int maxMum = this->verticalScrollBar()->maximum();

		//  如果当前小于最大
		if (value < maxMum)
		{
			this->verticalScrollBar()->setValue(value - 5);
			this->_autoDownWheel->start(50);
		}
		else
		{
			this->_autoDownWheel->stop();
		}
		});
#endif 
}

void CMusicListView::dragEnterEvent(QDragEnterEvent * event)
{
	///重写拖拽进入事件///
	event->acceptProposedAction();  // 传递事件
}

void CMusicListView::dragMoveEvent(QDragMoveEvent* event)
{
	///重写拖拽移动事件///

	// 自动滚轮
	//先停止其他地方的滚动定时器
	//_autoUpWheel->stop();
	//_autoDownWheel->stop();

	int value = this->verticalScrollBar()->value();
	int maxMum = this->verticalScrollBar()->maximum();
	int minMum = this->verticalScrollBar()->minimum();
	if (event->posF().y() > 250)
	{
		if (value < maxMum)
		{
			this->verticalScrollBar()->setValue(value + 5);
			//_autoUpWheel->start(100);
		}
		return ;
	}
	if (event->posF().y() < 60)
	{
		if (value > minMum)
		{
			this->verticalScrollBar()->setValue(value - 5);
			//_autoDownWheel->start(100);
		}
		return ;
	}
}

void CMusicListView::dropEvent(QDropEvent* event)
{
	///重写拖放事件///
	//_autoUpWheel->stop();
	//_autoDownWheel->stop();

	QPoint dropPoint = QPoint(event->posF().x(), event->posF().y());
	emit signal_dropEvent(dropPoint);
}

void CMusicListView::mouseReleaseEvent(QMouseEvent* event)
{
	///重写鼠标按下事件///
	QPoint point = QPoint(event->x(), event->y());
	// 单击右键效果
	if (event->button() == Qt::RightButton)
	{
		emit signal_openMusicInfo(point);
	}
	// 双击左击效果
	if (event->button() == Qt::LeftButton)
	{
		if (_leftClickFlag == 0)      //单击
		{
			_leftClickFlag = 1;
			//_leftDoubleClick->start(300);       //开启300ms自动复位，在规定内再次单击，视为双击。
			emit signal_musicLeftRelease();
		}
		else                          //双击
		{
			//qDebug()<<"双击";
			_leftClickFlag = 0;
			/*下面自己实现自己代码，我是发出信号*/
			emit signal_musicPlayl(this->indexAt(point).row());
		}
	}
}

