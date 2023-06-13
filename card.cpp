#include "card.h"

Card::Card()
{

}

Card::Card(QString, int, int)
{

}
QString Card::get_Name(){return Name;}
int Card::get_Number(){return Number;}
bool Card::get_Reserved(){return Reserved;}
void Card::set_Reserved(bool _Reserved)
{
  Reserved=_Reserved;
}
