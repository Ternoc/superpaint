#include "superpaintmw.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SuperPaintMW w;
    w.show();

    return a.exec();
}
