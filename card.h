#ifndef CARD_H
#define CARD_H

#include<QString>
#include<QPixmap>
class Card
{
public:
    Card();
    QString get_Name();
    int get_Number();
    bool get_Reserved();
private:
    QString Name;
    int Number;
    bool Reserved;
    QPixmap Picture;
};

#endif // CARD_H
