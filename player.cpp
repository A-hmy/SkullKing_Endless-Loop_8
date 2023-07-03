#include "player.h"

Player::Player(QString _Name, QString _Username, QString _PhoneNumber, QString _Email, QString _Password)
{
Name=_Name;
Username=_Username;
PhoneNumber=_PhoneNumber;
Email=_Email;
Password=_Password;
Coin=1000;
GamePlayer.set_Score(0);
GamePlayer.set_ScoreOpponent(0);
GamePlayer.set_photo("");
GamePlayer.set_NameOpponent("");
}
Player::Player()
{

}
void Player::Edit(QString _Name,QString _Username,QString _PhoneNumber,QString _Email,QString _Password)
{
  if(_Name!="")
      Name=_Name;
  if(_Username!="")
      Username=_Username;
  if(_PhoneNumber!="")
      PhoneNumber=_PhoneNumber;
  if(_Email!="")
      Email=_Email;
  if(_Password!="")
      Password=_Password;
}
QString Player::get_Name(){return Name;}
QString Player::get_UserName(){return Username;}
QString Player::get_Password(){return Password;}
QString Player::get_Email(){return Email;}
QString Player::get_PhoneNumber(){return PhoneNumber;}
int Player::get_Coin(){return Coin;}
int Player::get_Win(){return Win;}
int Player::get_Lose(){return Lose;}
//QVector<GameOfPlayer>Player::get_GamePlayer(){return GamePlayer;}
//std::list<Card>Player::get_cards(){return Cards;}
/*void Player::set_Cards(Card _card)
{
    Cards.push_back(_card);
}*/
void Player::set_Password(QString _Password){
    Password=_Password;
}

void Player::set_Coin(int _Coin)
{
    Coin=_Coin;
}

void Player::set_Win()
{
    Win++;
}

void Player::set_Lose()
{
    Lose++;
}

void Player::set_GamePlayer(GameOfPlayer g)
{
  GamePlayer=g;
}
GameOfPlayer Player::get_GamePlayer(){
    return GamePlayer;
}

/*void Player::clear_Cards()
{
   Cards.clear();
}*/
