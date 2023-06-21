#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include <QMainWindow>

namespace Ui {
class GameClient;
}

class GameClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameClient(QWidget *parent = nullptr);
    ~GameClient();

private slots:
    void on_card_1_clicked();

    void on_card_2_clicked();

    void on_card_3_clicked();

    void on_card_4_clicked();

    void on_card_5_clicked();

    void on_card_6_clicked();

    void on_card_7_clicked();

    void on_card_8_clicked();

    void on_card_9_clicked();

    void on_card_10_clicked();

    void on_card_11_clicked();

    void on_card_12_clicked();

    void on_card_13_clicked();

    void on_card_14_clicked();

private:
    Ui::GameClient *ui;
};

#endif // GAMECLIENT_H
