#include "gameserver.h"
#include "qtcpsocket.h"
#include "ui_gameserver.h"
#include "function.h"
#include"mainwindow.h"
#include "menu.h"
#include"QTcpSocket"
#include<QMovie>
#include<QHostAddress>
#include<QHostInfo>
#include<serverorclient.h>
#include<QMessageBox>
#include "global.h"
#include<QDebug>
#include <QTimer>
#include<thread>
GameServer::GameServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameServer)
{
    ui->setupUi(this);
    connect(ui->card_1, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(ui->card_2, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(ui->card_3, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(ui->card_4, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(ui->card_5, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(ui->card_6, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(ui->card_7, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(ui->card_8, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(ui->card_9, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(ui->card_10, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(ui->card_11, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(ui->card_12, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(ui->card_13, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(ui->card_14, &QPushButton::clicked, this, &GameServer::onButtonClicked);
    connect(this,&GameServer::ScOre, this,&GameServer::Score);
    //connect(timer, SIGNAL(timeout()), this, SLOT(hideImage()));
    ui->OKip->setVisible(false);
    ui->IpServer->setVisible(false);
    ui->YourIp->setVisible(false);
    ui->Counter->setVisible(false);
    ui->LoadingStop->setVisible(false);
    timer = new QTimer(this);
    StartGame();
    //setWindowFlags(Qt::FramelessWindowHint);
    MyClientSocket = new QTcpSocket;
    connect(MyClientSocket, &QTcpSocket::readyRead, this, &GameServer::readSocket);
    connect(MyClientSocket, &QTcpSocket::disconnected, this, &GameServer::discardSocket);
    connect(MyClientSocket, &QAbstractSocket::errorOccurred, this, &GameServer::displayError);
    connect(MyClientSocket,&QTcpSocket::connected,this,&GameServer::connectt);
    connect(this,SIGNAL(StArt()),this,SLOT(Game()));
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

void GameServer::DisplayCards()
{
    int i=0;
    QPushButton *buttons[14];
    for(auto x:player->get_cards()){
        QString PushButton="card_"+QString::number(i+1);//name of PushButton
        buttons[i]= findChild<QPushButton*>(PushButton);//find PushButton
        QString image="border-image: url("+x.get_Picture()+");"+"font: 1pt";
        buttons[i]->setStyleSheet(image);
        QString text=x.get_Name()+"*"+QString::number(x.get_Number());
        buttons[i]->setText(text);
        i++;
    }
    for(;i<14;i++){
        QString PushButton="card_"+QString::number(i+1);//name of PushButton
        buttons[i]= findChild<QPushButton*>(PushButton);//find PushButton
        buttons[i]->setVisible(false);
    }
}

void GameServer::DisplayingACard_you(QString card)
{
    QString name=card.split("*")[0];
    QString num=card.split("*")[1];
    for(auto x:_cards){
        if(name==x->get_Name()&&num==QString::number(x->get_Number())){
            SelectedCard_you=*x;
            break;
        }
    }
    QString image="border-image: url("+SelectedCard_you.get_Picture()+");";
    ui->You->setStyleSheet(image);
}

void GameServer::DisplayingACard_opponent(QString card)
{
    QString name=card.split("*")[0];
    QString num=card.split("*")[1];
    for(auto x:_cards){
        if(name==x->get_Name()&&num==QString::number(x->get_Number())){
            SelectedCard_opponent=*x;
            break;
        }
    }
    QString image="border-image: url("+SelectedCard_opponent.get_Picture()+");";
    ui->Opponent->setStyleSheet(image);
}

bool GameServer::EndSet()
{
    int i=0;
    int flag=0;
    QPushButton *buttons[14];
    for(int i=0;i<14;i++){
        QString PushButton="card_"+QString::number(i+1);//name of PushButton
        buttons[i]= findChild<QPushButton*>(PushButton);//find PushButton
        if(buttons[i]->isVisible()){
            flag=1;
            return 1;//hanoz set edame dare
        }
    }
    return 0;//set tamom shade
}

void GameServer::SendCardsToClient()//ferestadan card ha baraye client**********
{
    int size=CardsOfPlayerClient.size();
    QString cards="7^"+QString::number(size)+"^";
    for(auto x:CardsOfPlayerClient){
        cards+=x->get_Name()+"*"+QString::number(x->get_Number())+"||";
    }
    QTimer timer;
    timer.setInterval(5000);
    sendMessage(cards);
}

void GameServer::connectt()
{
    if(s_or_c==0){
        if(MyClientSocket->state() == QAbstractSocket::ConnectedState){
            ui->Loading->hide();
            ui->OKip->setVisible(false);
            ui->IpServer->setVisible(false);
            QString Username=player->get_UserName();
            sendMessage("1^"+Username+"^"+"Client connected");
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
          QString message = QString("%1").arg(QString::fromStdString(buffer.toStdString()));
          QString part1=message.split("^")[0];
          //server // client 2 omade
        qDebug()<<part1;
          if(part1=="1"){
              //sendMessage("3^"+player->get_UserName());
              MyClientSocket->waitForBytesWritten(-1);
              QString part2=message.split("^")[1];
              qDebug()<<part2;
              //QString part3=message.split("^")[2];
              NameOfOpponent=part2;
              ui->YourIp->hide();
              ui->Loading->hide();
              ui->UsernameOpponent->setText(NameOfOpponent);
              ui->UsernameYou->setText(player->get_UserName());
              NumberOfRound=1;
              emit StArt();//call function Game
          }
          qDebug()<<s_or_c;
          //client // send parrot//set 1
          if(part1=="2"){
              QString p1=message.split("||")[0];//card1
              QString p2=message.split("||")[1];//card2
              QString p3=message.split("||")[2];//name server
              QString p4=message.split("||")[3];//turn
              QString p5=message.split("||")[4];//cards_1
              QString p6=message.split("||")[5];//cards_2
              Turn=p4;
              NameOfOpponent=p3;
              ui->Turn->setText(Turn+"'s turn");
              QString part2=p1.split("^")[1];
              QString part3=p1.split("^")[2];
              QString Part4=p2.split("^")[1];
              QString Part5=p2.split("^")[2];
              QString Part6=p5.split("*")[0];//name of card
              QString Part7=p5.split("*")[1];//number of card
              QString Part8=p6.split("*")[0];//name of card
              QString Part9=p6.split("*")[1];//number of card
              for(auto x:_cards){
                  if(Part6==x->get_Name()&&Part7==QString::number(x->get_Number())){
                      player->set_Cards(*x);
                      break;
                  }
              }
              for(auto x:_cards){
                  if(Part8==x->get_Name()&&Part9==QString::number(x->get_Number())){
                      player->set_Cards(*x);
                      break;
                  }
              }
              for(auto x:_cards){
                  if(part2==x->get_Name()&&part3==QString::number(x->get_Number())){
                      SelectedCard_you=*x;
                      break;
                  }
              }
              for(auto x:_cards){
                  if(Part4==x->get_Name()&&Part5==QString::number(x->get_Number())){
                      SelectedCard_opponent=*x;
                      break;
                  }
              }
              QString image="border-image: url("+SelectedCard_opponent.get_Picture()+");";
              ui->Opponent->setStyleSheet(image);
              image="border-image: url("+SelectedCard_you.get_Picture()+");";
              ui->You->setStyleSheet(image);
              ui->UsernameYou->setText(player->get_UserName());
              ui->UsernameOpponent->setText(p3);
              //timer->start(3000);
              DisplayCards();
          }
          //server to client&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
          if(part1=="3"){
              DisplayingACard_opponent(message.split("^")[1]);
              for(auto x:_cards){
                  if(message.split("^")[1].split("*")[0]==x->get_Name()&&message.split("^")[1].split("*")[1]==QString::number(x->get_Number())){
                      SelectedCard_opponent=*x;
                      break;
                   }
              }
              Turn=message.split("^")[2];
              ui->Turn->setText(Turn+"'s turn");
              QString part2=message.split("^")[3];
              QString ScoreO=part2.split("*")[0];
              QString ScoreY=part2.split("*")[1];
              ui->ScoreOpponent->setText(ScoreO);
              ui->ScoreYou->setText(ScoreY);
          }
          //client to server&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
          if(part1=="4"){
              DisplayingACard_opponent(message.split("^")[1]);
              for(auto x:_cards){
                  if(message.split("^")[1].split("*")[0]==x->get_Name()&&message.split("^")[1].split("*")[1]==QString::number(x->get_Number())){
                      SelectedCard_opponent=*x;
                      break;
                   }
              }
              Turn=message.split("^")[2];
              ui->Turn->setText(Turn+"'s turn");
              if(SelectedCard_you.get_Name()!=" "){
                  emit ScOre(1);
              }
          }
          //stop
          if(part1=="5"){

                  QMovie *LoadingG=new QMovie(":/new/prefix1/Picture/loadingstop.gif");
                  ui->LoadingStop->setMovie(LoadingG);
                  ui->LoadingStop->show();
                  ui->LoadingStop->setScaledContents(true);
                 // ui->LoadingStop->setAttribute(Qt::WA_StyledBackground, true);
                 // ui->Loading->setStyleSheet("background-color: brown");
                  LoadingG->start();


                  timerresume = new QTimer(this);
                  connect(timerresume, SIGNAL(timeout()), this, SLOT(countdown()));
                  timerresume->start(1000);
                  count = 20;
                  ui->Counter->show();
                 // ui->StopResume.remo
                  ui->StopResume->setText("Resume");
                  ui->StopResume->setStyleSheet("border-image: url(:/new/prefix1/Picture/Resume1.png)");
          }
          //resume
          if (part1=="6"){
              ui->StopResume->setText("Stop");
              ui->LoadingStop->hide();
              ui->Counter->hide();
              ui->StopResume->setStyleSheet("border-image: url(:/new/prefix1/Picture/Stop1.png)");
          }
          //client//daryaft card&&&&&&&&&&&&&&&&&&&&&&&&
          if(part1=="7"){
              showPushButton();
              player->clear_Cards();
              int size=message.split("^")[1].toInt(nullptr,10);
              QString card=message.split("^")[2];
              for(int i=0;i<size;i++){
                  QString c=card.split("||")[i];
                  QString n=c.split("*")[0];
                  int num=c.split("*")[1].toInt(nullptr,10);
                  for(auto x:_cards){
                      if(n==x->get_Name()&&num==x->get_Number()){
                          player->set_Cards(*x);
                          break;
                      }
                  }
              }
              DisplayCards();
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

void GameServer::onButtonClicked()
{
    //server&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    if(s_or_c==1){
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString NameButton=button->objectName();
    QPushButton *Pushbutton =findChild<QPushButton*>(NameButton);
    if(!ui->NumberOfPredict->isVisible()){
        if(Turn==player->get_UserName()){
           QString card=Pushbutton->text();
           for(auto x:_cards){
               if(card.split("*")[0]==x->get_Name()&&card.split("*")[1]==QString::number(x->get_Number())){
                   SelectedCard_you=*x;
                   break;
                }
           }
           if(SelectedCard_opponent.get_Name()!=" "){
               emit ScOre(0);
           }
           DisplayingACard_you(card);
           Turn=NameOfOpponent;
           sendMessage("3^"+card+"^"+Turn+"^"+QString::number(ScoreSet_You)+"*"+QString::number(ScoreSet_Opponent));
           ui->Turn->setText(Turn+"'s turn");
           Pushbutton->setVisible(false);
        }
    }
    else{
         ui->NumberOfPredict->setPlaceholderText("❗❗❗❗❗");
    }
    }
    //client&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    if(s_or_c==0){
        QPushButton *button = qobject_cast<QPushButton *>(sender());
        QString NameButton=button->objectName();
        QPushButton *Pushbutton =findChild<QPushButton*>(NameButton);
        if(!ui->NumberOfPredict->isVisible()){
            if(Turn==player->get_UserName()){
               QString card=Pushbutton->text();
               for(auto x:_cards){
                   if(card.split("*")[0]==x->get_Name()&&card.split("*")[1]==QString::number(x->get_Number())){
                       SelectedCard_you=*x;
                       break;
                    }
               }
               DisplayingACard_you(card);
               Turn=NameOfOpponent;
               sendMessage("4^"+card+"^"+Turn);
               ui->Turn->setText(Turn+"'s turn");
               Pushbutton->setVisible(false);
            }
        }
        else{
             ui->NumberOfPredict->setPlaceholderText("❗❗❗❗❗");
        }
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
//server
void GameServer::Game()
{
    ScoreSet_You=0;
    ScoreSet_Opponent=0;
    SelectedCard_you.set_Name(" ");
    SelectedCard_opponent.set_Name(" ");
    player->clear_Cards();
    CardsOfPlayerClient.clear();
    Dealing(NumberOfRound);
       //first set*****************************
        if (NumberOfRound==1){
            for(int j=0;j<Parrot.size();j++){
                Parrot[j]->set_Reserved(false);
            }
            srand(time(NULL));
            int index = rand() % (Parrot.size());
            if (Parrot[index]->get_Reserved() != 1) {
                ParrotClient1 = *(Parrot[index]);//khodesh(server)
                QString image="border-image: url("+ParrotClient1.get_Picture()+");";
                //QPixmap mypixmap(ParrotClient1.get_Picture());
                ui->You->setStyleSheet(image);
                //ui->You->setScaledContents(true);
                Parrot[index]->set_Reserved(true);
            }
            index = rand() % (Parrot.size());
            if (Parrot[index]->get_Reserved() != 1) {
                ParrotClient2 = *(Parrot[index]);//on yeki(client)
                QString image="border-image: url("+ParrotClient2.get_Picture()+");";
                ui->Opponent->setStyleSheet(image);
                Parrot[index]->set_Reserved(true);
            }
            if(ParrotClient1.get_Number()>ParrotClient2.get_Number()){
                //nobat server
                Turn=player->get_UserName();
            }
            else{
                Turn=NameOfOpponent;
            }
            if (Turn==player->get_UserName()){
                qDebug()<<"server Turn";
            }
            ui->Turn->setText(Turn+"'s turn");
            //timer->start(3000);
            QString card1="2^"+ParrotClient2.get_Name()+"^"+QString::number(ParrotClient2.get_Number());
            QString card2="2^"+ParrotClient1.get_Name()+"^"+QString::number(ParrotClient1.get_Number());
            QString cards=CardsOfPlayerClient[0]->get_Name()+"*"+QString::number(CardsOfPlayerClient[0]->get_Number())+"||"+CardsOfPlayerClient[1]->get_Name()+"*"+QString::number(CardsOfPlayerClient[1]->get_Number());
            sendMessage(card1+"||"+card2+"||"+player->get_UserName()+"||"+Turn+"||"+cards);
            DisplayCards();
        }
        //timer->start(3000);
        else{
        SendCardsToClient();
        DisplayCards();
        }
}


void GameServer::Score(int a)
{
    if(SelectedCard_you.get_Name()!="Queen"&&SelectedCard_you.get_Name()!="King"&&SelectedCard_you.get_Name()!="Pirate"&&SelectedCard_opponent.get_Name()!="Queen"&&SelectedCard_opponent.get_Name()!="King"&&SelectedCard_opponent.get_Name()!="Pirate"){

       if(SelectedCard_you.get_value()>SelectedCard_opponent.get_value()){
        ScoreSet_You++;
       }
        else {
        ScoreSet_Opponent++;
       }
    }
    ////////////Queen
     if(SelectedCard_you.get_Name()=="Queen"){
             if(SelectedCard_opponent.get_Name()=="Queen"){
                 if(a==1){
                     ScoreSet_You++;
                     YouScore+=40;
                 }
                 else{
                     ScoreSet_Opponent++;
                     OpponentScore+=40;
                 }

             }
             else if(SelectedCard_opponent.get_Name()=="King"){
                 ScoreSet_You++;
                 YouScore+=35;
             }
             else if(SelectedCard_opponent.get_Name()=="Pirate"){
                 ScoreSet_Opponent++;
                 OpponentScore+=30;
             }
              if(SelectedCard_opponent.get_Name()=="Flag"||SelectedCard_opponent.get_Name()=="Treasure"||SelectedCard_opponent.get_Name()=="Map"||SelectedCard_opponent.get_Name()=="Parrot"){
                  ScoreSet_You++;
                  YouScore+=20;
              }
    }
         ////////////King
         if(SelectedCard_you.get_Name()=="King"){
             if(SelectedCard_opponent.get_Name()=="Queen"){
                 //dast baraye be client
                 ScoreSet_Opponent++;
                 OpponentScore+=35;
             }
             else if(SelectedCard_opponent.get_Name()=="King"){
                 //nafar aval
                 if(a==1){
                     ScoreSet_You++;
                     YouScore+=30;
                 }
                 else{
                     ScoreSet_Opponent++;
                     OpponentScore+=30;
                 }
             }
             else if(SelectedCard_opponent.get_Name()=="Pirate"){
                 //dast baraye server
                 ScoreSet_You++;
                 YouScore+=25;
             }
             if(SelectedCard_opponent.get_Name()=="Flag"||SelectedCard_opponent.get_Name()=="Treasure"||SelectedCard_opponent.get_Name()=="Map"||SelectedCard_opponent.get_Name()=="Parrot"){
                 //dast baraye server
                 ScoreSet_You++;
                 YouScore+=15;
             }

         }
         ////////////Pirate
         if(SelectedCard_you.get_Name()=="Pirate"){

             if(SelectedCard_opponent.get_Name()=="Queen"){
                 ////dast baraye be server
                 ScoreSet_You++;
                 YouScore+=30;
             }
             else if(SelectedCard_opponent.get_Name()=="King"){
                 //dast baraye client
                 ScoreSet_Opponent++;
                 OpponentScore+=30;
             }
             else if(SelectedCard_opponent.get_Name()=="Pirate"){
                //nafar aval
                 if(a==1){
                     ScoreSet_You++;
                     YouScore+=20;
                 }
                 else{
                     ScoreSet_Opponent++;
                     OpponentScore+=20;
                 }
             }
             if(SelectedCard_opponent.get_Name()=="Flag"||SelectedCard_opponent.get_Name()=="Treasure"||SelectedCard_opponent.get_Name()=="Map"||SelectedCard_opponent.get_Name()=="Parrot"){
                 //dast baraye server
                 ScoreSet_You++;
                 YouScore+=10;
             }

}

             if(SelectedCard_you.get_Name()=="Flag"||SelectedCard_you.get_Name()=="Treasure"||SelectedCard_you.get_Name()=="Map"||SelectedCard_you.get_Name()=="Parrot"){
                 if(SelectedCard_opponent.get_Name()!="Queen"){
                     ScoreSet_Opponent++;
                     OpponentScore+=20;
                 }
                 else if(SelectedCard_opponent.get_Name()!="King"){
                     ScoreSet_Opponent++;
                     OpponentScore+=15;
                 }
                 else if(SelectedCard_opponent.get_Name()!="Pirate"){
                     ScoreSet_Opponent++;
                     OpponentScore+=10;
                 }
             }

         SelectedCard_you.set_Name(" ");
         SelectedCard_opponent.set_Name(" ");
         ui->ScoreYou->setText(QString::number(ScoreSet_You));
         ui->ScoreOpponent->setText(QString::number(ScoreSet_Opponent));
         if(!EndSet()){// set is finished
             if(ScoreSet_You>ScoreSet_Opponent){
                 Turn=player->get_UserName();
                 NumberOfRound++;
                 showPushButton();
                 if(NumberOfRound!=7){
                     //QMessageBox::information(this,"*","dsfd");
                     emit StArt();
                 }
             }
             else{
                 Turn=NameOfOpponent;
                 NumberOfRound++;
                 if(NumberOfRound!=7){
                     //QMessageBox::information(this,"*","dsfd");
                     emit StArt();
                 }
             }
         }
}

void GameServer::showPushButton()//restart page
{
    QPushButton *buttons[14];
    for(int i=0;i<14;i++){
        QString PushButton="card_"+QString::number(i+1);//name of PushButton
        buttons[i]= findChild<QPushButton*>(PushButton);//find PushButton
           buttons[i]->setVisible(true);
    }
    ScoreSet_You=0;
    ScoreSet_Opponent=0;
    ui->NumberOfPredict->setVisible(true);
    ui->Ok->setVisible(true);
    ui->lablePredict->setVisible(true);
    ui->ScoreYou->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(139, 121, 117, 255), stop:1 rgba(255, 255, 255, 255));border-radius:10px;");
    ui->ScoreOpponent->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(139, 121, 117, 255), stop:1 rgba(255, 255, 255, 255));border-radius:10px;");
    ui->Opponent->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(139, 121, 117, 255), stop:1 rgba(255, 255, 255, 255));border-radius:10px;");
    ui->You->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(139, 121, 117, 255), stop:1 rgba(255, 255, 255, 255));border-radius:10px;");
}
void GameServer::hideImage()
{
    ui->You->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(139, 121, 117, 255), stop:1 rgba(255, 255, 255, 255));border-radius:10px;");
    ui->Opponent->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(139, 121, 117, 255), stop:1 rgba(255, 255, 255, 255));border-radius:10px;");
}

void GameServer::on_Ok_clicked()
{
    //error if write wrong
    if(!ui->NumberOfPredict->text().isEmpty()){
        NumberOfPredictServer=ui->NumberOfPredict->text().toInt(nullptr,10);
        ui->NumberOfPredict->setVisible(false);
        ui->Ok->setVisible(false);
        ui->lablePredict->setVisible(false);
    }
    else{
        ui->NumberOfPredict->setPlaceholderText("❗❗❗❗❗");
    }

}

void GameServer::on_StopResume_clicked()
{
    ui->LoadingStop->setVisible(true);
    ui->Counter->setVisible(true);
    //if background be a stop
    //if()
    //for another player stop
    if(ui->StopResume->text()=="Stop"){
    QMovie *LoadingG=new QMovie(":/new/prefix1/Picture/loadingstop.gif");
    ui->LoadingStop->setMovie(LoadingG);
    ui->LoadingStop->show();
    ui->LoadingStop->setScaledContents(true);
   // ui->LoadingStop->setAttribute(Qt::WA_StyledBackground, true);
   // ui->Loading->setStyleSheet("background-color: brown");
    LoadingG->start();


    timerresume = new QTimer(this);
    connect(timerresume, SIGNAL(timeout()), this, SLOT(countdown()));
    timerresume->start(1000);
    count = 20;
    ui->Counter->show();
   // ui->StopResume.remo
    ui->StopResume->setText("Resume");
    ui->StopResume->setStyleSheet("border-image: url(:/new/prefix1/Picture/Resume1.png)");
    sendMessage("5^Stop");
  }
    else{
        //ui->StopResume->clear();
        ui->StopResume->setText("Stop");
        ui->LoadingStop->hide();
        ui->Counter->hide();
        ui->StopResume->setStyleSheet("border-image: url(:/new/prefix1/Picture/Stop1.png)");
        sendMessage("6^Resume");
    }
}

void GameServer::countdown()
{

    if (count > 0) {
            count--;
            ui->Counter->setText(QString::number(count));
    }
    else if(count==0){
        timerresume->stop();
        ui->StopResume->setText("Stop");
        ui->LoadingStop->hide();
        ui->Counter->hide();
        ui->StopResume->setStyleSheet("border-image: url(:/new/prefix1/Picture/Stop1.png)");
    }

    if (!timerresume->isActive()) {
        timerresume->start(1000);
    }

}

void GameServer::on_Exit_clicked()
{
   Menu*m=new Menu;
   this->close();
   m->show();
}
