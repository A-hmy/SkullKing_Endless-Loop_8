#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <QMainWindow>

namespace Ui {
class GameServer;
}

class GameServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameServer(QWidget *parent = nullptr);
    ~GameServer();

private slots:
    void on_Ok_clicked();

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
signals:
    void SendToServer(QString str);

private:
    Ui::GameServer *ui;
    QString NumberOfServer;
    QString NumberOfClient;
};

#endif // GAMESERVER_H
