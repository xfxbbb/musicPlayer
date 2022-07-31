#include "DbProcess.h"

DbProcess* DbProcess::GetInstance()
{
	static DbProcess _instance;
	return &_instance;
}

DbProcess::DbProcess(QObject *parent)
	: QObject(parent)
{}
DbProcess::DbProcess()
{
}

DbProcess::~DbProcess()
{}
