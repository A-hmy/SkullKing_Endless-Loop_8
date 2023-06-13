#include "function.h"
#include "mainwindow.h"

void Dealing(int NumberOfGame)
{
    QVector<Card*> CardsOfPlayerClient;
    player->get_cards().clear();//check
    CardsOfPlayerClient.clear();
    // reserved=false
    for (int i = 0; i < _cards.size(); i++)
         _cards[i]->set_Reserved(false);
    // deal_server
    for (int i = 0; i < NumberOfGame * 2;) {
         srand(time(NULL));
         int index = rand() % (_cards.size() - 0 + 1) + 0;
         if (_cards[index]->get_Reserved() != 1) {
             player->set_Cards(*_cards[index]);
             i++;
             _cards[index]->set_Reserved(true);
            }
        }
        //deal_client
        for (int i = 0; i < NumberOfGame * 2;) {
            srand(time(NULL));
            int index = rand() % (_cards.size() - 0 + 1) + 0;
            if (_cards[index]->get_Reserved() != 1) {
                CardsOfPlayerClient.push_back(_cards[index]);
                i++;
                _cards[index]->set_Reserved(true);
            }
        }
        //send CardsOfPlayerClient to client
}
