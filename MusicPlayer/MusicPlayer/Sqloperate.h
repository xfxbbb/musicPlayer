// ���ݿ������
#pragma once
#include <QObject>

class Sqloperate  : public QObject
{
	Q_OBJECT

public:
	Sqloperate(QObject *parent);
	~Sqloperate();
};
