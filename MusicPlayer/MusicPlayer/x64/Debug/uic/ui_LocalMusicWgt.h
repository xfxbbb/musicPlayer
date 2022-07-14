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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLocalMusicWgtClass
{
public:
    QWidget *leftSongImg;
    QPushButton *addSongBtn;
    QListWidget *listWidget;

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
        addSongBtn = new QPushButton(CLocalMusicWgtClass);
        addSongBtn->setObjectName(QString::fromUtf8("addSongBtn"));
        addSongBtn->setGeometry(QRect(250, 90, 91, 71));
        listWidget = new QListWidget(CLocalMusicWgtClass);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 220, 1001, 661));

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
