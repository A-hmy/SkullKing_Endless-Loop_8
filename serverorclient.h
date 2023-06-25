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
    ~ServerOrClient();

private slots:

    void on_server_clicked();
    void on_client_clicked();
    void connecting();
    void connectedtoserver();
    void reading_Error();
    void on_IpServer_returnPressed();
signals:
    void send_error(QByteArray error);

private:
    Ui::ServerOrClient *ui;
    QTcpServer*MyQtServer;
    QTcpSocket*MyServerSocket;
    QTcpSocket*MyClientSocket;
};

#endif // SERVERORCLIENT_H
