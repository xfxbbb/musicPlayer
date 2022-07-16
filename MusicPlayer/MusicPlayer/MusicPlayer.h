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
    void setSongPlayerPath(QString strMusicPath);  // 设置将要播放的音乐路径
public slots:
    void slots_closeBtn_clicked();  // title栏关闭按钮的槽函数
    void slots_maxBtn_clicked();  // title栏 最大化/还原的按钮槽函数
    void slots_minBtn_clicked();  // title栏 最小化按钮的槽函数
    void slots_switch_musicWgt(PublicData::MUSICWGTE e);  // 切换界面
protected:
    virtual bool eventFilter(QObject *obj,QEvent* eve);  // 重写事件过滤器
private:
    Ui::MusicPlayerClass ui;
    bool _bIsMaxWindow;  // 默认窗口不是最大话
    QRect _beforeRec;  // 最大化之前的尺寸
    CSongListSmallWgt* _songListWgt;
    bool _songStatus{false};  // 音乐播放按钮状态 默认为暂停 false 


};
