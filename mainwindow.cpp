#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"function.h"
QVector <Player*> Players;
QVector<Card*>_cards;
Player* player;
QVector<Card*> CardsOfPlayerClient;
int s_or_c;
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

