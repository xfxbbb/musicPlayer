#include "MusicPlayer.h"
#include <QtWidgets/QApplication>
#include <QCoroHandle.h>
#include "Utils.hpp"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    coro::QCoroHandle::init();

    MusicPlayer w;
    w.show();
    return a.exec();
}
