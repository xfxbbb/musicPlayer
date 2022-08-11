#pragma once

#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QApplication>
#include <QDesktopWidget> 
#include <QRect>
#include <QDebug>
#include <QMouseEvent>
#include "ui_MusicPlayer.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QCoroHandle.h>
#include "Utils.hpp"

class MusicPlayer : public QMainWindow
{
    Q_OBJECT

public:
    MusicPlayer(QWidget *parent = nullptr);
    ~MusicPlayer();
    void init();  // 初始化界面一些信息
    void setSongPlayerPath(QString strMusicPath);  // 设置将要播放的音乐路径
    void pauseOrPlayMusic();  // 暂停/播放音乐
public slots:
    void slots_switch_musicWgt(PublicData::MUSICWGTE e);  // 切换界面
    void slots_handel_musicPlayerList(QStringList strMusicPath); // 处理音乐播放列表槽函数
    void slots_update_volume(int iValue);  // 更新音量
protected:
    virtual bool eventFilter(QObject *obj,QEvent* eve);  // 重写事件过滤器
private:
    Ui::MusicPlayerClass ui;
    bool _bIsMaxWindow;  // 默认窗口不是最大话
    QRect _beforeRec;  // 最大化之前的尺寸
    CSongListSmallWgt* _songListWgt;
    bool _songStatus{false};  // 音乐播放按钮状态 默认为暂停 false 
    QMediaPlaylist* _pPlayList;
    QMediaPlayer* _pMusicPlayer;

};
