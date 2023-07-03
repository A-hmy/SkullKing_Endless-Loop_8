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

void GameOfPlayer::set_Score(int _s)
{
    Score=_s;
}

void GameOfPlayer::set_ScoreOpponent(int _s)
{
    ScoreOpponent=_s;
}

void GameOfPlayer::set_NameOpponent(QString n)
{
    NameOpponent=n;
}

void GameOfPlayer::set_photo(QString _P)
{
    Photo=_P;
}

