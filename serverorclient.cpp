
#include "serverorclient.h"
#include "gameserver.h"
#include "ui_serverorclient.h"

ServerOrClient::ServerOrClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerOrClient)
{
    ui->setupUi(this);
}

ServerOrClient::~ServerOrClient()
{
    delete ui;
}

void ServerOrClient::on_server_clicked()
{
    MyQtServer=new QTcpServer;
    MyQtServer->listen(QHostAddress::Any,1234);
    //صفحه نمایش انتظار
    connect(MyQtServer,SIGNAL(newConnection()),this,SLOT(connect()));
}


void ServerOrClient::on_client_clicked()
{

}

void ServerOrClient::connecting()
{
    MyServerSocket=MyQtServer->nextPendingConnection();
    GameServer * m=new GameServer;
    m->show();
    this->hide();
    connect(MyServerSocket,SIGNAL(readyRead()),this,SLOT(received()));
    //connect(m,&GameServer::SendToServer,this,&srverOrclient::ReceivedFromeGameaserver);
    // ص گیم سرور برای این صفحه سیگنال ارسال میکند
    //میاد ارسال میکنه چه کارتی و چه حرکاتی انجام شده است
    // و از این صفحه اطلاعات برای کلاینت ارسال میشوند
    // و اطلاعات در همین صفحه از کلاینت دریافت میشود
}

