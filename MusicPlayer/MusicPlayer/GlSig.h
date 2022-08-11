// 全局信号类
#pragma once
#include <qobject.h>
#include <mutex>
class GlobalSig :
    public QObject
{
    Q_OBJECT
public:
    static GlobalSig* GetInstance();
Q_SIGNALS:
    void signal_test();
    void signal_update_musiclist(QStringList strNamePath);  // 更新音乐播放列表
    void signal_update_volume(int iValue);  // 更新音量
private:
    GlobalSig(){}
    ~GlobalSig(){}
};

