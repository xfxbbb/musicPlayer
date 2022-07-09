#pragma once
// 底部界面类
#include <QWidget>
#include "ui_BottomWgt.h"

class CBottomWgt : public QWidget
{
	Q_OBJECT

public:
	CBottomWgt(QWidget *parent = nullptr);
	~CBottomWgt();
	
private:
	Ui::CBottomWgtClass ui;
	bool m_bSongStatue{ false };  // 默认为false 也就是暂停状态
};
