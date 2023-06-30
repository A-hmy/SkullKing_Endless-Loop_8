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
    void DisplayCards();
    void DisplayingACard_you(QString card);
    void DisplayingACard_opponent(QString card);
private slots:
    void onButtonClicked();

    void connectt();

    void discardSocket();

    void readSocket();

    void displayError(QAbstractSocket::SocketError socketError);

    void on_OKip_clicked();

    void sendMessage(QString message);

    void Game();

    void hideImage();
    void on_Ok_clicked();

signals:
    void StArt();

private:
    Ui::GameServer *ui;
     QTimer *timer;
    QTcpSocket* MyClientSocket;
    QString Ipserver;
    Card ParrotClient1;
    Card ParrotClient2;
    QString NameOfOpponent;
    Card SelectedCard_you;
    Card SelectedCard_opponent;
    QString Turn;
    int NumberOfPredictClient;
    int NumberOfPredictServer;
    //Card PlayerCard_S;
    //Card PlayerCard_C;//Receiving from client
};

#endif // GAMESERVER_H
