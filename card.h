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
    void set_picture(QString);
    QString get_Picture();
    int get_value();
    void set_Name(QString _name);
private:
    QString Name;
    int Number;
    bool Reserved;
    int Value;
    int PushButton;
    QString Picture;
};
#endif // CARD_H
