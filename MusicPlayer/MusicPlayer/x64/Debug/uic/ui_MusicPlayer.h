/********************************************************************************
** Form generated from reading UI file 'MusicPlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICPLAYER_H
#define UI_MUSICPLAYER_H

#include <BottomWgt.h>
#include <LeftWgt.h>
#include <MainContentWgt.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
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
    CMainContentWgt *contentWgt;
    CBottomWgt *bottomWgt;

    void setupUi(QMainWindow *MusicPlayerClass)
    {
        if (MusicPlayerClass->objectName().isEmpty())
            MusicPlayerClass->setObjectName(QString::fromUtf8("MusicPlayerClass"));
        MusicPlayerClass->resize(1024, 785);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MusicPlayerClass->sizePolicy().hasHeightForWidth());
        MusicPlayerClass->setSizePolicy(sizePolicy);
        MusicPlayerClass->setMinimumSize(QSize(1024, 768));
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
        leftWgt->setMaximumSize(QSize(300, 16777215));
        leftWgt->setStyleSheet(QString::fromUtf8("#leftWgt{\n"
"	background:#f8f8f8;\n"
"}"));

        horizontalLayout_3->addWidget(leftWgt);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        contentWgt = new CMainContentWgt(centralWidget);
        contentWgt->setObjectName(QString::fromUtf8("contentWgt"));
        contentWgt->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(contentWgt);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        bottomWgt = new CBottomWgt(centralWidget);
        bottomWgt->setObjectName(QString::fromUtf8("bottomWgt"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(bottomWgt->sizePolicy().hasHeightForWidth());
        bottomWgt->setSizePolicy(sizePolicy2);
        bottomWgt->setMinimumSize(QSize(0, 85));
        bottomWgt->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(bottomWgt);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MusicPlayerClass->setCentralWidget(centralWidget);

        retranslateUi(MusicPlayerClass);

        QMetaObject::connectSlotsByName(MusicPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *MusicPlayerClass)
    {
        MusicPlayerClass->setWindowTitle(QCoreApplication::translate("MusicPlayerClass", "MusicPlayer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicPlayerClass: public Ui_MusicPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYER_H
