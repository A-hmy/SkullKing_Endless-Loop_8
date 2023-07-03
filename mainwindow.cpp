#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"function.h"
#include <QTimer>
#include <QProgressBar>
#include "sign.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->progressBar->setStyleSheet("QProgressBar {"

                                   "border-radius: 5px;"
                                   "background-color: white;"
                                   "}"
                                   "QProgressBar::chunk {"
                                   "background-color: black;"
                                   "}");

    ui->progressBar->setRange(0, 100);
    QTimer *timer = new QTimer(this);
    timer->setInterval(2000);
    timer->start();
    connect(timer, &QTimer::timeout, [=]() {
        static int count = 0;
        const int totalSteps = 3;
        const int valueStep = 100 / totalSteps;

        if (count < totalSteps) {
            ui->progressBar->setValue(ui->progressBar->value() + valueStep);
            count++;
        } else {
            Sign *s=new Sign;
            s->show();
            this->close();


            timer->stop();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

