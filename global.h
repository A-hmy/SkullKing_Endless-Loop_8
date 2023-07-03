#ifndef GLOBAL_H
#define GLOBAL_H
#include "player.h"

extern int s_or_c;
extern QVector<Card*> CardsOfPlayerClient;//card client
extern QVector <Player*> Players;// All user
extern QVector<Card*>_cards;//All cards
extern Player* player;
extern int numberOfclient;
extern QVector<Card*>Parrot;
class Global
{
public:
    Global();
};

#endif // GLOBAL_H
