#include "function.h"
#include "mainwindow.h"
void StartGame() {
    for (int i = 1; i <= 8; i++) {
        Card* c = new Card("Parrot", i, i + 10);
        _cards.push_back(c);
    }
    for (int i = 1; i <= 8; i++) {
        Card* c = new Card("Map", i, i + 10);
        _cards.push_back(c);
    }
    for (int i = 1; i <= 8; i++) {
        Card* c = new Card("Treasure", i, i + 10);
        _cards.push_back(c);
    }
    for (int i = 1; i <= 8; i++) {
        Card* c = new Card("Flag", i, i + 20);
        _cards.push_back(c);
    }
    for (int i = 1; i <= 3; i++) {
        Card* c = new Card("Queen", i, i + 30);
        _cards.push_back(c);
    }
    for (int i = 1; i <= 3; i++) {
        Card* c = new Card("King", i, i + 40);
        _cards.push_back(c);
    }
    for (int i = 1; i <= 4; i++) {
        Card* c = new Card("Pirate", i, i + 50);
        _cards.push_back(c);
    }
}
void Dealing(int NumberOfGame)
{
    QVector<Card*> CardsOfPlayerClient;
    player->clear_Cards();
    CardsOfPlayerClient.clear();
    // reserved=false
    for (int i = 0; i < _cards.size(); i++)
         _cards[i]->set_Reserved(false);
    // deal_server
    for (int i = 0; i < NumberOfGame * 2;) {
         srand(time(NULL));
         int index = rand() % (_cards.size()+ 1);
         if (_cards[index]->get_Reserved() != 1) {
             player->set_Cards(*_cards[index]);
             i++;
             _cards[index]->set_Reserved(true);
            }
        }
        //deal_client
        for (int i = 0; i < NumberOfGame * 2;) {
            srand(time(NULL));
            int index = rand() % (_cards.size()+ 1);
            if (_cards[index]->get_Reserved() != 1) {
                CardsOfPlayerClient.push_back(_cards[index]);
                i++;
                _cards[index]->set_Reserved(true);
            }
        }
        //send CardsOfPlayerClient to client
}
