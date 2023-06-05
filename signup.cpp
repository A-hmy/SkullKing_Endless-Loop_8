#include <QMessageBox>
#include "signup.h"
#include "sign.h"
#include "ui_signup.h"
#include "player.h"
#include "mainwindow.h"
// check kardan tekrari nabodan ramz ....
Signup::Signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_ok_clicked()
{
    bool ch=false;
    if(ui->username->text().isEmpty()||ui->password->text().isEmpty()
            ||ui->name->text().isEmpty()||ui->email->text().isEmpty()||
            ui->phonenumber->text().isEmpty())
    {
               QMessageBox:: warning(this,"❗❗❗","Please complete all the lines 🙄");
               ch=true;
    }
else
    {

    Player* newuser=new Player(ui->name->text(), ui->username->text(), ui->phonenumber->text(), ui->email->text(), ui->password->text());
    Players.push_back(newuser);
    QMessageBox::information(this," Sign up","  Done 🤩 ");
    if(ch==false){
        this->close();
    }
    Sign *m=new Sign();
    m->show();

    }
}


void Signup::on_cancle_clicked()
{
    Sign *m=new Sign();
    m->show();
    this->close();
}

