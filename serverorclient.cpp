#include "serverorclient.h"
#include "gameserver.h"
#include "mainwindow.h"
#include "ui_serverorclient.h"
#include <QMovie>
#include"function.h"
#include<QMessageBox>
#include"gameserver.h"
#include<QDebug>
#include"global.h"
#include "menu.h"
ServerOrClient::ServerOrClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerOrClient)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
}

ServerOrClient::~ServerOrClient()
{
    delete ui;
}
//server
void ServerOrClient::on_server_clicked()
{
    MyQtServer=new QTcpServer;
    //MyQtServer->setMaxPendingConnections(2);
    MyQtServer->listen(QHostAddress::Any,1205);
    if(MyQtServer->isListening()){
    s_or_c=1;//server=1
    GameServer * Game=new GameServer;
    Game->show();
    this->hide();
    connect(MyQtServer,SIGNAL(newConnection()),this,SLOT(connecting()));
    }
    // if can not listen*********
    else {
        QFont Font("Segoe Script",10);
        QMessageBox* message=new QMessageBox;
        message->setFont(Font);
        message->setStyleSheet("background-color:rgb(112, 66, 33);;color:white");
        message->setText("Not listening");
        QPixmap pixmap(":/new/prefix1/Picture/iconQMessageBox.png");
        message->setIconPixmap(pixmap);
        message->setWindowFlags(Qt::FramelessWindowHint);
        message->show();
        message->exec();
    }
}
//server
void ServerOrClient::connecting()
{
    if(MyQtServer->hasPendingConnections()){
    if(numberOfclient <2){
    QTcpSocket *socket=MyQtServer->nextPendingConnection();
    MyServerSocket.insert(socket);
    connect(socket, &QTcpSocket::readyRead, this, &ServerOrClient::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &ServerOrClient::discardSocket);
    connect(socket, &QAbstractSocket::errorOccurred, this, &ServerOrClient::displayError);
    numberOfclient++;
    this->hide();
    }
     }
    else {
             QTcpSocket* socket = MyQtServer->nextPendingConnection();
             QString message = "Server is busy";
             socket->write(message.toUtf8());
             socket->waitForBytesWritten();
             socket->close();
      }
}
//server (read)
void ServerOrClient::readSocket()
{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());
    QByteArray buffer;
    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_5_15);
    socketStream.startTransaction();
    socketStream >> buffer;
        QString message = QString("%1").arg(QString::fromStdString(buffer.toStdString()));
        //QString Part2=message.split("^")[1];
        //if(Part2=="Client connected"){
        foreach(QTcpSocket * socket2,MyServerSocket){
            if(socket->socketDescriptor()!=socket2->socketDescriptor()){
                sendMessage(socket2,message);
                break;
            }
        }
        //}

    //}
}
//server(disconnect)
void ServerOrClient::discardSocket()
{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());
    QSet<QTcpSocket*>::iterator it = MyServerSocket.find(socket);
    if (it != MyServerSocket.end()){
        MyServerSocket.remove(*it);
    }
    socket->deleteLater();
}
//server change QMessageBox?!!!!!!!!!!!!!!!!!!
void ServerOrClient::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
        break;
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, "QTCPServer", "The host was not found. Please check the host name and port settings.");
        break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, "QTCPServer", "The connection was refused by the peer. Make sure QTCPServer is running, and check that the host name and port settings are correct.");
        break;
        default:
            QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
            QMessageBox::information(this, "QTCPServer", QString("The following error occurred: %1.").arg(socket->errorString()));
        break;
    }
}
//server when clicked pushbutton
// this function is called in read all
void ServerOrClient::sendMessage(QTcpSocket *socket,QString message)
{
    if(socket)
    {
        if(socket->isOpen())
        {
            QDataStream socketStream(socket);
            socketStream.setVersion(QDataStream::Qt_5_15);

           // QByteArray header;
            //header.prepend(QString("fileType:message,fileName:null,fileSize:%1;").arg(str.size()).toUtf8());
            //header.resize(128);

           // QByteArray byteArray = str.toUtf8();
            QByteArray byteArray=message.toUtf8();
            //byteArray.prepend(header);

            socketStream.setVersion(QDataStream::Qt_5_15);
            socketStream << byteArray;
        }
        else
            QMessageBox::critical(this,"QTCPServer","Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this,"QTCPServer","Not connected");
}
void ServerOrClient::on_client_clicked()
{
    s_or_c=0;//client=0
    GameServer * Game=new GameServer;
    Game->show();
    this->hide();
}


void ServerOrClient::on_pushButton_clicked()
{
    this->close();
       Menu *m=new Menu;
       m->show();
}

