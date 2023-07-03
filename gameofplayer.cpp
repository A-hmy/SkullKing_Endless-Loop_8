#include "gameofplayer.h"

GameOfPlayer::GameOfPlayer(){}

GameOfPlayer::GameOfPlayer(QString photo, QString nameOpponent, int score, int scoreOpponent)
{
    Photo=photo;
    NameOpponent=nameOpponent;
    Score=score;
    ScoreOpponent=scoreOpponent;
}
QString GameOfPlayer::get_NameOpponent(){return NameOpponent;}
int GameOfPlayer::get_Score(){return Score;}
int GameOfPlayer::get_ScoreOpponent(){return ScoreOpponent;}
QString GameOfPlayer::get_Photo()
{
  return Photo;
}
