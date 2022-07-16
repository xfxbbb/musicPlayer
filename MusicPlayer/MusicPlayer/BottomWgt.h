#pragma once
// 底部界面类
#include <QWidget>
#include "ui_BottomWgt.h"
#include "PublicData.h"
#include "SongListSmallWgt.h"
#include <QLabel>
class CBottomWgt : public QWidget
{
	Q_OBJECT

public:
	CBottomWgt(QWidget *parent = nullptr);
	~CBottomWgt();
public:
	QPushButton* _songListBtn;
	QPushButton* _startBtn;
	QPushButton* _inSongBtn;
	QPushButton* _nextSongBtn;
	QLabel* _musicNameLabel;
private:
	Ui::CBottomWgtClass ui;
};
