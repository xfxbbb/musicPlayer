#pragma once
// �ײ�������
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
	bool m_bSongStatue{ false };  // Ĭ��Ϊfalse Ҳ������ͣ״̬
};
