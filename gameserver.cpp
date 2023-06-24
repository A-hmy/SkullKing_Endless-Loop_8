#include "gameserver.h"
#include "ui_gameserver.h"
#include "function.h"
GameServer::GameServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameServer)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
}

GameServer::~GameServer()
{
    delete ui;
}

void GameServer::PlayingGame()
{
   for(int NumberOfRound=0;NumberOfRound!=7;NumberOfRound++){
       //dealing
       Dealing(NumberOfRound);

   }

}

void GameServer::on_Ok_clicked()
{
    if(ui->NumberOfPredict->text().isEmpty()){
      ui->NumberOfPredict->setPlaceholderText("❗❗❗❗");
        }
    else{
       NumberOfServer=ui->NumberOfPredict->text().toInt();
       // daryaft tedad bord client(NumberOfClient=ui.......)
       ui->NumberOfPredict->setVisible(false);
       ui->Ok->setVisible(false);
       ui->lablePredict->setVisible(false);
        }


}


void GameServer::on_card_1_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_card_2_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}


void GameServer::on_card_3_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}


void GameServer::on_card_4_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}


void GameServer::on_card_5_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}


void GameServer::on_card_6_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}


void GameServer::on_card_7_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}


void GameServer::on_card_8_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}


void GameServer::on_card_9_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}


void GameServer::on_card_10_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}


void GameServer::on_card_11_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}


void GameServer::on_card_12_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}


void GameServer::on_card_13_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}


void GameServer::on_card_14_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::Set(Board _board)
{
    PlayerCard_C=_board.get_player2();
    //PlayerCard_S=_board.get_player1();
    NumberOfClient=_board.get_NumberOfset_C();//This variable should not be changed
}






