#include "sign.h"
#include "ui_sign.h"
#include "signup.h"
Sign::Sign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sign)
{
    ui->setupUi(this);
}

Sign::~Sign()
{
    delete ui;
}

void Sign::on_ForgotPassword_clicked()
{

}


void Sign::on_SignUp_clicked()
{
    this->close();
    Signup* signup=new Signup();
    signup->show();
}

