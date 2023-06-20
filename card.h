#ifndef CARD_H
#define CARD_H

#include<QString>
#include<QPixmap>
class Card
{
public:
    Card();
    Card(QString, int, int);
    QString get_Name();
    int get_Number();
    bool get_Reserved();
    void set_Reserved(bool);
    int get_PushButton();
    void set_PushButton(int);
private:
    QString Name;
    int Number;
    bool Reserved;
    QPixmap Picture;
    int Value;
    int PushButton;
};
#endif // CARD_H
