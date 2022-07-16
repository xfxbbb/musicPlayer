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
	///��ʼ��һЩ����///
	
	// ���õ�ǰlistView�Ĳ���
	this->setFrameShape(QListView::NoFrame);  // �ޱ߿�
	this->setEditTriggers(QAbstractItemView::NoEditTriggers);  // ���ɱ༭
	this->setMovement(QListView::Free);  // ���ÿ����ƶ���item
	this->setAlternatingRowColors(true);  // ������ɫ
	this->setAcceptDrops(true);  // ���ý���drag��drop
	this->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel); // �������ܹ��� �ӵ�һ��
	this->verticalScrollBar()->setMaximum(100);
	this->verticalScrollBar()->setMinimum(0);
	this->verticalScrollBar()->setValue(0);

	// ��ʼ����ʱ��
	this->_leftDoubleClick = new QTimer;
	this->_autoUpWheel = new QTimer;
	this->_autoDownWheel = new QTimer;
	
	// ������˫����ʱ��
	connect(_leftDoubleClick, &QTimer::timeout, this, [=]() {
		this->_leftClickFlag = 0;  // ����־��λ
	});
#if 0
	// ����up��ʱ��
	connect(_autoUpWheel, &QTimer::timeout, this, [=]() {
		qDebug() << "����up statrt....";
		_autoUpWheel->stop();
		int value = this->verticalScrollBar()->value();
		int maxMum = this->verticalScrollBar()->maximum();
		
		//  �����ǰС�����
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

	// ����down��ʱ��
	connect(_autoDownWheel, &QTimer::timeout, this, [=]() {
		qDebug() << "����up statrt....";
		_autoDownWheel->stop();
		int value = this->verticalScrollBar()->value();
		int maxMum = this->verticalScrollBar()->maximum();

		//  �����ǰС�����
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
	///��д��ק�����¼�///
	event->acceptProposedAction();  // �����¼�
}

void CMusicListView::dragMoveEvent(QDragMoveEvent* event)
{
	///��д��ק�ƶ��¼�///

	// �Զ�����
	//��ֹͣ�����ط��Ĺ�����ʱ��
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
	///��д�Ϸ��¼�///
	//_autoUpWheel->stop();
	//_autoDownWheel->stop();

	QPoint dropPoint = QPoint(event->posF().x(), event->posF().y());
	emit signal_dropEvent(dropPoint);
}

void CMusicListView::mouseReleaseEvent(QMouseEvent* event)
{
	///��д��갴���¼�///
	QPoint point = QPoint(event->x(), event->y());
	// �����Ҽ�Ч��
	if (event->button() == Qt::RightButton)
	{
		emit signal_openMusicInfo(point);
	}
	// ˫�����Ч��
	if (event->button() == Qt::LeftButton)
	{
		if (_leftClickFlag == 0)      //����
		{
			_leftClickFlag = 1;
			//_leftDoubleClick->start(300);       //����300ms�Զ���λ���ڹ涨���ٴε�������Ϊ˫����
			emit signal_musicLeftRelease();
		}
		else                          //˫��
		{
			//qDebug()<<"˫��";
			_leftClickFlag = 0;
			/*�����Լ�ʵ���Լ����룬���Ƿ����ź�*/
			emit signal_musicPlayl(this->indexAt(point).row());
		}
	}
}

