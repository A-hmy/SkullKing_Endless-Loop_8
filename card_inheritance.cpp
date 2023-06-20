#include "card_inheritance.h"

Card_Inheritance::Card_Inheritance(){}

void Card_Inheritance::clear_Cards(){Cards.clear();}

void Card_Inheritance::set_Cards(Card _card){Cards.push_back(_card);}

std::list<Card> Card_Inheritance::get_cards()
{
   return Cards;
}
