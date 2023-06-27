#include "history.h"
#include "ui_history.h"
#include "player.h"
#include "mainwindow.h"
History::History(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui->Opponent->setText(player->get_GamePlayer().get_NameOpponent());
    QString s = QString::number(player->get_GamePlayer().get_ScoreOpponent());
    ui->OpponentScore->setText(s);
    QString f = QString::number(player->get_GamePlayer().get_Score());
    ui->YourScore->setText(f);
}

History::~History()
{
    delete ui;
}

void History::on_Set1_clicked()
{

}


void History::on_Set2_clicked()
{

}


void History::on_Set3_clicked()
{

}


void History::on_Set4_clicked()
{

}



void History::on_Set5_clicked()
{

}


void History::on_Set6_clicked()
{

}


void History::on_Set7_clicked()
{

}


void History::on_Set8_clicked()
{

}


void History::on_Set9_clicked()
{

}


void History::on_Set10_clicked()
{

}


void History::on_Set11_clicked()
{

}


void History::on_Set12_clicked()
{

}


void History::on_Set13_clicked()
{

}


void History::on_Set14_clicked()
{

}

