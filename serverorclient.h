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



private:
    Ui::ServerOrClient *ui;
    QTcpServer*MyQtServer;
    QTcpSocket*MyServerSocket;
};

#endif // SERVERORCLIENT_H
