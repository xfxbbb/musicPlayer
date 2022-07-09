#include "BottomWgt.h"

CBottomWgt::CBottomWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.startBtn, &QPushButton::clicked, this, [=]() {
		if (!m_bSongStatue)  // Ä¬ÈÏ Ò²ÊÇÔÝÍ£
		{
			QString strSheet = "#startBtn{ \
				border-image:url(:/MusicPlayer/img/ÔÝÍ£.png); \
				} \
			#startBtn:hover{ \
				border-image:url(:/MusicPlayer/img/ÔÝÍ£_hover.png); \
			}";

			QString strSheet2 = " \
            #startBtn{ \
                border-image: url(:/MusicPlayer/img/ÔÝÍ£.png); \
             } \
            #startBtn:hover{ \
               border-image: url(:/MusicPlayer/img/ÔÝÍ£_hover.png); \
             }";
			ui.startBtn->setStyleSheet(strSheet2);
			m_bSongStatue  = true;
		}
		else 
		{
			QString strSheet = "#startBtn{ \
				border-image:url(:/MusicPlayer/img/²¥·Å2.png); \
				} \
			#startBtn:hover{ \
				border-image:url(:/MusicPlayer/img/²¥·Å2_hover.png); \
			}";
			ui.startBtn->setStyleSheet(strSheet);
			m_bSongStatue = false;
		}
	});
}

CBottomWgt::~CBottomWgt()
{}
