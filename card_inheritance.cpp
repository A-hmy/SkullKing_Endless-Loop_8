#include "card_inheritance.h"

Card_Inheritance::Card_Inheritance(){}

void Card_Inheritance::clear_Cards(){Cards.clear();}

void Card_Inheritance::set_Cards(Card _card){Cards.push_back(_card);}

void Card_Inheritance::delete_card(Card x)
{
   for(std::list<Card>::iterator it= Cards.begin();it!=Cards.end();it++){
       if(*it==x){
           Cards.erase(it);
       }
   }
}

std::list<Card> Card_Inheritance::get_cards()
{
   return Cards;
}
