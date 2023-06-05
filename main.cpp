#include "mainwindow.h"
#include "sign.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sign w;
    w.show();
    return a.exec();
}
