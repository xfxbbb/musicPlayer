#include "LocalMusicWgt.h"
#include <QFileDialog>
#include <QStringListModel>
#include <QListView>
#include <QDebug>
#include <QString>
#pragma execution_character_set("utf-8")
CLocalMusicWgt::CLocalMusicWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	
	
	init();
}

CLocalMusicWgt::~CLocalMusicWgt()
{}

void CLocalMusicWgt::init()
{
	///初始化///
	_addSongBtn = ui.addSongBtn;
	_model = new QStandardItemModel;
	QStringList tableHeaders{ "歌曲名","歌手","专辑","操作" };
	for (auto index = 0; index < tableHeaders.count(); index++)
	{
		QStandardItem* header = new QStandardItem(tableHeaders[index]);
		_model->setHorizontalHeaderItem(index, header);  // 设置水平标题项
	}
	_delegate = new Delegate;
	_delegateStyle = new MuiscStyledItemDelegate;
	ui.musicView->setModel(_model);
	//ui.musicView->setItemDelegate(_delegate);  // 设置代理
	//ui.musicView->setItemDelegateForColumn(3, _delegateStyle);
	ui.musicView->setItemDelegate(_delegateStyle);
	ui.musicView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // 设置表头宽度自填充
	ui.musicView->setFocusPolicy(Qt::NoFocus);  // 去除选中的虚线框
	ui.musicView->setShowGrid(false);  // 隐藏网格线
	ui.musicView->verticalHeader()->hide();  // 隐藏垂直表头
	ui.musicView->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 设置不可编辑
	ui.musicView->setSelectionBehavior(QAbstractItemView::SelectRows);  // 设置选中为整行
	ui.musicView->setAlternatingRowColors(true);  // 奇偶行区分颜色
	ui.musicView->setSelectionMode(QAbstractItemView::SingleSelection);  // 设置只可单选
	//ui.musicView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);  // 设计表头固定
	ui.musicView->verticalHeader()->setDefaultSectionSize(50);
	//ui.musicView->verticalHeader()->setDefaultSectionSize(60);
	
	//ui.musicView->setColumnWidth(0, 120);
	//ui.musicView->setColumnWidth(1, 100);
	//ui.musicView->setColumnWidth(2, 100);
	//ui.musicView->setColumnWidth(3, 150);

	connect(ui.addSongBtn, & QPushButton::clicked, this, [=]() {
		QString strPath;  
		QStringList strPathList,outPutName;
		QFileDialog* fileDIg = new QFileDialog;
		strPathList = fileDIg->getOpenFileNames(this, "选择音乐","","音乐文件(*.ape;*.mp3;*.flac;*.wav)");
		int x = 0;
		for (auto i : strPathList)
		{
			strPath = i;
			qDebug() << "歌曲: " << i;
			QFileInfo file = QFileInfo(strPath);
			outPutName.append(file.fileName());
			//ui.musicView->set;
			QString strFileName = file.fileName();
			if (strFileName.contains(".mp3"))
			{
				int pos = strFileName.indexOf(".mp3");
				strFileName = strFileName.mid(0,pos);
			}
			QStandardItem* item = new QStandardItem(strFileName);
			item->setTextAlignment(Qt::AlignCenter);
			_model->setItem(x, item);
			x++;
		}

		});


}


