#ifndef PLAYER_H
#define PLAYER_H

#include "card_inheritance.h"
#include "gameofplayer.h"
#include "card.h"
class Player:public Card_Inheritance
{
public:
    Player(QString,QString,QString,QString,QString);
    Player();
    void Edit(QString ,QString ,QString,QString,QString);
    QString get_Name();
    QString get_UserName();
    QString get_Password();
    QString get_Email();
    QString get_PhoneNumber();
    int get_Coin();
    int get_Win();
    int get_Lose();
    //QVector<GameOfPlayer>get_GamePlayer();
    //std::list<Card>get_cards();
    GameOfPlayer get_GamePlayer();
    void set_GamePlayer(QVector<GameOfPlayer>);
    //void set_Cards(Card);
    void set_Password(QString);
    //void clear_Cards();

private:
     QString Name;
     QString Username;
     QString Password;
     QString Email;
     QString PhoneNumber;
     int Coin;
     int Win;
     int Lose;
     //QVector<GameOfPlayer> GamePlayer;
     GameOfPlayer GamePlayer;
     //std::list<Card>Cards;

};

#endif // PLAYER_H
