
#include "serverorclient.h"
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

}


void ServerOrClient::on_client_clicked()
{

}

