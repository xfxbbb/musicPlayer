#pragma once
// �������ֽ�����
#include <QWidget>
#include "ui_LocalMusicWgt.h"
#include "PublicData.h"

class CLocalMusicWgt : public QWidget
{
	Q_OBJECT

public:
	CLocalMusicWgt(QWidget *parent = nullptr);
	~CLocalMusicWgt();
	void init();  // ��ʼ��
public:
	QListView* _listView;
	QPushButton* _addSongBtn;
signals:
	void signal_listViewIndexChange(QString itemTxt);
private:
	Ui::CLocalMusicWgtClass ui;
};
