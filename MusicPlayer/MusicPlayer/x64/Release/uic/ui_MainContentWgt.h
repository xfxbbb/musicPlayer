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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainContentWgtClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *awidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;

    void setupUi(QWidget *CMainContentWgtClass)
    {
        if (CMainContentWgtClass->objectName().isEmpty())
            CMainContentWgtClass->setObjectName(QString::fromUtf8("CMainContentWgtClass"));
        CMainContentWgtClass->resize(1108, 1016);
        verticalLayout = new QVBoxLayout(CMainContentWgtClass);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        awidget = new QWidget(CMainContentWgtClass);
        awidget->setObjectName(QString::fromUtf8("awidget"));
        awidget->setStyleSheet(QString::fromUtf8("#awidget\n"
"{\n"
"	border:1px dotted black\n"
"\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(awidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(awidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        verticalLayout_2->addWidget(tabWidget);


        verticalLayout->addWidget(awidget);


        retranslateUi(CMainContentWgtClass);

        tabWidget->setCurrentIndex(-1);


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
