#include "gameserver.h"
#include "qtcpsocket.h"
#include "ui_gameserver.h"
#include "function.h"
#include"mainwindow.h"
#include"QTcpSocket"
GameServer::GameServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameServer)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//remove tool bar.
    MyClientSocket = new QTcpSocket(this);
    //connect(this, &GameServer::newMessage, this, &GameServer::displayMessage);
    //connect(MyClientSocket, &QTcpSocket::readyRead, this, &GameServer::readSocket);
    QAbstractSocket::connect(MyClientSocket, &QTcpSocket::disconnected, this, &GameServer::discardSocket);
    //connect(MyClientSocket, &QAbstractSocket::errorOccurred, this, &GameServer::displayError);
    QAbstractSocket::connect(MyClientSocket,SIGNAL(connected()),this,SLOT(connect()));
    //Loading Gif!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!??????????????????????????????????????
    MyClientSocket->connectToHost(Ipserver,1204);

}

GameServer::~GameServer()
{
    if(MyClientSocket->isOpen())
        MyClientSocket->close();
    delete ui;
}

void GameServer::connect()
{
    if(MyClientSocket->state() == QAbstractSocket::ConnectedState){
        //hide loading**********
    }
}

void GameServer::discardSocket()
{
    //loading gif**************
    //MyClientSocket->deleteLater();
    //MyClientSocket=nullptr;
    MyClientSocket->connectToHost(Ipserver,1204);
    QAbstractSocket::connect(MyClientSocket,SIGNAL(connected()),this,SLOT(connect()));
}


/*void GameServer::readSocket()
{
    QByteArray buffer;

    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_5_15);

    socketStream.startTransaction();
    socketStream >> buffer;

    if(!socketStream.commitTransaction())
    {
        QString message = QString("%1 :: Waiting for more data to come..").arg(socket->socketDescriptor());
        emit newMessage(message);
        return;
    }

    QString header = buffer.mid(0,128);
    QString fileType = header.split(",")[0].split(":")[1];

    buffer = buffer.mid(128);

    if(fileType=="attachment"){
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
        }
    }else if(fileType=="message"){
        QString message = QString("%1 :: %2").arg(socket->socketDescriptor()).arg(QString::fromStdString(buffer.toStdString()));
        emit newMessage(message);
    }
}
*/




void GameServer::on_Ok_clicked()
{
    if(ui->NumberOfPredict->text().isEmpty()){
      ui->NumberOfPredict->setPlaceholderText("❗❗❗❗");
        }
    else{
       NumberOfServer=ui->NumberOfPredict->text().toInt();
       // daryaft tedad bord client(NumberOfClient=ui.......)
       ui->NumberOfPredict->setVisible(false);
       ui->Ok->setVisible(false);
       ui->lablePredict->setVisible(false);
        }


}


void GameServer::Set(Board _board)
{
    PlayerCard_C=_board.get_player2();
    //PlayerCard_S=_board.get_player1();
    NumberOfClient=_board.get_NumberOfset_C();//This variable should not be changed
}




void GameServer::PlayingGame()
{
   for(int NumberOfRound=0;NumberOfRound!=7;NumberOfRound++){
       //dealing
       Dealing(NumberOfRound);

   }

}


void GameServer::on_card_1_clicked()
{
    if(ui->NumberOfPredict->isVisible()){
       emit send(1);
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






