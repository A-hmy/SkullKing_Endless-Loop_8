#ifndef GAMEOFPLAYER_H
#define GAMEOFPLAYER_H


#include <QPixmap>

class GameOfPlayer
{
public:
    GameOfPlayer();
    QString get_NameOpponent();
    int get_Score();
    int get_ScoreOpponent();
private:
   QPixmap Photo;
   QString NameOpponent;
   int Score;
   int ScoreOpponent;

};

#endif // GAMEOFPLAYER_H
