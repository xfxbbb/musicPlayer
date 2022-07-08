/********************************************************************************
** Form generated from reading UI file 'MainContentWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCONTENTWGT_H
#define UI_MAINCONTENTWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainContentWgtClass
{
public:

    void setupUi(QWidget *CMainContentWgtClass)
    {
        if (CMainContentWgtClass->objectName().isEmpty())
            CMainContentWgtClass->setObjectName(QString::fromUtf8("CMainContentWgtClass"));
        CMainContentWgtClass->resize(600, 400);

        retranslateUi(CMainContentWgtClass);

        QMetaObject::connectSlotsByName(CMainContentWgtClass);
    } // setupUi

    void retranslateUi(QWidget *CMainContentWgtClass)
    {
        CMainContentWgtClass->setWindowTitle(QCoreApplication::translate("CMainContentWgtClass", "CMainContentWgt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CMainContentWgtClass: public Ui_CMainContentWgtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCONTENTWGT_H
