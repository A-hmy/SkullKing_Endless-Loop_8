#include "player.h"

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
