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
    void init();  // ��ʼ������һЩ��Ϣ
    void setSongPlayerPath(QString strMusicPath);  // ���ý�Ҫ���ŵ�����·��
public slots:
    void slots_switch_musicWgt(PublicData::MUSICWGTE e);  // �л�����

protected:
    virtual bool eventFilter(QObject *obj,QEvent* eve);  // ��д�¼�������
private:
    Ui::MusicPlayerClass ui;
    bool _bIsMaxWindow;  // Ĭ�ϴ��ڲ������
    QRect _beforeRec;  // ���֮ǰ�ĳߴ�
    CSongListSmallWgt* _songListWgt;
    bool _songStatus{false};  // ���ֲ��Ű�ť״̬ Ĭ��Ϊ��ͣ false 
    QMediaPlaylist* _pPlayList;
    QMediaPlayer* _pMusicPlayer;

};
