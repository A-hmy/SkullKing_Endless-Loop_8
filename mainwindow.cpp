#include "mainwindow.h"
#include "ui_mainwindow.h"
QVector <Player*> Players;
Player* player;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

