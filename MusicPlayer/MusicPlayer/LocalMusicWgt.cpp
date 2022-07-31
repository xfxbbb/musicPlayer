#include "LocalMusicWgt.h"
#include <QFileDialog>
#include <QStringListModel>
#include <QListView>
#include <QDebug>
#pragma execution_character_set("utf-8")
CLocalMusicWgt::CLocalMusicWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//_listView = ui.listView;
	_addSongBtn = ui.addSongBtn;
	_model = new QStandardItemModel;

	init();
	//QStringList listModels;
	//for (auto i = 0; i < 300; i++)
	//{
	//	QString str = QString::number(i);
	//	listModels.append(str);
	//}
	//QStringListModel* listmodela = new QStringListModel(listModels);
	//ui.listView->setModel(listmodela);
	
}

CLocalMusicWgt::~CLocalMusicWgt()
{}

void CLocalMusicWgt::init()
{
	///初始化///

	QStringList tableHeaders{ "歌曲名","歌手","专辑","操作" };
	for (auto index = 0; index < tableHeaders.count(); index++)
	{
		QStandardItem* header = new QStandardItem(tableHeaders[index]);
		_model->setHorizontalHeaderItem(index, header);  // 设置水平标题项
	}

	ui.musicView->setModel(_model);
	ui.musicView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // 设置表头宽度自填充
	ui.musicView->setShowGrid(false);  // 隐藏网格线
	ui.musicView->verticalHeader()->hide();  // 隐藏垂直表头
	ui.musicView->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 设置不可编辑
	ui.musicView->setSelectionBehavior(QAbstractItemView::SelectRows);  // 设置选中为整行
	ui.musicView->setAlternatingRowColors(true);  // 奇偶行区分颜色

	ui.musicView->verticalHeader()->setDefaultSectionSize(60);
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
			QStandardItem* item = new QStandardItem(file.fileName());
			_model->setItem(x, item);
			x++;
		}
		//QStringListModel* items = new QStringListModel(strItmes);
		//ui.contentWgt->_listView->setModel(items);
		});


}


