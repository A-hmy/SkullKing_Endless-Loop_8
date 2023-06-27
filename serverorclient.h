#ifndef SERVERORCLIENT_H
#define SERVERORCLIENT_H
#include <QTcpServer>
#include<QTcpSocket>
#include <QMainWindow>
#include "board.h"
namespace Ui {
class ServerOrClient;
}

class ServerOrClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerOrClient(QWidget *parent = nullptr);
    void PlayingGame();
    ~ServerOrClient();

private slots:

    void on_server_clicked();
    void on_client_clicked();
    void connecting();
    void connectedtoserver();
    void received();
    void on_IpServer_returnPressed();
    void receivedCardFromBoard();
signals:
    void send_error(QByteArray error);

private:
    Ui::ServerOrClient *ui;
    QTcpServer*MyQtServer;
    QTcpSocket*MyServerSocket;
    QTcpSocket*MyClientSocket;
    Card PlayerCard_S;
    Card PlayerCard_C;//Receiving from client
};

#endif // SERVERORCLIENT_H
