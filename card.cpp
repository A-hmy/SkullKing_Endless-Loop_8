#include "card.h"

Card::Card(){}
Card::Card(QString _Name, int _Number, int _Value)
{
    Name = _Name;
    Number = _Number;
    Reserved = false;
    Value = _Value;
}
QString Card::get_Name(){return Name;}
int Card::get_Number(){return Number;}
bool Card::get_Reserved(){return Reserved;}
void Card::set_Reserved(bool _Reserved){Reserved=_Reserved;}
int Card::get_PushButton(){return PushButton;}
void Card::set_PushButton(int _PushButton){PushButton=_PushButton;}
void Card::set_picture(QString _Picture)
{
   Picture.load(_Picture);
}
