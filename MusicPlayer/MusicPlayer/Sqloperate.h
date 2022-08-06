// 数据库操作类
#pragma once
#include <QObject>

class Sqloperate  : public QObject
{
	Q_OBJECT

public:
	Sqloperate(QObject *parent);
	~Sqloperate();
};
