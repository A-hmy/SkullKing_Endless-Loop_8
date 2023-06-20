#include "board.h"

Board::Board()
{

}

Card Board::get_player1()
{
   return player1;
}

Card Board::get_player2()
{
    return player2;
}

int Board::get_NumberOfset_C()
{
  return NumberOfset_C;
}

void Board::set_player1(Card _player1)
{
   player1=_player1;
}

void Board::set_player2(Card _player2)
{
   player2=_player2;
}
