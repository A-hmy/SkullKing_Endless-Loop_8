
#include "serverorclient.h"
#include "gameserver.h"
#include "ui_serverorclient.h"
#include <QMovie>
int numberOfclient=0;
ServerOrClient::ServerOrClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerOrClient)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->IpServer->setVisible(false);
    ui->ShowIp->setVisible(false);
    ui->Loading->setVisible(false);
}

ServerOrClient::~ServerOrClient()
{
    delete ui;
}
//server
void ServerOrClient::on_server_clicked()
{
    MyQtServer=new QTcpServer;
    MyQtServer->setMaxPendingConnections(1);
    MyQtServer->listen(QHostAddress::Any,8080);
    ui->Loading->setVisible(true);
    ui->ShowIp->setVisible(true);
    ui->client->setVisible(false);
    ui->server->setVisible(false);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    QLabel *mylabel=ui->Loading;
    mylabel->lower();
    QMovie *LoadingG=new QMovie(":/new/prefix1/Picture/load2.gif");
    ui->Loading->setMovie(LoadingG);
    ui->Loading->setScaledContents(true);
    ui->Loading->setAttribute(Qt::WA_StyledBackground, true);
     ui->Loading->setStyleSheet("background-color: brown");
    LoadingG->start();
    connect(MyQtServer,SIGNAL(newConnection()),this,SLOT(connecting()));
}

//client
void ServerOrClient::on_client_clicked()
{
    //Display server IP page
    ui->IpServer->setVisible(true);
    /*if(!ui->IpServer->text().isEmpty()){
    QString IpServer=ui->IpServer->text();
    MyClientSocket=new QTcpSocket;
    MyClientSocket->connectToHost(IpServer,8080);
    connect(MyClientSocket,SIGNAL(connected()),this,SLOT(connectedtoserver()));
    }*/

}
//client
void ServerOrClient::on_IpServer_returnPressed()
{
    if(!ui->IpServer->text().isEmpty()){
    QString IpServer=ui->IpServer->text();
    MyClientSocket=new QTcpSocket;
    MyClientSocket->connectToHost(IpServer,8080);
    connect(MyClientSocket,SIGNAL(connected()),this,SLOT(connectedtoserver()));
    connect(MyClientSocket,SIGNAL(readyRead()),this,SLOT(reading_Error()));
    }
}
//client
void ServerOrClient::connectedtoserver()
{
    if(MyClientSocket->state() == QAbstractSocket::ConnectedState){
    //GameClient *c=new GameClient;
    //c->show();
    //this->hide();
    }
    //else connect(MyClientSocket,SIGNAL(readyRead()),this,SLOT(reading_Error()));
}
//client
void ServerOrClient::reading_Error()
{
    QByteArray data=MyClientSocket->readAll();
    ui->IpServer->clear();
    ui->IpServer->setReadOnly(true);
    ui->IpServer->setText(data);
}
//server
void ServerOrClient::connecting()
{
     if(numberOfclient == 0){
    MyServerSocket=MyQtServer->nextPendingConnection();
     numberOfclient++;
    GameServer * m=new GameServer;
    m->show();
    this->hide();
    connect(MyServerSocket,SIGNAL(readyRead()),m,SLOT(Set()));//send cards
    //connect(this,&ServerOrClient::SendSocket,m,&GameServer::)
    //The server needs to send the selected card to the client, so that the client can display it
     }
     else {
             QTcpSocket* socket = MyQtServer->nextPendingConnection();
             QString message = "Server is busy";
             socket->write(message.toUtf8());
             socket->waitForBytesWritten();
             socket->close();
         }

}



