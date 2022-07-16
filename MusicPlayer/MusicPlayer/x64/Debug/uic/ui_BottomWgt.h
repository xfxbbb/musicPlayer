/********************************************************************************
** Form generated from reading UI file 'BottomWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOTTOMWGT_H
#define UI_BOTTOMWGT_H

#include <DownProcessBar.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CBottomWgtClass
{
public:
    QVBoxLayout *verticalLayout_5;
    QWidget *bgWgt;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QWidget *leftWgt;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *inSongBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *startBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *nextSongBtn;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *musicShowBtn;
    QWidget *contentWgt;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *musicNameLabel;
    DownProcessBar *processWidget;
    QWidget *rightWgt;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *songListBtn;
    QPushButton *voiceBtn;

    void setupUi(QWidget *CBottomWgtClass)
    {
        if (CBottomWgtClass->objectName().isEmpty())
            CBottomWgtClass->setObjectName(QString::fromUtf8("CBottomWgtClass"));
        CBottomWgtClass->resize(1723, 85);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CBottomWgtClass->sizePolicy().hasHeightForWidth());
        CBottomWgtClass->setSizePolicy(sizePolicy);
        CBottomWgtClass->setMinimumSize(QSize(0, 85));
        CBottomWgtClass->setStyleSheet(QString::fromUtf8("#CBottomWgtClass{\n"
"	border:1px solid black;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(CBottomWgtClass);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        bgWgt = new QWidget(CBottomWgtClass);
        bgWgt->setObjectName(QString::fromUtf8("bgWgt"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bgWgt->sizePolicy().hasHeightForWidth());
        bgWgt->setSizePolicy(sizePolicy1);
        bgWgt->setMaximumSize(QSize(16777215, 85));
        verticalLayout_6 = new QVBoxLayout(bgWgt);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        leftWgt = new QWidget(bgWgt);
        leftWgt->setObjectName(QString::fromUtf8("leftWgt"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leftWgt->sizePolicy().hasHeightForWidth());
        leftWgt->setSizePolicy(sizePolicy2);
        leftWgt->setMaximumSize(QSize(420, 85));
        leftWgt->setStyleSheet(QString::fromUtf8("#leftWgt{\n"
"	background:#ffffff;\n"
"}"));
        verticalLayout = new QVBoxLayout(leftWgt);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        inSongBtn = new QPushButton(leftWgt);
        inSongBtn->setObjectName(QString::fromUtf8("inSongBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(inSongBtn->sizePolicy().hasHeightForWidth());
        inSongBtn->setSizePolicy(sizePolicy3);
        inSongBtn->setMaximumSize(QSize(16777215, 30));
        inSongBtn->setStyleSheet(QString::fromUtf8("#inSongBtn{\n"
"	border-image: url(:/MusicPlayer/img/\344\270\212\344\270\200\346\233\262.png);\n"
"}\n"
"#inSongBtn:hover{\n"
"	border-image: url(:/MusicPlayer/img/\344\270\212\344\270\200\346\233\262_hover.png);\n"
"}"));

        horizontalLayout->addWidget(inSongBtn);

        horizontalSpacer_2 = new QSpacerItem(37, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        startBtn = new QPushButton(leftWgt);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));
        sizePolicy3.setHeightForWidth(startBtn->sizePolicy().hasHeightForWidth());
        startBtn->setSizePolicy(sizePolicy3);
        startBtn->setMaximumSize(QSize(16777215, 30));
        startBtn->setStyleSheet(QString::fromUtf8("#startBtn{\n"
"	border-image: url(:/MusicPlayer/img/\346\222\255\346\224\2762.png);\n"
"}\n"
"#startBtn:hover{\n"
"	border-image: url(:/MusicPlayer/img/\346\222\255\346\224\2762_hover.png);\n"
"}\n"
"#startBtn:checked{\n"
"	border-image: url(:/MusicPlayer/img/\346\232\202\345\201\234.png);\n"
"}"));
        startBtn->setCheckable(true);
        startBtn->setAutoRepeat(true);

        horizontalLayout->addWidget(startBtn);

        horizontalSpacer_3 = new QSpacerItem(37, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        nextSongBtn = new QPushButton(leftWgt);
        nextSongBtn->setObjectName(QString::fromUtf8("nextSongBtn"));
        sizePolicy3.setHeightForWidth(nextSongBtn->sizePolicy().hasHeightForWidth());
        nextSongBtn->setSizePolicy(sizePolicy3);
        nextSongBtn->setMaximumSize(QSize(16777215, 30));
        nextSongBtn->setStyleSheet(QString::fromUtf8("#nextSongBtn{\n"
"	border-image: url(:/MusicPlayer/img/\344\270\213\344\270\200\346\233\262.png);\n"
"}\n"
"#nextSongBtn:hover{\n"
"	border-image: url(:/MusicPlayer/img/\344\270\213\344\270\200\346\233\262_hover.png);\n"
"}"));

        horizontalLayout->addWidget(nextSongBtn);

        horizontalSpacer_4 = new QSpacerItem(140, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addWidget(leftWgt);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        musicShowBtn = new QPushButton(bgWgt);
        musicShowBtn->setObjectName(QString::fromUtf8("musicShowBtn"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(musicShowBtn->sizePolicy().hasHeightForWidth());
        musicShowBtn->setSizePolicy(sizePolicy4);
        musicShowBtn->setMinimumSize(QSize(80, 0));
        musicShowBtn->setMaximumSize(QSize(80, 90));
        musicShowBtn->setStyleSheet(QString::fromUtf8("#musicShowBtn{\n"
"	\n"
"	border-image: url(:/MusicPlayer/img/musicImg.png);\n"
"}"));

        horizontalLayout_2->addWidget(musicShowBtn);

        contentWgt = new QWidget(bgWgt);
        contentWgt->setObjectName(QString::fromUtf8("contentWgt"));
        sizePolicy1.setHeightForWidth(contentWgt->sizePolicy().hasHeightForWidth());
        contentWgt->setSizePolicy(sizePolicy1);
        contentWgt->setMaximumSize(QSize(10000, 85));
        contentWgt->setStyleSheet(QString::fromUtf8("#contentWgt{\n"
"	background:#ffffff;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(contentWgt);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        musicNameLabel = new QLabel(contentWgt);
        musicNameLabel->setObjectName(QString::fromUtf8("musicNameLabel"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(musicNameLabel->sizePolicy().hasHeightForWidth());
        musicNameLabel->setSizePolicy(sizePolicy5);
        musicNameLabel->setMaximumSize(QSize(16777215, 20));
        musicNameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(musicNameLabel);

        processWidget = new DownProcessBar(contentWgt);
        processWidget->setObjectName(QString::fromUtf8("processWidget"));
        sizePolicy4.setHeightForWidth(processWidget->sizePolicy().hasHeightForWidth());
        processWidget->setSizePolicy(sizePolicy4);
        processWidget->setMaximumSize(QSize(100000, 60));
        processWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(processWidget);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_2->addWidget(contentWgt);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        rightWgt = new QWidget(bgWgt);
        rightWgt->setObjectName(QString::fromUtf8("rightWgt"));
        sizePolicy1.setHeightForWidth(rightWgt->sizePolicy().hasHeightForWidth());
        rightWgt->setSizePolicy(sizePolicy1);
        rightWgt->setMaximumSize(QSize(200, 85));
        rightWgt->setStyleSheet(QString::fromUtf8("#rightWgt{\n"
"	background:#ffffff;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(rightWgt);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        songListBtn = new QPushButton(rightWgt);
        songListBtn->setObjectName(QString::fromUtf8("songListBtn"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(songListBtn->sizePolicy().hasHeightForWidth());
        songListBtn->setSizePolicy(sizePolicy6);
        songListBtn->setMaximumSize(QSize(30, 35));
        songListBtn->setStyleSheet(QString::fromUtf8("#songListBtn{\n"
"	border-image: url(:/MusicPlayer/img/\351\237\263\344\271\220\345\210\227\350\241\250.png);\n"
"}\n"
"#songListBtn:hover{\n"
"	border-image: url(:/MusicPlayer/img/\351\237\263\344\271\220\345\210\227\350\241\250_hover.png);\n"
"}\n"
"#songListBtn::checked{\n"
"border-image: url(:/MusicPlayer/img/\351\237\263\344\271\220\345\210\227\350\241\250_hover.png);\n"
"}"));
        songListBtn->setCheckable(true);
        songListBtn->setAutoExclusive(true);

        horizontalLayout_3->addWidget(songListBtn);

        voiceBtn = new QPushButton(rightWgt);
        voiceBtn->setObjectName(QString::fromUtf8("voiceBtn"));
        sizePolicy6.setHeightForWidth(voiceBtn->sizePolicy().hasHeightForWidth());
        voiceBtn->setSizePolicy(sizePolicy6);
        voiceBtn->setMaximumSize(QSize(35, 40));
        voiceBtn->setStyleSheet(QString::fromUtf8("#voiceBtn{\n"
"	border-image: url(:/MusicPlayer/img/\345\243\260\351\237\263.png);\n"
"}\n"
"#voiceBtn:pressed{\n"
"	border-image: url(:/MusicPlayer/img/\345\243\260\351\237\263\351\235\231\351\237\263.png);\n"
"}"));

        horizontalLayout_3->addWidget(voiceBtn);


        verticalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_4->addWidget(rightWgt);


        verticalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_5->addWidget(bgWgt);


        retranslateUi(CBottomWgtClass);

        QMetaObject::connectSlotsByName(CBottomWgtClass);
    } // setupUi

    void retranslateUi(QWidget *CBottomWgtClass)
    {
        CBottomWgtClass->setWindowTitle(QCoreApplication::translate("CBottomWgtClass", "CBottomWgt", nullptr));
        inSongBtn->setText(QString());
        startBtn->setText(QString());
        nextSongBtn->setText(QString());
        musicShowBtn->setText(QString());
        musicNameLabel->setText(QCoreApplication::translate("CBottomWgtClass", "\346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
        songListBtn->setText(QString());
        voiceBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CBottomWgtClass: public Ui_CBottomWgtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTTOMWGT_H
