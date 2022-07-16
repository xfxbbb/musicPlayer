#include "LocalMusicWgt.h"
#include <QFileDialog>
#include <QStringListModel>
#include <QListView>
#include <QDebug>
CLocalMusicWgt::CLocalMusicWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
	_listView = ui.listView;
	_addSongBtn = ui.addSongBtn;
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
	///≥ı ºªØ///
	
}


