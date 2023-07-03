#ifndef CARD_INHERITANCE_H
#define CARD_INHERITANCE_H
#include "card.h"

class Card_Inheritance
{
public:
    Card_Inheritance();
    void clear_Cards();
    void set_Cards(Card);
    void delete_card(Card x);
    std::list<Card>get_cards();
protected:
    std::list<Card>Cards;
};

#endif // CARD_INHERITANCE_H
