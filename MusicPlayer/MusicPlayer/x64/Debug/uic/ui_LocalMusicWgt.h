/********************************************************************************
** Form generated from reading UI file 'LocalMusicWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALMUSICWGT_H
#define UI_LOCALMUSICWGT_H

#include <MusicListView.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLocalMusicWgtClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QWidget *leftSongImg;
    QPushButton *addSongBtn;
    QSpacerItem *horizontalSpacer;
    CMusicListView *listView;

    void setupUi(QWidget *CLocalMusicWgtClass)
    {
        if (CLocalMusicWgtClass->objectName().isEmpty())
            CLocalMusicWgtClass->setObjectName(QString::fromUtf8("CLocalMusicWgtClass"));
        CLocalMusicWgtClass->resize(1075, 967);
        gridLayout = new QGridLayout(CLocalMusicWgtClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leftSongImg = new QWidget(CLocalMusicWgtClass);
        leftSongImg->setObjectName(QString::fromUtf8("leftSongImg"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftSongImg->sizePolicy().hasHeightForWidth());
        leftSongImg->setSizePolicy(sizePolicy);
        leftSongImg->setMinimumSize(QSize(300, 260));
        leftSongImg->setStyleSheet(QString::fromUtf8("#leftSongImg{	\n"
"	\n"
"	border-image: url(:/MusicPlayer/img/musicImg.png);\n"
"\n"
"}"));

        horizontalLayout->addWidget(leftSongImg);

        addSongBtn = new QPushButton(CLocalMusicWgtClass);
        addSongBtn->setObjectName(QString::fromUtf8("addSongBtn"));
        sizePolicy.setHeightForWidth(addSongBtn->sizePolicy().hasHeightForWidth());
        addSongBtn->setSizePolicy(sizePolicy);
        addSongBtn->setMinimumSize(QSize(30, 100));

        horizontalLayout->addWidget(addSongBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        listView = new CMusicListView(CLocalMusicWgtClass);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setMinimumSize(QSize(0, 800));
        listView->setStyleSheet(QString::fromUtf8("/*QListView\347\232\204\346\240\267\345\274\217\350\241\250*/\n"
"#listView{\n"
"    show-decoration-selected: 1;\n"
"}\n"
"  \n"
"/*iterm\347\232\204\351\253\230\345\272\246*/\n"
"#listView::item{\n"
"	height: 50px; /*\346\217\222\345\205\245iterm\351\253\230\345\272\246*/\n"
"	font-size:20pt;\n"
"}\n"
"#listView::item:alternate {\n"
"      background: #EEEEEE;		\n"
"}\n"
"#listView::item:selected {\n"
"      border: 1px solid #6a6ea9;	\n"
"}\n"
"/*\345\275\223\345\211\215index\347\232\204\351\242\234\350\211\262*/\n"
"#listView::item:selected:!active {\n"
"      background: #838383\n"
"}\n"
"/*\351\274\240\346\240\207\351\200\211\344\270\255\347\232\204\351\242\234\350\211\262*/\n"
"#listView::item:selected:active {\n"
"     background: #c3c3c3\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\232\204\351\242\234\350\211\262*/\n"
"#listView::item:hover {\n"
"     background: #c3c3c3\n"
"}\n"
""));

        verticalLayout->addWidget(listView);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(CLocalMusicWgtClass);

        QMetaObject::connectSlotsByName(CLocalMusicWgtClass);
    } // setupUi

    void retranslateUi(QWidget *CLocalMusicWgtClass)
    {
        CLocalMusicWgtClass->setWindowTitle(QCoreApplication::translate("CLocalMusicWgtClass", "CLocalMusicWgt", nullptr));
        addSongBtn->setText(QCoreApplication::translate("CLocalMusicWgtClass", "\346\267\273\345\212\240\346\255\214\346\233\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CLocalMusicWgtClass: public Ui_CLocalMusicWgtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALMUSICWGT_H
