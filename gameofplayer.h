#ifndef GAMEOFPLAYER_H
#define GAMEOFPLAYER_H


#include <QPixmap>

class GameOfPlayer
{
public:
    //QPixmap Photo;
    GameOfPlayer();
    GameOfPlayer(QString photo,QString nameOpponent,int score,int scoreOpponent );
    QString get_NameOpponent();
    int get_Score();
    int get_ScoreOpponent();
    QString get_Photo();
private:
   QString Photo;
   QString NameOpponent;
   int Score;
   int ScoreOpponent;

};
#endif // GAMEOFPLAYER_H
