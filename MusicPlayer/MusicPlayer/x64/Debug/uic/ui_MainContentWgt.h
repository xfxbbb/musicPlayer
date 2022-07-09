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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainContentWgtClass
{
public:
    QGridLayout *gridLayout;
    QWidget *awidget;

    void setupUi(QWidget *CMainContentWgtClass)
    {
        if (CMainContentWgtClass->objectName().isEmpty())
            CMainContentWgtClass->setObjectName(QString::fromUtf8("CMainContentWgtClass"));
        CMainContentWgtClass->resize(1108, 1016);
        gridLayout = new QGridLayout(CMainContentWgtClass);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        awidget = new QWidget(CMainContentWgtClass);
        awidget->setObjectName(QString::fromUtf8("awidget"));
        awidget->setStyleSheet(QString::fromUtf8("#awidget\n"
"{\n"
"	border:1px dotted black\n"
"\n"
"}"));

        gridLayout->addWidget(awidget, 0, 0, 1, 1);


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
