#include "function.h"
#include "mainwindow.h"
#include<QFile>
#include"global.h"
void StartGame() {
    for (int i = 1; i <= 8; i++) {
        Card* c = new Card("Parrot", i, i + 10);
        QString p=":/new/prefix1/Picture/parrot"+QString::number(i)+".png";
        c->set_picture(p);
        _cards.push_back(c);
        Parrot.push_back(c);
    }
    for (int i = 1; i <= 8; i++) {
        QString p=":/new/prefix1/Picture/map"+QString::number(i)+".png";
        Card* c = new Card("Map", i, i + 10);
        c->set_picture(p);
        _cards.push_back(c);
    }
    for (int i = 1; i <= 8; i++) {
        Card* c = new Card("Treasure", i, i + 10);
        QString p=":/new/prefix1/Picture/treasure"+QString::number(i)+".png";
        c->set_picture(p);
        _cards.push_back(c);
    }
    for (int i = 1; i <= 8; i++) {
        Card* c = new Card("Flag", i, i + 20);
        QString p=":/new/prefix1/Picture/PirateFlag"+QString::number(i)+".png";
        c->set_picture(p);
        _cards.push_back(c);
    }
    for (int i = 1; i <= 3; i++) {
        Card* c = new Card("Queen", i, i + 30);
        c->set_picture(":/new/prefix1/Picture/Queen.png");
        _cards.push_back(c);
    }
    for (int i = 1; i <= 3; i++) {
        Card* c = new Card("King", i, i + 40);
        c->set_picture(":/new/prefix1/Picture/king.png");
        _cards.push_back(c);
    }
    for (int i = 1; i <= 4; i++) {
        Card* c = new Card("Pirate", i, i + 50);
        c->set_picture(":/new/prefix1/Picture/Pirate.png");
        _cards.push_back(c);
    }
}
void Dealing(int NumberOfRound)
{
    player->clear_Cards();
    CardsOfPlayerClient.clear();
    // reserved=false
    for (int i = 0; i < _cards.size(); i++)
         _cards[i]->set_Reserved(false);
    // deal_server
    for (int i = 0; i < NumberOfRound * 2;) {
         srand(time(NULL));
         int index = rand() % (_cards.size());
         if (_cards[index]->get_Reserved() != 1) {
             player->set_Cards(*_cards[index]);
             i++;
             _cards[index]->set_Reserved(true);
            }
        }
        //deal_client
        for (int i = 0; i < NumberOfRound * 2;) {
            srand(time(NULL));
            int index = rand() % (_cards.size());
            if (_cards[index]->get_Reserved() != 1) {
                CardsOfPlayerClient.push_back(_cards[index]);
                i++;
                _cards[index]->set_Reserved(true);
            }
        }
        //send CardsOfPlayerClient to client
}

void File_WriteOnly(QString FileName, Player player)
{
  QFile file(FileName);
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
      QTextStream out(&file);
      out<<player.get_Name()<<"&"<<player.get_UserName()<<"&"<<player.get_Password()<<"&"<<player.get_Email()<<"&"<<player.get_PhoneNumber()<<"&"<<player.get_Coin()<<"&"<<player.get_Lose()<<"&"<<player.get_Win()<<"&";
      //for(auto it=player.get_GamePlayer().begin();it!=player.get_GamePlayer().begin();++it){
       //   out<<it->get_NameOpponent()<<"||"<<it->get_ScoreOpponent()<<"||"<<it->get_Score();
      //}
      out<<"\n";
  }
  file.close();
}

void File_Read(QString FileName)
{
    QFile file(FileName);
     if (file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
          QTextStream in(&file);
          while (!in.atEnd()){
              QString line = in.readLine();
              QStringList fields = line.split("&");
              QString name = fields[0];
              QString username=fields[1];
              QString password=fields[2];
              QString email=fields[3];
              QString phonenumber=fields[4];
              QString coin=fields[5];
              QString lose=fields[6];
              QString win=fields[7];
              //QStringList Game=fields[8].split("||");
             // QString NameOpponent=Game[0];
             // QString ScoreOpponent=Game[1];
             // QString Score=Game[2];
              Player * p=new Player(name, username, phonenumber, email, password);
              Players.push_back(p);
          }
     }
     file.close();
}



