/********************************************************************************
** Form generated from reading UI file 'LeftWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTWGT_H
#define UI_LEFTWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLeftWgtClass
{
public:
    QPushButton *allMusicBtn;
    QPushButton *favouriteMusicBtn;

    void setupUi(QWidget *CLeftWgtClass)
    {
        if (CLeftWgtClass->objectName().isEmpty())
            CLeftWgtClass->setObjectName(QString::fromUtf8("CLeftWgtClass"));
        CLeftWgtClass->resize(339, 1069);
        CLeftWgtClass->setStyleSheet(QString::fromUtf8("#CLeftWgtClass{\n"
"\n"
"}"));
        allMusicBtn = new QPushButton(CLeftWgtClass);
        allMusicBtn->setObjectName(QString::fromUtf8("allMusicBtn"));
        allMusicBtn->setGeometry(QRect(50, 190, 201, 41));
        allMusicBtn->setStyleSheet(QString::fromUtf8("#allMusicBtn{\n"
"	font-size:20pt;\n"
"	color:#5f5f5f;\n"
"	border:1px solid #5f5f5f;\n"
"	background-color:#ffffff;\n"
"}\n"
"#allMusicBtn:hover{\n"
"	color:#ffffff;\n"
"	background-color:#5f5f5f;\n"
"}"));
        favouriteMusicBtn = new QPushButton(CLeftWgtClass);
        favouriteMusicBtn->setObjectName(QString::fromUtf8("favouriteMusicBtn"));
        favouriteMusicBtn->setGeometry(QRect(50, 250, 201, 41));
        favouriteMusicBtn->setStyleSheet(QString::fromUtf8("#favouriteMusicBtn{\n"
"	font-size:20pt;\n"
"	color:#5f5f5f;\n"
"	border:1px solid #5f5f5f;\n"
"	background-color:#ffffff;\n"
"}\n"
"#favouriteMusicBtn:hover{\n"
"	color:#ffffff;\n"
"	background-color:#5f5f5f;\n"
"}"));

        retranslateUi(CLeftWgtClass);

        QMetaObject::connectSlotsByName(CLeftWgtClass);
    } // setupUi

    void retranslateUi(QWidget *CLeftWgtClass)
    {
        CLeftWgtClass->setWindowTitle(QCoreApplication::translate("CLeftWgtClass", "CLeftWgt", nullptr));
        allMusicBtn->setText(QCoreApplication::translate("CLeftWgtClass", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        favouriteMusicBtn->setText(QCoreApplication::translate("CLeftWgtClass", "\346\224\266\350\227\217\346\255\214\346\233\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CLeftWgtClass: public Ui_CLeftWgtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTWGT_H
