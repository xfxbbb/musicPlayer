/********************************************************************************
** Form generated from reading UI file 'MusicPlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICPLAYER_H
#define UI_MUSICPLAYER_H

#include "BottomWgt.h"
#include "LeftWgt.h"
#include "MainContentWgt.h"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicPlayerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    CLeftWgt *leftWgt;
    QVBoxLayout *verticalLayout_2;
    QWidget *titleWgt;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *minBtn;
    QPushButton *maxBtn;
    QPushButton *closeBtn;
    CMainContentWgt *contentWgt;
    CBottomWgt *bottomWgt;

    void setupUi(QMainWindow *MusicPlayerClass)
    {
        if (MusicPlayerClass->objectName().isEmpty())
            MusicPlayerClass->setObjectName(QString::fromUtf8("MusicPlayerClass"));
        MusicPlayerClass->resize(1725, 1315);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MusicPlayerClass->sizePolicy().hasHeightForWidth());
        MusicPlayerClass->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MusicPlayerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        leftWgt = new CLeftWgt(centralWidget);
        leftWgt->setObjectName(QString::fromUtf8("leftWgt"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leftWgt->sizePolicy().hasHeightForWidth());
        leftWgt->setSizePolicy(sizePolicy1);
        leftWgt->setMinimumSize(QSize(300, 0));
        leftWgt->setMaximumSize(QSize(16777215, 16777215));
        leftWgt->setStyleSheet(QString::fromUtf8("#leftWgt{\n"
"	background-color:#858585;\n"
"	border-right:1px solid red;\n"
"}"));

        horizontalLayout_3->addWidget(leftWgt);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        titleWgt = new QWidget(centralWidget);
        titleWgt->setObjectName(QString::fromUtf8("titleWgt"));
        sizePolicy.setHeightForWidth(titleWgt->sizePolicy().hasHeightForWidth());
        titleWgt->setSizePolicy(sizePolicy);
        titleWgt->setMaximumSize(QSize(16777215, 59));
        titleWgt->setStyleSheet(QString::fromUtf8("#titleWgt{\n"
"	border-color: rgb(229, 243, 255);\n"
"}"));
        verticalLayout = new QVBoxLayout(titleWgt);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        minBtn = new QPushButton(titleWgt);
        minBtn->setObjectName(QString::fromUtf8("minBtn"));
        minBtn->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(minBtn->sizePolicy().hasHeightForWidth());
        minBtn->setSizePolicy(sizePolicy2);
        minBtn->setMaximumSize(QSize(50, 35));
        minBtn->setStyleSheet(QString::fromUtf8("#minBtn{\n"
"	\n"
"	border-image: url(:/MusicPlayer/img/min.png);\n"
"}\n"
"#minBtn:hover{\n"
"	border-image: url(:/MusicPlayer/img/min_hover.png);\n"
"}"));

        horizontalLayout->addWidget(minBtn);

        maxBtn = new QPushButton(titleWgt);
        maxBtn->setObjectName(QString::fromUtf8("maxBtn"));
        sizePolicy2.setHeightForWidth(maxBtn->sizePolicy().hasHeightForWidth());
        maxBtn->setSizePolicy(sizePolicy2);
        maxBtn->setMaximumSize(QSize(50, 35));
        maxBtn->setStyleSheet(QString::fromUtf8("#maxBtn{\n"
"	\n"
"	border-image: url(:/MusicPlayer/img/max.png);\n"
"}\n"
"#maxBtn:hover{\n"
"	border-image: url(:/MusicPlayer/img/max_hover.png);\n"
"}"));

        horizontalLayout->addWidget(maxBtn);

        closeBtn = new QPushButton(titleWgt);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        sizePolicy2.setHeightForWidth(closeBtn->sizePolicy().hasHeightForWidth());
        closeBtn->setSizePolicy(sizePolicy2);
        closeBtn->setMaximumSize(QSize(50, 35));
        closeBtn->setStyleSheet(QString::fromUtf8("#closeBtn{\n"
"	border-image: url(:/MusicPlayer/img/close.png);\n"
"}\n"
"#closeBtn:hover{\n"
"	border-image: url(:/MusicPlayer/img/close_hover.png);\n"
"}"));

        horizontalLayout->addWidget(closeBtn);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(titleWgt);

        contentWgt = new CMainContentWgt(centralWidget);
        contentWgt->setObjectName(QString::fromUtf8("contentWgt"));
        contentWgt->setStyleSheet(QString::fromUtf8("#contentWgt{\n"
"	background-color:#f8f8f8;\n"
"}"));

        verticalLayout_2->addWidget(contentWgt);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        bottomWgt = new CBottomWgt(centralWidget);
        bottomWgt->setObjectName(QString::fromUtf8("bottomWgt"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(bottomWgt->sizePolicy().hasHeightForWidth());
        bottomWgt->setSizePolicy(sizePolicy3);
        bottomWgt->setMinimumSize(QSize(0, 85));
        bottomWgt->setStyleSheet(QString::fromUtf8("#bottomWgt{\n"
"	background-color:#dadada;\n"
"}"));

        verticalLayout_3->addWidget(bottomWgt);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MusicPlayerClass->setCentralWidget(centralWidget);

        retranslateUi(MusicPlayerClass);

        QMetaObject::connectSlotsByName(MusicPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *MusicPlayerClass)
    {
        MusicPlayerClass->setWindowTitle(QCoreApplication::translate("MusicPlayerClass", "MusicPlayer", nullptr));
        minBtn->setText(QString());
        maxBtn->setText(QString());
        closeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MusicPlayerClass: public Ui_MusicPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYER_H
