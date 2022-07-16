/********************************************************************************
** Form generated from reading UI file 'SongListSmallWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGLISTSMALLWGT_H
#define UI_SONGLISTSMALLWGT_H

#include <MusicListView.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSongListSmallWgtClass
{
public:
    QGridLayout *gridLayout;
    QWidget *mainWgt;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    CMusicListView *listView;
    QPushButton *backBtn;

    void setupUi(QWidget *CSongListSmallWgtClass)
    {
        if (CSongListSmallWgtClass->objectName().isEmpty())
            CSongListSmallWgtClass->setObjectName(QString::fromUtf8("CSongListSmallWgtClass"));
        CSongListSmallWgtClass->resize(559, 580);
        gridLayout = new QGridLayout(CSongListSmallWgtClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mainWgt = new QWidget(CSongListSmallWgtClass);
        mainWgt->setObjectName(QString::fromUtf8("mainWgt"));
        mainWgt->setStyleSheet(QString::fromUtf8("#mainWgt{\n"
"	background-color:#f0f0f0;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(mainWgt);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(mainWgt);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("#label{\n"
"	color:black;\n"
"}"));

        verticalLayout->addWidget(label);

        listView = new CMusicListView(mainWgt);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);

        backBtn = new QPushButton(mainWgt);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setStyleSheet(QString::fromUtf8("#backBtn{\n"
"	border:1px solid #808080;\n"
"}\n"
"\n"
"#backBtn:hover{\n"
"	border:1px solid balck;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MusicPlayer/img/\351\237\263\344\271\220\345\210\227\350\241\250_hover.png"), QSize(), QIcon::Normal, QIcon::Off);
        backBtn->setIcon(icon);

        verticalLayout->addWidget(backBtn);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addWidget(mainWgt, 0, 0, 1, 1);


        retranslateUi(CSongListSmallWgtClass);

        QMetaObject::connectSlotsByName(CSongListSmallWgtClass);
    } // setupUi

    void retranslateUi(QWidget *CSongListSmallWgtClass)
    {
        CSongListSmallWgtClass->setWindowTitle(QCoreApplication::translate("CSongListSmallWgtClass", "CSongListSmallWgt", nullptr));
        label->setText(QCoreApplication::translate("CSongListSmallWgtClass", "\346\211\200\346\234\211\351\237\263\344\271\220:", nullptr));
        backBtn->setText(QCoreApplication::translate("CSongListSmallWgtClass", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSongListSmallWgtClass: public Ui_CSongListSmallWgtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGLISTSMALLWGT_H
