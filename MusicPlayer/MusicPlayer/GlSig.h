// ȫ���ź���
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
    void signal_update_musiclist(QStringList strNamePath);  // �������ֲ����б�
    void signal_update_volume(int iValue);  // ��������
private:
    GlobalSig(){}
    ~GlobalSig(){}
};

