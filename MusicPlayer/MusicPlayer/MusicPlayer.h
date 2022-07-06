#pragma once

#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QApplication>
#include <QDesktopWidget> 
#include <QRect>
#include <QDebug>
#include <QMouseEvent>
#include "ui_MusicPlayer.h"

class MusicPlayer : public QMainWindow
{
    Q_OBJECT

public:
    MusicPlayer(QWidget *parent = nullptr);
    ~MusicPlayer();
    void init();  // 初始化界面一些信息
public slots:
    void slots_closeBtn_clicked();  // title栏关闭按钮的槽函数
    void slots_maxBtn_clicked();  // title栏 最大化/还原的按钮槽函数
    void slots_minBtn_clicked();  // title栏 最小化按钮的槽函数
protected:
    virtual bool eventFilter(QObject *obj,QEvent* eve);  // 重写事件过滤器
private:
    Ui::MusicPlayerClass ui;
    bool m_bIsMaxWindow;  // 默认窗口不是最大话
    QRect m_beforeRec;  // 最大化之前的尺寸
};
