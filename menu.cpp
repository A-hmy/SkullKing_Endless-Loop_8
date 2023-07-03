#include "menu.h"
#include "changeinformation.h"
#include "sign.h"
#include "ui_menu.h"
#include"gameserver.h"
#include"serverorclient.h"
#include "history.h"
#include"global.h"
Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
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
    if(player->get_Coin()<50){
        //error
    }
    else{
    player->set_Coin(player->get_Coin()-50);
    ServerOrClient * s=new ServerOrClient;
    this->close();
    s->show();}
}


void Menu::on_History_2_clicked()
{
    History *h=new History;
    this->close();
    h->show();

}

