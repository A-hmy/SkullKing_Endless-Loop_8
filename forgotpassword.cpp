#include "forgotpassword.h"
#include <QRegularExpressionValidator>
#include "mainwindow.h"
#include "sign.h"
#include "ui_forgotpassword.h"
#include<QMessageBox>
ForgotPassword::ForgotPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForgotPassword)
{

    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    QString phoneRegex = ("^09[0-9]\\d{8}$");
    QRegularExpressionValidator* validator = new QRegularExpressionValidator(QRegularExpression(phoneRegex), ui->PhoneNumber);
    ui->PhoneNumber->setValidator(validator);
    ui->Error->setVisible(false);
    ui->New->setVisible(false);
    ui->NewPassword->setVisible(false);
}

ForgotPassword::~ForgotPassword()
{
    delete ui;
}

void ForgotPassword::on_PhoneNumber_returnPressed()
{
    if(ui->Username->text().isEmpty()){
        ui->Error->clear();
        ui->Error->setVisible(true);
        ui->Error->addItem("Enter your Username");
        ui->Error->setStyleSheet("background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(191, 152, 95, 255), stop:1 rgba(255, 255, 255, 255));color:red;border-radius:10px");
    }
    else{
        int flag=0;
         ui->Error->clear();
         for(auto x:Players){
            if(ui->PhoneNumber->text()==x->get_PhoneNumber()&&ui->Username->text()==x->get_UserName()){
                ui->Error->setVisible(true);
                ui->Error->addItem("Enter new password");
                ui->Error->setStyleSheet("background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(191, 152, 95, 255), stop:1 rgba(255, 255, 255, 255));color:green;border-radius:10px");
                ui->New->setVisible(true);
                ui->New->clear();
                ui->New->addItem("New password:");
                ui->New->setStyleSheet("background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(191, 152, 95, 255), stop:1 rgba(255, 255, 255, 255));color:black;border-radius:10px");
                ui->NewPassword->setVisible(true);
                ui->NewPassword->setFocus();
                ui->NewPassword->setStyleSheet("background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(191, 152, 95, 255), stop:1 rgba(255, 255, 255, 255));color:black;border-radius:10px");
                flag=1;
                break;
             }
         }
         if(flag==0){
             ui->Error->clear();
             ui->Error->setVisible(true);
             ui->Error->addItem("The phone number or username is incorrect");
             ui->Error->setStyleSheet("background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(191, 152, 95, 255), stop:1 rgba(255, 255, 255, 255));color:red;border-radius:10px");
             ui->PhoneNumber->setPlaceholderText("Phone number");
             ui->Username->setPlaceholderText("Username");
             ui->New->setVisible(false);
             ui->NewPassword->setVisible(false);
             }
         }
}


void ForgotPassword::on_Ok_clicked()
{
    if(ui->PhoneNumber->text().isEmpty()||ui->Username->text().isEmpty()){
        ui->Error->clear();
        ui->Error->setVisible(true);
        ui->Error->addItem("Enter Username and phone number");
        ui->Error->setStyleSheet("background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(191, 152, 95, 255), stop:1 rgba(255, 255, 255, 255));color:red;border-radius:10px");
    }
    else if(ui->NewPassword->text().isEmpty()){
        ui->Error->clear();
        ui->Error->setVisible(true);
        ui->Error->addItem("Enter new password");
        ui->Error->setStyleSheet("background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(191, 152, 95, 255), stop:1 rgba(255, 255, 255, 255));color:red;border-radius:10px");
    }
    else{
        for(auto x:Players){
           if(ui->PhoneNumber->text()==x->get_PhoneNumber()&&ui->Username->text()==x->get_UserName()){
               x->set_Password(ui->NewPassword->text());
               break;
           }
        }
        QFont Font("Segoe Script",10);
        QMessageBox* message=new QMessageBox;
        message->setFont(Font);
        message->setStyleSheet("background-color:rgb(112, 66, 33);;color:white");
        message->setText("Your password changed successfully :)");
        QPixmap pixmap(":/new/prefix1/Picture/QMessageBox icon.png");
        message->setIconPixmap(pixmap);
        message->setWindowFlags(Qt::FramelessWindowHint);
        message->show();
        message->exec();
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


void ForgotPassword::on_Username_returnPressed()
{
    ui->PhoneNumber->setFocus();
}

