#ifndef GAMESERVER_H
#define GAMESERVER_H
#include"card.h"
#include <QMainWindow>
#include"board.h"
#include "qtcpsocket.h"
#include<QStandardPaths>
#include<QMetaType>
#include<QAbstractSocket>
#include <QTimer>
#include <algorithm>
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
    bool EndSet();
    void SendCardsToClient();
    bool CheckPushButton(QString card);
    void clickedServer(QString card);
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

    void on_StopResume_clicked();

    void on_Exit_clicked();

    void countdown();

    void Score(int a);

    void showPushButton();

    void on_ChangeCard_clicked();

    void on_accept_clicked();

    void on_reject_clicked();

signals:
    void StArt();
    void ScOre(int a);
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
    QString ChangedCard;
    int NumberOfRound;
    int StopResumeRequest;
    int NumberOfPredictClient;
    int NumberOfPredictServer;
    int OpponentScore;//emtiyaz akhar
    int YouScore;//emtiyaz akhar
    int ScoreSet_You;
    int ScoreSet_Opponent;
    QTimer *timerresume;
    int count;
};

#endif // GAMESERVER_H
