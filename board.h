#ifndef BOARD_H
#define BOARD_H
#include"card.h"

class Board
{
public:
    Board();
    Card get_player1();
    Card get_player2();
    int get_NumberOfset_C();
    void set_player1(Card);
    void set_player2(Card);
private:
    Card player1;//server
    Card player2;//client
    int NumberOfset_C;//client
};

#endif // BOARD_H
