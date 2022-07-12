#pragma once

#include <QWidget>
#include "ui_FavouriteMusicWgt.h"

class CFavouriteMusicWgt : public QWidget
{
	Q_OBJECT

public:
	CFavouriteMusicWgt(QWidget *parent = nullptr);
	~CFavouriteMusicWgt();

private:
	Ui::CFavouriteMusicWgtClass ui;
};
