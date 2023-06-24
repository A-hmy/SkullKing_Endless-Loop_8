#include "gameclient.h"
#include "ui_gameclient.h"

GameClient::GameClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameClient)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
}

GameClient::~GameClient()
{
    delete ui;
}

void GameClient::on_card_1_clicked()
{

}


void GameClient::on_card_2_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}


void GameClient::on_card_3_clicked()
{

}


void GameClient::on_card_4_clicked()
{

}


void GameClient::on_card_5_clicked()
{

}


void GameClient::on_card_6_clicked()
{

}


void GameClient::on_card_7_clicked()
{

}


void GameClient::on_card_8_clicked()
{

}


void GameClient::on_card_9_clicked()
{

}


void GameClient::on_card_10_clicked()
{

}


void GameClient::on_card_11_clicked()
{

}


void GameClient::on_card_12_clicked()
{

}


void GameClient::on_card_13_clicked()
{

}


void GameClient::on_card_14_clicked()
{

}

