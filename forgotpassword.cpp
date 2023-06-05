#include "forgotpassword.h"
#include "mainwindow.h"
#include "sign.h"
#include "ui_forgotpassword.h"
#include<QMessageBox>
ForgotPassword::ForgotPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForgotPassword)
{
    ui->setupUi(this);
}

ForgotPassword::~ForgotPassword()
{
    delete ui;
}

void ForgotPassword::on_PhoneNumber_returnPressed()
{
    if(ui->Username->text().isEmpty()){
        ui->Error->clear();
        ui->Error->addItem("Enter your Username");
        ui->Error->setStyleSheet("color:red");
    }
    else{
        int flag=0;
         ui->Error->clear();
         for(auto x:Players){
            if(ui->PhoneNumber->text()==x->get_PhoneNumber()&&ui->Username->text()==x->get_UserName()){
                ui->Error->addItem("Enter new password");
                ui->Error->setStyleSheet("color:green");
                ui->New->clear();
                ui->New->addItem("New password:");
                ui->NewPassword->setStyleSheet("background-color:white");
                flag=1;
                break;
             }
         }
         if(flag==0){
             ui->Error->clear();
             ui->Error->addItem("The phone number or username is incorrect");
             ui->Error->setStyleSheet("color:red");
             ui->PhoneNumber->setPlaceholderText("Phone number");
             ui->Username->setPlaceholderText("Username");
             }
         }
}


void ForgotPassword::on_Ok_clicked()
{
    if(ui->PhoneNumber->text().isEmpty()||ui->Username->text().isEmpty()){
        ui->Error->clear();
        ui->Error->addItem("Enter Username and phone number");
        ui->Error->setStyleSheet("color:red");
    }
    else if(ui->NewPassword->text().isEmpty()){
        ui->Error->clear();
        ui->Error->addItem("Enter new password");
        ui->Error->setStyleSheet("color:red");
    }
    else{
        for(auto x:Players){
           if(ui->PhoneNumber->text()==x->get_PhoneNumber()&&ui->Username->text()==x->get_UserName()){
               x->set_Password(ui->NewPassword->text());
               break;
           }
        }
        QMessageBox::information(this,"✅","Your password changed successfully");
        this->close();
        Sign *m=new Sign;
        m->show();
    }
}


void ForgotPassword::on_Cancel_clicked()
{
    Sign *m=new Sign;
    m->show();
    this->close();
}

