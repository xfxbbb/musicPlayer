#include "LocalMusicWgt.h"
#include <QFileDialog>
#include <QStringListModel>
#include <QDebug>
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
	
	// 添加本地音乐
	connect(ui.addSongBtn, &QPushButton::clicked, this, [=]() {
		QFileDialog* fileDIg = new QFileDialog;
		QString strPath = fileDIg->getExistingDirectory(this, "添加音乐");
		QDir dir(strPath);
		QStringList strItmes = dir.entryList(QStringList()<<"*.mp3");
		ui.listWidget->addItems(strItmes);
		ui.listWidget->item(0)->setSelected(true);
		PublicData::_strMusicPath = strPath;
		PublicData::_strMusicName = ui.listWidget->item(0)->text();
		qDebug() << "1231:" << PublicData::_strMusicPath << " ; 4565" << PublicData::_strMusicName;
		});

	// 索引发生改变
	connect(ui.listWidget, &QListWidget::currentRowChanged, [=](int currentRow) {
		PublicData::_strMusicName = ui.listWidget->item(currentRow)->text();
		});
}


