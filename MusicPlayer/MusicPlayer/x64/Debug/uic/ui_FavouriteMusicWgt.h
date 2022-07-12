/********************************************************************************
** Form generated from reading UI file 'FavouriteMusicWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAVOURITEMUSICWGT_H
#define UI_FAVOURITEMUSICWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CFavouriteMusicWgtClass
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *CFavouriteMusicWgtClass)
    {
        if (CFavouriteMusicWgtClass->objectName().isEmpty())
            CFavouriteMusicWgtClass->setObjectName(QString::fromUtf8("CFavouriteMusicWgtClass"));
        CFavouriteMusicWgtClass->resize(733, 672);
        pushButton = new QPushButton(CFavouriteMusicWgtClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 160, 381, 271));

        retranslateUi(CFavouriteMusicWgtClass);

        QMetaObject::connectSlotsByName(CFavouriteMusicWgtClass);
    } // setupUi

    void retranslateUi(QWidget *CFavouriteMusicWgtClass)
    {
        CFavouriteMusicWgtClass->setWindowTitle(QCoreApplication::translate("CFavouriteMusicWgtClass", "CFavouriteMusicWgt", nullptr));
        pushButton->setText(QCoreApplication::translate("CFavouriteMusicWgtClass", "\346\224\266\350\227\217\351\237\263\344\271\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CFavouriteMusicWgtClass: public Ui_CFavouriteMusicWgtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAVOURITEMUSICWGT_H
