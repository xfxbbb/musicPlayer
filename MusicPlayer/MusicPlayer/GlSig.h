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
private:
    GlobalSig(){}
    ~GlobalSig(){}
};

