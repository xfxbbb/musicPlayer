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
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
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
    QWidget *contentWgt;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *musicShowBtn;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    DownProcessBar *processWidget;
    QWidget *rightWgt;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *songListBtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *voiceBtn;
    DownProcessBar *widget;

    void setupUi(QWidget *CBottomWgtClass)
    {
        if (CBottomWgtClass->objectName().isEmpty())
            CBottomWgtClass->setObjectName(QString::fromUtf8("CBottomWgtClass"));
        CBottomWgtClass->resize(1671, 104);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CBottomWgtClass->sizePolicy().hasHeightForWidth());
        CBottomWgtClass->setSizePolicy(sizePolicy);
        CBottomWgtClass->setMinimumSize(QSize(0, 85));
        CBottomWgtClass->setStyleSheet(QString::fromUtf8("#CBottomWgtClass{\n"
"	border:1px solid black;\n"
"}"));
        gridLayout = new QGridLayout(CBottomWgtClass);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        leftWgt = new QWidget(CBottomWgtClass);
        leftWgt->setObjectName(QString::fromUtf8("leftWgt"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leftWgt->sizePolicy().hasHeightForWidth());
        leftWgt->setSizePolicy(sizePolicy1);
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
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        inSongBtn = new QPushButton(leftWgt);
        inSongBtn->setObjectName(QString::fromUtf8("inSongBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(inSongBtn->sizePolicy().hasHeightForWidth());
        inSongBtn->setSizePolicy(sizePolicy2);
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
        sizePolicy2.setHeightForWidth(startBtn->sizePolicy().hasHeightForWidth());
        startBtn->setSizePolicy(sizePolicy2);
        startBtn->setMaximumSize(QSize(16777215, 30));
        startBtn->setStyleSheet(QString::fromUtf8("#startBtn{\n"
"	border-image: url(:/MusicPlayer/img/\346\222\255\346\224\2762.png);\n"
"}\n"
"#startBtn:hover{\n"
"	border-image: url(:/MusicPlayer/img/\346\222\255\346\224\2762_hover.png);\n"
"}"));

        horizontalLayout->addWidget(startBtn);

        horizontalSpacer_3 = new QSpacerItem(37, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        nextSongBtn = new QPushButton(leftWgt);
        nextSongBtn->setObjectName(QString::fromUtf8("nextSongBtn"));
        sizePolicy2.setHeightForWidth(nextSongBtn->sizePolicy().hasHeightForWidth());
        nextSongBtn->setSizePolicy(sizePolicy2);
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


        horizontalLayout_5->addWidget(leftWgt);

        contentWgt = new QWidget(CBottomWgtClass);
        contentWgt->setObjectName(QString::fromUtf8("contentWgt"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(contentWgt->sizePolicy().hasHeightForWidth());
        contentWgt->setSizePolicy(sizePolicy3);
        contentWgt->setMaximumSize(QSize(16777215, 85));
        contentWgt->setStyleSheet(QString::fromUtf8("#contentWgt{\n"
"	background:#ffffff;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(contentWgt);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        musicShowBtn = new QPushButton(contentWgt);
        musicShowBtn->setObjectName(QString::fromUtf8("musicShowBtn"));
        sizePolicy2.setHeightForWidth(musicShowBtn->sizePolicy().hasHeightForWidth());
        musicShowBtn->setSizePolicy(sizePolicy2);
        musicShowBtn->setMaximumSize(QSize(90, 90));

        horizontalLayout_2->addWidget(musicShowBtn);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(contentWgt);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 20));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label);

        processWidget = new DownProcessBar(contentWgt);
        processWidget->setObjectName(QString::fromUtf8("processWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(processWidget->sizePolicy().hasHeightForWidth());
        processWidget->setSizePolicy(sizePolicy4);
        processWidget->setMaximumSize(QSize(400, 60));
        processWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(processWidget);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_5->addWidget(contentWgt);

        rightWgt = new QWidget(CBottomWgtClass);
        rightWgt->setObjectName(QString::fromUtf8("rightWgt"));
        sizePolicy4.setHeightForWidth(rightWgt->sizePolicy().hasHeightForWidth());
        rightWgt->setSizePolicy(sizePolicy4);
        rightWgt->setMaximumSize(QSize(500, 85));
        rightWgt->setStyleSheet(QString::fromUtf8("#rightWgt{\n"
"	background:#ffffff;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(rightWgt);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        songListBtn = new QPushButton(rightWgt);
        songListBtn->setObjectName(QString::fromUtf8("songListBtn"));
        sizePolicy2.setHeightForWidth(songListBtn->sizePolicy().hasHeightForWidth());
        songListBtn->setSizePolicy(sizePolicy2);
        songListBtn->setMaximumSize(QSize(30, 35));
        songListBtn->setStyleSheet(QString::fromUtf8("#songListBtn{\n"
"	border-image: url(:/MusicPlayer/img/\351\237\263\344\271\220\345\210\227\350\241\250.png);\n"
"}\n"
"#songListBtn:hover{\n"
"	border-image: url(:/MusicPlayer/img/\351\237\263\344\271\220\345\210\227\350\241\250_hover.png);\n"
"}"));

        horizontalLayout_3->addWidget(songListBtn);

        horizontalSpacer_5 = new QSpacerItem(30, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        voiceBtn = new QPushButton(rightWgt);
        voiceBtn->setObjectName(QString::fromUtf8("voiceBtn"));
        sizePolicy2.setHeightForWidth(voiceBtn->sizePolicy().hasHeightForWidth());
        voiceBtn->setSizePolicy(sizePolicy2);
        voiceBtn->setMaximumSize(QSize(35, 40));
        voiceBtn->setStyleSheet(QString::fromUtf8("#voiceBtn{\n"
"	border-image: url(:/MusicPlayer/img/\345\243\260\351\237\263.png);\n"
"}\n"
"#voiceBtn:pressed{\n"
"	border-image: url(:/MusicPlayer/img/\345\243\260\351\237\263\351\235\231\351\237\263.png);\n"
"}"));

        horizontalLayout_3->addWidget(voiceBtn);

        widget = new DownProcessBar(rightWgt);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMaximumSize(QSize(300, 100));

        horizontalLayout_3->addWidget(widget);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_5->addWidget(rightWgt);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        retranslateUi(CBottomWgtClass);

        QMetaObject::connectSlotsByName(CBottomWgtClass);
    } // setupUi

    void retranslateUi(QWidget *CBottomWgtClass)
    {
        CBottomWgtClass->setWindowTitle(QCoreApplication::translate("CBottomWgtClass", "CBottomWgt", nullptr));
        inSongBtn->setText(QString());
        startBtn->setText(QString());
        nextSongBtn->setText(QString());
        musicShowBtn->setText(QCoreApplication::translate("CBottomWgtClass", "\346\255\214\346\233\262\345\233\276\347\211\207", nullptr));
        label->setText(QCoreApplication::translate("CBottomWgtClass", "\346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
        songListBtn->setText(QString());
        voiceBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CBottomWgtClass: public Ui_CBottomWgtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTTOMWGT_H
