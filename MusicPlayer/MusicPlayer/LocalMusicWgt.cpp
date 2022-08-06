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
	///��ʼ��///
	_addSongBtn = ui.addSongBtn;
	_model = new QStandardItemModel;
	QStringList tableHeaders{ "������","����","ר��","����" };
	for (auto index = 0; index < tableHeaders.count(); index++)
	{
		QStandardItem* header = new QStandardItem(tableHeaders[index]);
		_model->setHorizontalHeaderItem(index, header);  // ����ˮƽ������
	}
	_delegate = new Delegate;
	_delegateStyle = new MuiscStyledItemDelegate;
	ui.musicView->setModel(_model);
	//ui.musicView->setItemDelegate(_delegate);  // ���ô���
	//ui.musicView->setItemDelegateForColumn(3, _delegateStyle);
	ui.musicView->setItemDelegate(_delegateStyle);
	ui.musicView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // ���ñ�ͷ��������
	ui.musicView->setFocusPolicy(Qt::NoFocus);  // ȥ��ѡ�е����߿�
	ui.musicView->setShowGrid(false);  // ����������
	ui.musicView->verticalHeader()->hide();  // ���ش�ֱ��ͷ
	ui.musicView->setEditTriggers(QAbstractItemView::NoEditTriggers);  // ���ò��ɱ༭
	ui.musicView->setSelectionBehavior(QAbstractItemView::SelectRows);  // ����ѡ��Ϊ����
	ui.musicView->setAlternatingRowColors(true);  // ��ż��������ɫ
	ui.musicView->setSelectionMode(QAbstractItemView::SingleSelection);  // ����ֻ�ɵ�ѡ
	//ui.musicView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);  // ��Ʊ�ͷ�̶�
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
		strPathList = fileDIg->getOpenFileNames(this, "ѡ������","","�����ļ�(*.ape;*.mp3;*.flac;*.wav)");
		int x = 0;
		for (auto i : strPathList)
		{
			strPath = i;
			qDebug() << "����: " << i;
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


