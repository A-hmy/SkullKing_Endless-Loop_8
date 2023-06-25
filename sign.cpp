#include "sign.h"
#include "mainwindow.h"
#include "ui_sign.h"
#include "signup.h"
#include "menu.h"
#include "QMessageBox"
#include "forgotpassword.h"
#include"function.h"
Sign::Sign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sign)
{
    ui->setupUi(this);
    QString FileName="Game";
    File_Read(FileName);
    setWindowFlags(Qt::FramelessWindowHint);
    QLabel *mylabel=ui->background;
    mylabel->lower();
}

Sign::~Sign()
{
    delete ui;
}

void Sign::on_ForgotPassword_clicked()
{
  ForgotPassword* pas=new ForgotPassword;
  pas->show();
  this->close();
}


void Sign::on_SignUp_clicked()
{
    this->close();
    Signup* signup=new Signup();
    signup->show();
}




void Sign::on_Login_clicked()
{
  if(ui->Username->text().isEmpty()||ui->Password->text().isEmpty()){
      QFont Font("Segoe Script",10);
      QMessageBox* message=new QMessageBox;
      message->setFont(Font);
      message->setStyleSheet("background-color:rgb(112, 66, 33);;color:white");
      message->setText("Please complete all the lines 🙄");
      QPixmap pixmap(":/new/prefix1/Picture/iconQMessageBox.png");
      message->setIconPixmap(pixmap);
      message->setWindowFlags(Qt::FramelessWindowHint);
      message->show();
      message->exec();
  }
  else{
      int flag=0;
      for(auto x: Players){
          if(x->get_UserName()==ui->Username->text()&&x->get_Password()==ui->Password->text()){
              //overlouding =
              player=x;
              flag=1;
              // bere safhe khod karbar
              Menu *m=new Menu();
              this->close();
              m->show();
              break;
          }
      }
      if(flag==0){
              QFont Font("Segoe Script",10);
              QMessageBox* message=new QMessageBox;
              message->setFont(Font);
              message->setStyleSheet("background-color:rgb(112, 66, 33);;color:white");
              message->setText("Username or Password is wrong 🙁");
              QPixmap pixmap(":/new/prefix1/Picture/iconQMessageBox.png");
              message->setIconPixmap(pixmap);
              message->setWindowFlags(Qt::FramelessWindowHint);
              message->show();
              message->exec();
              ui->Username->clear();
              ui->Username->setPlaceholderText("Username");
              ui->Username->setFocus();
              ui->Password->clear();
              ui->Password->setPlaceholderText("Password");
      }
  }
}


void Sign::on_Username_returnPressed()
{
    ui->Password->setFocus();
}

