#include "changeinformation.h"
#include <QRegularExpressionValidator>
#include "global.h"
#include "player.h"
#include "mainwindow.h"
#include "menu.h"
#include "ui_changeinformation.h"
ChangeInformation::ChangeInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeInformation)
{

    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    QString phoneRegex = ("^09[0-9]\\d{8}$");
        QRegularExpressionValidator* validator = new QRegularExpressionValidator(QRegularExpression(phoneRegex), ui->phonenumber);
        ui->phonenumber->setValidator(validator);
    ui->name->setPlaceholderText(player->get_Name());
    ui->username->setPlaceholderText(player->get_UserName());
    ui->phonenumber->setPlaceholderText(player->get_PhoneNumber());
    ui->email->setPlaceholderText(player->get_Email());
    ui->password->setPlaceholderText(player->get_Password());
    ui->name->setFocus();
}

ChangeInformation::~ChangeInformation()
{
    delete ui;
}

void ChangeInformation::on_ok_clicked()
{

    player->Edit(ui->name->text(), ui->username->text(), ui->phonenumber->text(), ui->email->text(), ui->password->text());
    this->close();
    Menu *m=new Menu;
    m->show();
}


void ChangeInformation::on_cancle_clicked()
{
    this->close();
    Menu *m=new Menu;
    m->show();
}


void ChangeInformation::on_name_returnPressed()
{
    ui->username->setFocus();
}


void ChangeInformation::on_username_returnPressed()
{
    ui->phonenumber->setFocus();
}


void ChangeInformation::on_phonenumber_returnPressed()
{
    ui->email->setFocus();
}


void ChangeInformation::on_email_returnPressed()
{
    ui->password->setFocus();
}

