#include "menu.h"
#include "changeinformation.h"
#include "sign.h"
#include "ui_menu.h"
#include"gameserver.h"
Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_Changeinformation_2_clicked()
{
    this->close();
    ChangeInformation*m=new ChangeInformation();
    m->show();
}


void Menu::on_Logout_2_clicked()
{
    this->close();
    Sign *m=new Sign;
    m->show();
}


void Menu::on_Start_2_clicked()
{
    // server_client
    //if(server)
    this->close();
    GameServer*g=new GameServer;
    g->show();
}

