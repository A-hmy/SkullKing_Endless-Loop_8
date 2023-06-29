#include "gameserver.h"
#include "qtcpsocket.h"
#include "ui_gameserver.h"
#include "function.h"
#include"mainwindow.h"
#include"QTcpSocket"
#include<QMovie>
#include<QHostAddress>
#include<QHostInfo>
#include<serverorclient.h>
#include<QMessageBox>
#include "global.h"
GameServer::GameServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameServer)
{
    ui->setupUi(this);
    ui->OKip->setVisible(false);
    ui->IpServer->setVisible(false);
    ui->YourIp->setVisible(false);
    setWindowFlags(Qt::FramelessWindowHint);
    MyClientSocket = new QTcpSocket;
    connect(MyClientSocket, &QTcpSocket::readyRead, this, &GameServer::readSocket);
    connect(MyClientSocket, &QTcpSocket::disconnected, this, &GameServer::discardSocket);
    connect(MyClientSocket, &QAbstractSocket::errorOccurred, this, &GameServer::displayError);
    connect(MyClientSocket,&QTcpSocket::connected,this,&GameServer::connectt);
    //Loading Gif
    QMovie *LoadingG=new QMovie(":/new/prefix1/Picture/gifloading.gif");
    ui->Loading->setMovie(LoadingG);
    ui->Loading->setScaledContents(true);
    ui->Loading->setAttribute(Qt::WA_StyledBackground, true);
    ui->Loading->setStyleSheet("background-color: brown");
    LoadingG->start();
    //server
    if(s_or_c==1){
        Ipserver="127.0.0.1";
        ui->YourIp->setVisible(true);
        foreach(const QHostAddress &address, QHostInfo::fromName(QHostInfo::localHostName()).addresses()) {
            if(address.protocol() == QAbstractSocket::IPv4Protocol) {
                Ipserver = address.toString();
                break;
            }
        }
        if(!Ipserver.isEmpty()) {
          ui->YourIp->clear();
          QString ip="Your Ip : "+Ipserver;
          ui->YourIp->addItem(ip);
          ui->YourIp->setStyleSheet("background-color: qconicalgradient(cx:0, cy:1, angle:0, stop:0.0673077 rgba(156, 105, 60, 255), stop:1 rgba(255, 255, 255, 255)); font: 15pt \"Segoe UI\"; font: 15pt \"Segoe Script\"; border-radius: 10px;");
        }
        MyClientSocket->connectToHost("127.0.0.1",1205);
    }
    //client
    else if(s_or_c==0) {
        ui->IpServer->setVisible(true);
        ui->OKip->setVisible(true);}
    }



GameServer::~GameServer()
{
    if(MyClientSocket->isOpen())
        MyClientSocket->close();
    delete ui;
}

void GameServer::Game()
{
    for (int i=0;i<7;i++){
        Dealing(i);
        if (i==1){
            srand(time(NULL));
            int index = rand() % (Parrot.size()+ 1);
            if (Parrot[index]->get_Reserved() != 1) {
                ParrotClient1 = *(Parrot[index]);
                Parrot[index]->set_Reserved(true);
            }
            index = rand() % (Parrot.size()+ 1);
            if (Parrot[index]->get_Reserved() != 1) {
                ParrotClient2 = *(Parrot[index]);
                Parrot[index]->set_Reserved(true);
            }
            if(ParrotClient1.get_Number()>ParrotClient2.get_Number()){

            }
        }

    }
}


void GameServer::connectt()
{
    if(s_or_c==0){
        if(MyClientSocket->state() == QAbstractSocket::ConnectedState){
            ui->Loading->hide();
            ui->OKip->setVisible(false);
            ui->IpServer->setVisible(false);
            //MyClientSocket->write("Client connected");
            //MyClientSocket->waitForBytesWritten(-1);
            QString Username=player->get_UserName();
            sendMessage(Username+"^"+"Client connected");


    }
    }
}

void GameServer::discardSocket()
{
    //loading gif**************
    //MyClientSocket->deleteLater();
    //MyClientSocket=nullptr;
    MyClientSocket->connectToHost(Ipserver,1205);
    QAbstractSocket::connect(MyClientSocket,SIGNAL(connected()),this,SLOT(connect()));
}


void GameServer::readSocket()
{
    QByteArray buffer;
    QDataStream socketStream(MyClientSocket);
    socketStream.setVersion(QDataStream::Qt_5_15);

   socketStream.startTransaction();
   socketStream >> buffer;
   //QString header = buffer.mid(0,128);
    //QString fileType = header.split(",")[0].split(":")[1];
    //buffer = buffer.mid(128);
   //if(fileType=="message"){
          QString message = QString("%1").arg(QString::fromStdString(buffer.toStdString()));
           //emit newMessage(message);
          QString ClientConnect=message.split("^")[1];
          if(ClientConnect=="Client connected"){
              NameOfOpponent=message.split("^")[0];
              ui->YourIp->hide();
              ui->Loading->hide();
              ui->UsernameOpponent->setText(NameOfOpponent);
              ui->UsernameYou->setText(player->get_UserName());
              // function Game**************************************************************
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
          }
           if(part1=="1")
               Game();
          if(part1=="2"){
              for(auto x:_cards){
                  if(part2==x->get_Name()&&part3==QString::number(x->get_Number())){
                      SelectedCard=*x;
                      break;
                  }
              }
              ui->Opponent->setPixmap(SelectedCard.Picture);
          }
>>>>>>> aee48ee448551460599fbb268bb961b75748ca5f
>>>>>>> sana

          }
   }

//change QMessageBox
void GameServer::displayError(QAbstractSocket::SocketError socketError)
{
    /*switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
        break;
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, "QTCPClient", "The host was not found. Please check the host name and port settings.");
        break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, "QTCPClient", "The connection was refused by the peer. Make sure QTCPServer is running, and check that the host name and port settings are correct.");
        break;
        default:
            QMessageBox::information(this, "QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
        break;
    }*/
}

void GameServer::on_card_1_clicked()
{
    if(ui->NumberOfPredict->isVisible()){
    }
}

void GameServer::on_card_2_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_card_3_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_card_4_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_card_5_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_card_6_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_card_7_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_card_8_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_card_9_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_card_10_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_card_11_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_card_12_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_card_13_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_card_14_clicked()
{
    if(ui->NumberOfPredict->isVisible()){

    }
}

void GameServer::on_OKip_clicked()
{
    if(!ui->IpServer->text().isEmpty()){
        Ipserver=ui->IpServer->text();
        MyClientSocket->connectToHost(Ipserver,1205);
        //connect(MyClientSocket,SIGNAL(connected()),this,SLOT(connectt()));
    }
    else
        ui->IpServer->setPlaceholderText("Enter IP");
}

void GameServer::sendMessage(QString message)
{
    if(MyClientSocket)
    {
        if(MyClientSocket->isOpen())
        {
            //QString str = ui->lineEdit_message->text();

            QDataStream socketStream(MyClientSocket);
            socketStream.setVersion(QDataStream::Qt_5_15);

            //QByteArray header;
            //header.prepend(QString("fileType:message,fileName:null,fileSize:%1;").arg(str.size()).toUtf8());
            //header.resize(128);

            QByteArray byteArray = message.toUtf8();
            //byteArray.prepend(header);

            socketStream << byteArray;

            //ui->lineEdit_message->clear();
        }
        else
            QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this,"QTCPClient","Not connected");
}

