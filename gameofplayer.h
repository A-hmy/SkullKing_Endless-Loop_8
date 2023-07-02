#ifndef GAMEOFPLAYER_H
#define GAMEOFPLAYER_H


#include <QPixmap>

class GameOfPlayer
{
public:
    QPixmap Photo;
    GameOfPlayer();
    QString get_NameOpponent();
    int get_Score();
    int get_ScoreOpponent();
private:

   QString NameOpponent;
   int Score;
   int ScoreOpponent;

};
#endif // GAMEOFPLAYER_H
