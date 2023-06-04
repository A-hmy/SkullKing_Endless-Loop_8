#ifndef PLAYER_H
#define PLAYER_H

#include<QString>
class Player
{
public:
    Player();
    void Edit(QString ,QString ,QString,QString,QString);


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
     //std::list<Card>Cards;

};

#endif // PLAYER_H
