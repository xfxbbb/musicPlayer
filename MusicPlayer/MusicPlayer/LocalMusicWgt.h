#pragma once

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
private:
	Ui::CLocalMusicWgtClass ui;
};
