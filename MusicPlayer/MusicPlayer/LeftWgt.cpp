#include "LeftWgt.h"

CLeftWgt::CLeftWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// �л�
	connect(ui.allMusicBtn, &QPushButton::clicked, [=]() {
		emit signal_switch_wgt(PublicData::MUSICWGTE::E_ALLMUSIC);  // �������ֽ���
		});

	connect(ui.favouriteMusicBtn, &QPushButton::clicked, [=]() {
		emit signal_switch_wgt(PublicData::MUSICWGTE::E_FAVOURITEMUSIC);  // �ղ����ֽ���
		});

	// ������
	_btnGroup = new QButtonGroup(this);
	_btnGroup->addButton(ui.allMusicBtn);
	_btnGroup->addButton(ui.favouriteMusicBtn);
	_btnGroup->setExclusive(true);
}

CLeftWgt::~CLeftWgt()
{}
