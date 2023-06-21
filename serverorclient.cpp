
#include "serverorclient.h"
#include "gameserver.h"
#include "gameclient.h"
#include "ui_serverorclient.h"
#include <QMovie>
ServerOrClient::ServerOrClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerOrClient)
{
    ui->setupUi(this);
    ui->IpServer->setVisible(false);
    ui->ShowIp->setVisible(false);
    ui->Loading->setVisible(false);
}

ServerOrClient::~ServerOrClient()
{
    delete ui;
}

void ServerOrClient::on_server_clicked()
{
    MyQtServer=new QTcpServer;
    MyQtServer->listen(QHostAddress::Any,8080);
    ui->Loading->setVisible(true);
    ui->ShowIp->setVisible(true);
    /*QMovie *Loading=new QMovie("Loading.gif");
    ui->Loading->setMovie(Loading);
    ui->client->setVisible(false);
    ui->server->setVisible(false);
    ui->label->setVisible(false);
    Loading->start();*/
    //Displaying the waiting page and IP
    connect(MyQtServer,SIGNAL(newConnection()),this,SLOT(connecting()));
}


void ServerOrClient::on_client_clicked()
{
    //Display server IP page
    ui->IpServer->setVisible(true);
    if(!ui->IpServer->text().isEmpty()){
    QString IpServer=ui->IpServer->text();
    MyClientSocket=new QTcpSocket;
    MyClientSocket->connectToHost(IpServer,8080);
    connect(MyClientSocket,SIGNAL(connected()),this,SLOT(connectedtoserver()));
    }

}
void ServerOrClient::connectedtoserver()
{
    GameClient *c=new GameClient;
    c->show();
    this->hide();
}
void ServerOrClient::connecting()
{
    MyServerSocket=MyQtServer->nextPendingConnection();
    GameServer * m=new GameServer;
    m->show();
    this->hide();
    connect(MyServerSocket,SIGNAL(readyRead()),m,SLOT(Set()));
    //The server needs to send the selected card to the client, so that the client can display it

}

