#ifndef GAMESERVER_H
#define GAMESERVER_H
#include"card.h"
#include <QMainWindow>
#include"board.h"
#include "qtcpsocket.h"
#include<QStandardPaths>
#include<QMetaType>
#include<QAbstractSocket>
namespace Ui {
class GameServer;
}

class GameServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameServer(QWidget *parent = nullptr);
    ~GameServer();
    void PlayingGame();

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

    void connectt();

    void discardSocket();

    void readSocket();

    void displayError(QAbstractSocket::SocketError socketError);

    void on_OKip_clicked();

    void sendMessage(QString message);

    void Game();

private:
    Ui::GameServer *ui;
    QTcpSocket* MyClientSocket;
    QString Ipserver;
    Card ParrotClient1;
    Card ParrotClient2;
    QString NameOfOpponent;
    Card SelectedCard;
    //int NumberOfClient;
    //int NumberOfServer;
    //int NumberOfClient;//Receiving from client
    //Card PlayerCard_S;
    //Card PlayerCard_C;//Receiving from client
};

#endif // GAMESERVER_H
