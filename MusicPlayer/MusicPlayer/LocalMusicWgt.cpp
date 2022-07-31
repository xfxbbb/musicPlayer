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
	///��ʼ��///

	QStringList tableHeaders{ "������","����","ר��","����" };
	for (auto index = 0; index < tableHeaders.count(); index++)
	{
		QStandardItem* header = new QStandardItem(tableHeaders[index]);
		_model->setHorizontalHeaderItem(index, header);  // ����ˮƽ������
	}

	ui.musicView->setModel(_model);
	ui.musicView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // ���ñ�ͷ��������
	ui.musicView->setShowGrid(false);  // ����������
	ui.musicView->verticalHeader()->hide();  // ���ش�ֱ��ͷ
	ui.musicView->setEditTriggers(QAbstractItemView::NoEditTriggers);  // ���ò��ɱ༭
	ui.musicView->setSelectionBehavior(QAbstractItemView::SelectRows);  // ����ѡ��Ϊ����
	ui.musicView->setAlternatingRowColors(true);  // ��ż��������ɫ

	ui.musicView->verticalHeader()->setDefaultSectionSize(60);
	connect(ui.addSongBtn, & QPushButton::clicked, this, [=]() {
		QString strPath;  
		QStringList strPathList,outPutName;
		QFileDialog* fileDIg = new QFileDialog;
		strPathList = fileDIg->getOpenFileNames(this, "ѡ������","","�����ļ�(*.ape;*.mp3;*.flac;*.wav)");
		int x = 0;
		for (auto i : strPathList)
		{
			strPath = i;
			qDebug() << "����: " << i;
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


