#include "BottomWgt.h"
#include <QCursor>
CBottomWgt::CBottomWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	_songListBtn = ui.songListBtn;
	_musicNameLabel = ui.musicNameLabel;
	_startBtn = ui.startBtn;
	_inSongBtn = ui.inSongBtn;
	_nextSongBtn = ui.nextSongBtn;
}

CBottomWgt::~CBottomWgt()
{}
