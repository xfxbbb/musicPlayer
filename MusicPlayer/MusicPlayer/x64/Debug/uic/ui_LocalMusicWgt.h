/********************************************************************************
** Form generated from reading UI file 'LocalMusicWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALMUSICWGT_H
#define UI_LOCALMUSICWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLocalMusicWgtClass
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *leftSongImg;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *localLabel;
    QPushButton *addSongBtn;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QWidget *searchWgt;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *searchBtn;
    QLineEdit *searchEdit;
    QTableView *musicView;

    void setupUi(QWidget *CLocalMusicWgtClass)
    {
        if (CLocalMusicWgtClass->objectName().isEmpty())
            CLocalMusicWgtClass->setObjectName(QString::fromUtf8("CLocalMusicWgtClass"));
        CLocalMusicWgtClass->resize(1373, 1055);
        CLocalMusicWgtClass->setStyleSheet(QString::fromUtf8("#CLocalMusicWgtClass{\n"
"	background-color:#ffffff;\n"
"\n"
"}"));
        gridLayout_2 = new QGridLayout(CLocalMusicWgtClass);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        leftSongImg = new QWidget(CLocalMusicWgtClass);
        leftSongImg->setObjectName(QString::fromUtf8("leftSongImg"));
        leftSongImg->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftSongImg->sizePolicy().hasHeightForWidth());
        leftSongImg->setSizePolicy(sizePolicy);
        leftSongImg->setMinimumSize(QSize(187, 187));
        leftSongImg->setStyleSheet(QString::fromUtf8("#leftSongImg{	\n"
"	\n"
"	border-image: url(:/MusicPlayer/img/musicImg.png);\n"
"\n"
"}"));

        horizontalLayout_3->addWidget(leftSongImg);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        localLabel = new QLabel(CLocalMusicWgtClass);
        localLabel->setObjectName(QString::fromUtf8("localLabel"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        localLabel->setFont(font);
        localLabel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(localLabel);

        addSongBtn = new QPushButton(CLocalMusicWgtClass);
        addSongBtn->setObjectName(QString::fromUtf8("addSongBtn"));
        sizePolicy.setHeightForWidth(addSongBtn->sizePolicy().hasHeightForWidth());
        addSongBtn->setSizePolicy(sizePolicy);
        addSongBtn->setMinimumSize(QSize(144, 35));
        addSongBtn->setStyleSheet(QString::fromUtf8("#addSongBtn{\n"
"	border-image: url(:/MusicPlayer/img/addFile.png);\n"
"}\n"
"#addSongBtn:hover{\n"
"	border-image: url(:/MusicPlayer/img/addFile_hover.png);\n"
"}"));

        verticalLayout->addWidget(addSongBtn);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(888, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        searchWgt = new QWidget(CLocalMusicWgtClass);
        searchWgt->setObjectName(QString::fromUtf8("searchWgt"));
        sizePolicy.setHeightForWidth(searchWgt->sizePolicy().hasHeightForWidth());
        searchWgt->setSizePolicy(sizePolicy);
        searchWgt->setMinimumSize(QSize(230, 31));
        searchWgt->setStyleSheet(QString::fromUtf8("#searchWgt{\n"
"	border-radius:20%;\n"
"	background-color:#f5f5f5;\n"
"}\n"
"#searchWgt:hover{\n"
"	background-color:#ffffff;\n"
"}"));
        gridLayout = new QGridLayout(searchWgt);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        searchBtn = new QPushButton(searchWgt);
        searchBtn->setObjectName(QString::fromUtf8("searchBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(searchBtn->sizePolicy().hasHeightForWidth());
        searchBtn->setSizePolicy(sizePolicy1);
        searchBtn->setMinimumSize(QSize(38, 40));
        searchBtn->setStyleSheet(QString::fromUtf8("#searchBtn{\n"
"	border-image: url(:/MusicPlayer/img/search.png);\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(searchBtn);

        searchEdit = new QLineEdit(searchWgt);
        searchEdit->setObjectName(QString::fromUtf8("searchEdit"));
        sizePolicy1.setHeightForWidth(searchEdit->sizePolicy().hasHeightForWidth());
        searchEdit->setSizePolicy(sizePolicy1);
        searchEdit->setMinimumSize(QSize(160, 40));
        searchEdit->setMaximumSize(QSize(160, 16777215));
        searchEdit->setStyleSheet(QString::fromUtf8("#searchEdit{\n"
"	border:none;\n"
"	background-color:#f5f5f5;\n"
"\n"
"}\n"
"\n"
"#searchEdit:hover{\n"
"	border:none;\n"
"	background-color:#ffffff;\n"
"\n"
"}"));

        horizontalLayout->addWidget(searchEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(searchWgt);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        musicView = new QTableView(CLocalMusicWgtClass);
        musicView->setObjectName(QString::fromUtf8("musicView"));
        musicView->setMinimumSize(QSize(0, 0));
        musicView->setStyleSheet(QString::fromUtf8("#musicView{\n"
"	border:none;\n"
"\n"
"    gridline-color: black;                              /*\350\241\250\346\240\274\345\206\205\346\241\206\351\242\234\350\211\262*/\n"
"              /*\350\241\250\346\240\274\345\206\205\350\203\214\346\231\257\350\211\262*/\n"
"    alternate-background-color: #f5f5f5;\n"
"    selection-color: white;                             /*\351\200\211\344\270\255\345\214\272\345\237\237\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
"    selection-background-color: rgb(77, 77, 77);        /*\351\200\211\344\270\255\345\214\272\345\237\237\347\232\204\350\203\214\346\231\257\350\211\262*/\n"
"	font-size:14pt;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        musicView->setFrameShape(QFrame::NoFrame);
        musicView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_3->addWidget(musicView);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(CLocalMusicWgtClass);

        QMetaObject::connectSlotsByName(CLocalMusicWgtClass);
    } // setupUi

    void retranslateUi(QWidget *CLocalMusicWgtClass)
    {
        CLocalMusicWgtClass->setWindowTitle(QCoreApplication::translate("CLocalMusicWgtClass", "CLocalMusicWgt", nullptr));
        localLabel->setText(QCoreApplication::translate("CLocalMusicWgtClass", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        addSongBtn->setText(QString());
        searchBtn->setText(QString());
        searchEdit->setPlaceholderText(QCoreApplication::translate("CLocalMusicWgtClass", "\346\220\234\347\264\242\346\255\214\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CLocalMusicWgtClass: public Ui_CLocalMusicWgtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALMUSICWGT_H
