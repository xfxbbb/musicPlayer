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
    void init();  // ��ʼ������һЩ��Ϣ
public slots:
    void slots_closeBtn_clicked();  // title���رհ�ť�Ĳۺ���
    void slots_maxBtn_clicked();  // title�� ���/��ԭ�İ�ť�ۺ���
    void slots_minBtn_clicked();  // title�� ��С����ť�Ĳۺ���
protected:
    virtual bool eventFilter(QObject *obj,QEvent* eve);  // ��д�¼�������
private:
    Ui::MusicPlayerClass ui;
    bool m_bIsMaxWindow;  // Ĭ�ϴ��ڲ������
    QRect m_beforeRec;  // ���֮ǰ�ĳߴ�
};
