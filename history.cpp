#include "history.h"
#include "ui_history.h"
#include "player.h"
#include "mainwindow.h"
#include "global.h"
#include "menu.h"
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
    //ui->label_8->setPixmap(player->get_GamePlayer().Photo);
    ui->label_8->setStyleSheet(QString("border-image: url(%1);").arg(player->get_GamePlayer().get_Photo()));
}

History::~History()
{
    delete ui;
}


void History::on_pushButton_clicked()
{
    this->close();
    Menu *m=new Menu;
    m->show();
}

