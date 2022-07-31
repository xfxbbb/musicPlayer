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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLeftWgtClass
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *awidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QPushButton *allMusicBtn;
    QPushButton *favouriteMusicBtn;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CLeftWgtClass)
    {
        if (CLeftWgtClass->objectName().isEmpty())
            CLeftWgtClass->setObjectName(QString::fromUtf8("CLeftWgtClass"));
        CLeftWgtClass->resize(300, 527);
        CLeftWgtClass->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(CLeftWgtClass);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        awidget = new QWidget(CLeftWgtClass);
        awidget->setObjectName(QString::fromUtf8("awidget"));
        awidget->setStyleSheet(QString::fromUtf8("#awidget{\n"
"	background: #f8f8f8;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(awidget);
        verticalLayout_2->setSpacing(11);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 11, 11, 11);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 90, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(awidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("#label{\n"
"	color :#808080;\n"
"	font-size:16pt;\n"
"}"));
        label->setTextFormat(Qt::AutoText);

        verticalLayout->addWidget(label);

        verticalSpacer_3 = new QSpacerItem(2, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_3);

        allMusicBtn = new QPushButton(awidget);
        allMusicBtn->setObjectName(QString::fromUtf8("allMusicBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(allMusicBtn->sizePolicy().hasHeightForWidth());
        allMusicBtn->setSizePolicy(sizePolicy);
        allMusicBtn->setMinimumSize(QSize(0, 30));
        allMusicBtn->setStyleSheet(QString::fromUtf8("/*#allMusicBtn{\n"
"	font-size:20pt;\n"
"	color:#5f5f5f;\n"
"	border-style:none;\n"
"	background-color:#f8f8f8;\n"
"	text-align:left;\n"
"}\n"
"#allMusicBtn:hover{\n"
"	color:#ffffff;\n"
"	background-color:#5f5f5f;\n"
"}*/\n"
"\n"
"#allMusicBtn{\n"
"	\n"
"	border-image: url(:/MusicPlayer/img/allMusic.png);\n"
"}\n"
"\n"
"#allMusicBtn:hover{\n"
"	\n"
"	border-image: url(:/MusicPlayer/img/allMusic_hover.png);\n"
"}\n"
"#allMusicBtn:checked{\n"
"	border-image: url(:/MusicPlayer/img/allMusic_hover.png);\n"
"}"));
        allMusicBtn->setCheckable(true);
        allMusicBtn->setAutoRepeat(true);

        verticalLayout->addWidget(allMusicBtn);

        favouriteMusicBtn = new QPushButton(awidget);
        favouriteMusicBtn->setObjectName(QString::fromUtf8("favouriteMusicBtn"));
        sizePolicy.setHeightForWidth(favouriteMusicBtn->sizePolicy().hasHeightForWidth());
        favouriteMusicBtn->setSizePolicy(sizePolicy);
        favouriteMusicBtn->setMinimumSize(QSize(0, 30));
        favouriteMusicBtn->setStyleSheet(QString::fromUtf8("#favouriteMusicBtn{\n"
"\n"
"	border-image: url(:/MusicPlayer/img/localMusic.png);\n"
"}\n"
"#favouriteMusicBtn:hover{\n"
"	border-image: url(:/MusicPlayer/img/localMusic_hover.png);\n"
"}\n"
"#favouriteMusicBtn:checked{\n"
"	border-image: url(:/MusicPlayer/img/localMusic_hover.png);\n"
"}"));
        favouriteMusicBtn->setCheckable(true);
        favouriteMusicBtn->setAutoRepeat(true);

        verticalLayout->addWidget(favouriteMusicBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addWidget(awidget);


        retranslateUi(CLeftWgtClass);

        allMusicBtn->setDefault(false);


        QMetaObject::connectSlotsByName(CLeftWgtClass);
    } // setupUi

    void retranslateUi(QWidget *CLeftWgtClass)
    {
        CLeftWgtClass->setWindowTitle(QCoreApplication::translate("CLeftWgtClass", "CLeftWgt", nullptr));
        label->setText(QCoreApplication::translate("CLeftWgtClass", " \346\210\221\347\232\204\351\237\263\344\271\220", nullptr));
        allMusicBtn->setText(QString());
        favouriteMusicBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CLeftWgtClass: public Ui_CLeftWgtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTWGT_H
