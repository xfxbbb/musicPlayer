/********************************************************************************
** Form generated from reading UI file 'LocalMusicWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALMUSICWGT_H
#define UI_LOCALMUSICWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLocalMusicWgtClass
{
public:
    QWidget *leftSongImg;
    QListView *listView;
    QPushButton *rdSongBtn;
    QPushButton *addSongBtn;

    void setupUi(QWidget *CLocalMusicWgtClass)
    {
        if (CLocalMusicWgtClass->objectName().isEmpty())
            CLocalMusicWgtClass->setObjectName(QString::fromUtf8("CLocalMusicWgtClass"));
        CLocalMusicWgtClass->resize(1043, 908);
        leftSongImg = new QWidget(CLocalMusicWgtClass);
        leftSongImg->setObjectName(QString::fromUtf8("leftSongImg"));
        leftSongImg->setGeometry(QRect(20, 40, 171, 161));
        leftSongImg->setStyleSheet(QString::fromUtf8("#leftSongImg{	\n"
"	\n"
"	border-image: url(:/MusicPlayer/img/musicImg.png);\n"
"\n"
"}"));
        listView = new QListView(CLocalMusicWgtClass);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(30, 290, 941, 541));
        rdSongBtn = new QPushButton(CLocalMusicWgtClass);
        rdSongBtn->setObjectName(QString::fromUtf8("rdSongBtn"));
        rdSongBtn->setGeometry(QRect(270, 60, 201, 51));
        addSongBtn = new QPushButton(CLocalMusicWgtClass);
        addSongBtn->setObjectName(QString::fromUtf8("addSongBtn"));
        addSongBtn->setGeometry(QRect(490, 60, 201, 51));

        retranslateUi(CLocalMusicWgtClass);

        QMetaObject::connectSlotsByName(CLocalMusicWgtClass);
    } // setupUi

    void retranslateUi(QWidget *CLocalMusicWgtClass)
    {
        CLocalMusicWgtClass->setWindowTitle(QCoreApplication::translate("CLocalMusicWgtClass", "CLocalMusicWgt", nullptr));
        rdSongBtn->setText(QCoreApplication::translate("CLocalMusicWgtClass", "\351\232\217\346\234\272\346\222\255\346\224\276", nullptr));
        addSongBtn->setText(QCoreApplication::translate("CLocalMusicWgtClass", "\346\267\273\345\212\240\346\255\214\346\233\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CLocalMusicWgtClass: public Ui_CLocalMusicWgtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALMUSICWGT_H
