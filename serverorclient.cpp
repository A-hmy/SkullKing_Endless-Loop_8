
#include "serverorclient.h"
#include "gameserver.h"
#include "mainwindow.h"
#include "ui_serverorclient.h"
#include <QMovie>
#include"function.h"
#include<QMessageBox>
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
    MyQtServer->setMaxPendingConnections(2);
    MyQtServer->listen(QHostAddress::Any,1205);
    if(MyQtServer->isListening()){
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
    MyServerSocket.insert(MyQtServer->nextPendingConnection());
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
//server
void ServerOrClient::readSocket()
{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());
    QByteArray buffer;
    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_5_15);
    socketStream.startTransaction();
    socketStream >> buffer;
//    if(!socketStream.commitTransaction())
//    {
//        QString message = QString("%1 :: Waiting for more data to come..").arg(socket->socketDescriptor());
//        emit newMessage(message);
//        return;
//    }

    QString header = buffer.mid(0,128);
    QString fileType = header.split(",")[0].split(":")[1];

    buffer = buffer.mid(128);

    /*if(fileType=="attachment"){
        QString fileName = header.split(",")[1].split(":")[1];
        QString ext = fileName.split(".")[1];
        QString size = header.split(",")[2].split(":")[1].split(";")[0];

        if (QMessageBox::Yes == QMessageBox::question(this, "QTCPServer", QString("You are receiving an attachment from sd:%1 of size: %2 bytes, called %3. Do you want to accept it?").arg(socket->socketDescriptor()).arg(size).arg(fileName)))
        {
            QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/"+fileName, QString("File (*.%1)").arg(ext));

            QFile file(filePath);
            if(file.open(QIODevice::WriteOnly)){
                file.write(buffer);
                QString message = QString("INFO :: Attachment from sd:%1 successfully stored on disk under the path %2").arg(socket->socketDescriptor()).arg(QString(filePath));
                emit newMessage(message);
            }else
                QMessageBox::critical(this,"QTCPServer", "An error occurred while trying to write the attachment.");
        }else{
            QString message = QString("INFO :: Attachment from sd:%1 discarded").arg(socket->socketDescriptor());
            emit newMessage(message);
        }*/
    //}else
    if(fileType=="message"){
        //QString message = QString("%1 :: %2").arg(socket->socketDescriptor()).arg(QString::fromStdString(buffer.toStdString()));
        //emit newMessage(message);
    }
}
//server
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
void ServerOrClient::sendMessage(QTcpSocket *socket)
{
    if(socket)
    {
        if(socket->isOpen())
        {
            //QString str = ui->lineEdit_message->text();

//            QDataStream socketStream(socket);
//            socketStream.setVersion(QDataStream::Qt_5_15);

//            QByteArray header;
//            header.prepend(QString("fileType:message,fileName:null,fileSize:%1;").arg(str.size()).toUtf8());
//            header.resize(128);

//            //QByteArray byteArray = str.toUtf8();
//            byteArray.prepend(header);

//            socketStream.setVersion(QDataStream::Qt_5_15);
//            socketStream << byteArray;
        }
        else
            QMessageBox::critical(this,"QTCPServer","Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this,"QTCPServer","Not connected");
}

