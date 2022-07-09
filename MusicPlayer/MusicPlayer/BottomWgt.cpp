#include "BottomWgt.h"

CBottomWgt::CBottomWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.startBtn, &QPushButton::clicked, this, [=]() {
		if (!m_bSongStatue)  // Ĭ�� Ҳ����ͣ
		{
			QString strSheet = "#startBtn{ \
				border-image:url(:/MusicPlayer/img/��ͣ.png); \
				} \
			#startBtn:hover{ \
				border-image:url(:/MusicPlayer/img/��ͣ_hover.png); \
			}";

			QString strSheet2 = " \
            #startBtn{ \
                border-image: url(:/MusicPlayer/img/��ͣ.png); \
             } \
            #startBtn:hover{ \
               border-image: url(:/MusicPlayer/img/��ͣ_hover.png); \
             }";
			ui.startBtn->setStyleSheet(strSheet2);
			m_bSongStatue  = true;
		}
		else 
		{
			QString strSheet = "#startBtn{ \
				border-image:url(:/MusicPlayer/img/����2.png); \
				} \
			#startBtn:hover{ \
				border-image:url(:/MusicPlayer/img/����2_hover.png); \
			}";
			ui.startBtn->setStyleSheet(strSheet);
			m_bSongStatue = false;
		}
	});
}

CBottomWgt::~CBottomWgt()
{}
