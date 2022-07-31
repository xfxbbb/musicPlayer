/********************************************************************************
** Form generated from reading UI file 'MainContentWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCONTENTWGT_H
#define UI_MAINCONTENTWGT_H

#include <FavouriteMusicWgt.h>
#include <LocalMusicWgt.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainContentWgtClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *awidget;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    CLocalMusicWgt *page;
    CFavouriteMusicWgt *page_2;

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
        stackedWidget = new QStackedWidget(awidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new CLocalMusicWgt();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new CFavouriteMusicWgt();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout_2->addWidget(stackedWidget);


        verticalLayout->addWidget(awidget);


        retranslateUi(CMainContentWgtClass);

        stackedWidget->setCurrentIndex(0);


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
