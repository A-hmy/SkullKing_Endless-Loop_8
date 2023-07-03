#include "mainwindow.h"
#include "sign.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow s;
    s.show();
    return a.exec();
}
