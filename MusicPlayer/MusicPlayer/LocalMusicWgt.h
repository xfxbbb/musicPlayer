#pragma once
// 本地音乐界面类
#include <QWidget>
#include "ui_LocalMusicWgt.h"
#include "PublicData.h"

class CLocalMusicWgt : public QWidget
{
	Q_OBJECT

public:
	CLocalMusicWgt(QWidget *parent = nullptr);
	~CLocalMusicWgt();
	void init();  // 初始化
public:
	QListView* _listView;
	QPushButton* _addSongBtn;
signals:
	void signal_listViewIndexChange(QString itemTxt);
private:
	Ui::CLocalMusicWgtClass ui;
};
