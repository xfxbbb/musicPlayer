#pragma once

#include <QWidget>
#include "ui_LocalMusicWgt.h"

class CLocalMusicWgt : public QWidget
{
	Q_OBJECT

public:
	CLocalMusicWgt(QWidget *parent = nullptr);
	~CLocalMusicWgt();

private:
	Ui::CLocalMusicWgtClass ui;
};
