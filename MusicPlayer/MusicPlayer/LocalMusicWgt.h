#pragma once
// 本地音乐界面类
#include <QWidget>
#include "ui_LocalMusicWgt.h"
#include "PublicData.h"
#include <QListView>
#include <QTableView>
#include <QFileDialog>
#include <QFileInfo>
#include<QStandardItem>
#include<QStandardItemModel>
#include "Delegate.h"
#include "MusicViewCtrlWgt.h"
class CLocalMusicWgt : public QWidget
{
	Q_OBJECT

public:
	CLocalMusicWgt(QWidget *parent = nullptr);
	~CLocalMusicWgt();
	void init();  // 初始化
public:
	QListView* _listView;
	QTableView* _view;
	QPushButton* _addSongBtn;
	QStandardItemModel* _model;
signals:
	void signal_listViewIndexChange(QString itemTxt);
private:
	Ui::CLocalMusicWgtClass ui;
	Delegate* _delegate;
	MuiscStyledItemDelegate* _delegateStyle;
	MusicViewCtrlWgt* _ctrlWgt;
};
