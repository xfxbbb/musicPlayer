#pragma once
// �ײ�������
#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include "ui_BottomWgt.h"
#include "PublicData.h"
class CBottomWgt : public QWidget
{
	Q_OBJECT

public:
	CBottomWgt(QWidget *parent = nullptr);
	~CBottomWgt();
	
private:
	Ui::CBottomWgtClass ui;
	bool _bSongStatue{ false };  // Ĭ��Ϊfalse Ҳ������ͣ״̬
	QMediaPlayer* _player;
};
