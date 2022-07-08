/********************************************************************************
** Form generated from reading UI file 'BottomWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOTTOMWGT_H
#define UI_BOTTOMWGT_H

#include "DownProcessBar.h"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CBottomWgtClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QWidget *leftWgt;
    QWidget *contentWgt;
    DownProcessBar *processWidget;
    QWidget *rightWgt;

    void setupUi(QWidget *CBottomWgtClass)
    {
        if (CBottomWgtClass->objectName().isEmpty())
            CBottomWgtClass->setObjectName(QString::fromUtf8("CBottomWgtClass"));
        CBottomWgtClass->resize(1710, 121);
        CBottomWgtClass->setStyleSheet(QString::fromUtf8("#CBottomWgtClass{\n"
"	border:1px solid #808080;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(CBottomWgtClass);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leftWgt = new QWidget(CBottomWgtClass);
        leftWgt->setObjectName(QString::fromUtf8("leftWgt"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftWgt->sizePolicy().hasHeightForWidth());
        leftWgt->setSizePolicy(sizePolicy);
        leftWgt->setMaximumSize(QSize(300, 16777215));
        leftWgt->setStyleSheet(QString::fromUtf8("#leftWgt{\n"
"	background:#ffffff;\n"
"}"));

        horizontalLayout->addWidget(leftWgt);

        contentWgt = new QWidget(CBottomWgtClass);
        contentWgt->setObjectName(QString::fromUtf8("contentWgt"));
        contentWgt->setStyleSheet(QString::fromUtf8("#contentWgt{\n"
"	/*background:#f2f2f2;*/\n"
"}"));
        processWidget = new DownProcessBar(contentWgt);
        processWidget->setObjectName(QString::fromUtf8("processWidget"));
        processWidget->setGeometry(QRect(260, 20, 471, 80));
        processWidget->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(contentWgt);

        rightWgt = new QWidget(CBottomWgtClass);
        rightWgt->setObjectName(QString::fromUtf8("rightWgt"));
        sizePolicy.setHeightForWidth(rightWgt->sizePolicy().hasHeightForWidth());
        rightWgt->setSizePolicy(sizePolicy);
        rightWgt->setMaximumSize(QSize(260, 16777215));
        rightWgt->setStyleSheet(QString::fromUtf8("#rightWgt{\n"
"	background:#ffffff;\n"
"}"));

        horizontalLayout->addWidget(rightWgt);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(CBottomWgtClass);

        QMetaObject::connectSlotsByName(CBottomWgtClass);
    } // setupUi

    void retranslateUi(QWidget *CBottomWgtClass)
    {
        CBottomWgtClass->setWindowTitle(QCoreApplication::translate("CBottomWgtClass", "CBottomWgt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CBottomWgtClass: public Ui_CBottomWgtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTTOMWGT_H
