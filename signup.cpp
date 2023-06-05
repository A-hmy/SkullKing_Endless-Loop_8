#include <QMessageBox>
#include "signup.h"
#include "ui_signup.h"
#include "player.h"
#include "mainwindow.h"
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
               QMessageBox:: warning(this," Sign up"," !! Please complete all the lines !!");
               ch=true;
    }
else
    {

    Player newuser(ui->name->text(), ui->username->text(), ui->phonenumber->text(), ui->email->text(), ui->password->text());
    Players.push_back(newuser);
    ui->ok->setText(" Done :)");
    ui->ok->setEnabled(false);
    if(ch==false){
        this->close();
    }
    MainWindow *m=new MainWindow();
    m->show();

    }
}


void Signup::on_cancle_clicked()
{
    MainWindow *m=new MainWindow();
    m->show();
    this->close();
}

