// ���ݿ⴦����
#pragma once

#include <QObject>

class DbProcess  : public QObject
{
	Q_OBJECT
public:
	static DbProcess* GetInstance();
private:
	DbProcess(QObject* parent);
	DbProcess();
	~DbProcess();

};
