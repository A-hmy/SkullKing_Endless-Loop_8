#include <QMessageBox>
#include <QRegularExpressionValidator>
#include "function.h"
#include "signup.h"
#include "sign.h"
#include "ui_signup.h"
#include "player.h"
#include "mainwindow.h"
#include "global.h"
// check kardan tekrari nabodan ramz ....
Signup::Signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    QString phoneRegex = ("^09[0-9]\\d{8}$");
    QRegularExpressionValidator* validator = new QRegularExpressionValidator(QRegularExpression(phoneRegex), ui->phonenumber);
    ui->phonenumber->setValidator(validator);

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
        QFont Font("Segoe Script",10);
        QMessageBox* message=new QMessageBox;
        message->setFont(Font);
        message->setStyleSheet("background-color:rgb(112, 66, 33);;color:white");
        message->setText("Please complete all the lines 🙄");
        QPixmap pixmap(":/new/prefix1/Picture/iconQMessageBox.png");
        message->setIconPixmap(pixmap);
        message->setWindowFlags(Qt::FramelessWindowHint);
        message->show();
        ch=true;
    }

      else{
          QRegularExpression regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[com]{2,4}$");
             QRegularExpressionMatch match = regex.match(ui->email->text());
              if (!match.hasMatch()) {
               ui->email->clear();
                ui->email->setStyleSheet("background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(191, 152, 95, 255), stop:1 rgba(255, 255, 255, 255));color:red;border-radius:10px");
               ui->email->setPlaceholderText("Email invalid input.");
               ui->email->setFocus();
              }
      else
          {
              bool check= false;
              for (auto x : Players){
              if(ui->username->text()==x->get_UserName()){
                  check=true;
                  break;
              }
              }
      if(check==false){
          QString FileName="Game";
          Player* newuser=new Player(ui->name->text(), ui->username->text(), ui->phonenumber->text(), ui->email->text(), ui->password->text());
          Players.push_back(newuser);
          for(auto it=Players.begin();it!=Players.end();it++){
              File_WriteOnly(FileName,**it);
          }
          QFont Font("Segoe Script",15);
          QMessageBox* message=new QMessageBox;
          message->setFont(Font);
          message->setStyleSheet("background-color:rgb(112, 66, 33);;color:white");
          message->setText("Done :)");
          QPixmap pixmap(":/new/prefix1/Picture/QMessageBox icon.png");
          message->setIconPixmap(pixmap);
          message->setWindowFlags(Qt::FramelessWindowHint);
          message->show();
          message->exec();
          if(ch==false){
              this->close();
          }
          Sign *m=new Sign();
          m->show();
      }
      else{
          QFont Font("Segoe Script",10);
          QMessageBox* message=new QMessageBox;
          message->setFont(Font);
          message->setStyleSheet("background-color:rgb(112, 66, 33);;color:white");
          message->setText("This username already exists.\n Please rename your username.");
          QPixmap pixmap(":/new/prefix1/Picture/iconQMessageBox.png");
          message->setIconPixmap(pixmap);
          message->setWindowFlags(Qt::FramelessWindowHint);
          message->show();
          message->exec();
          ui->username->clear();
          ui->username->setPlaceholderText("Username");
          ui->username->setFocus();
      }

          }
      }
}


void Signup::on_cancle_clicked()
{
    Sign *m=new Sign();
    m->show();
    this->close();
}



void Signup::on_email_textChanged(const QString &arg1)
{
    ui->email->setStyleSheet("background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(191, 152, 95, 255), stop:1 rgba(255, 255, 255, 255));color:black;border-radius:10px");
}


void Signup::on_name_returnPressed()
{
    ui->username->setFocus();
}


void Signup::on_username_returnPressed()
{
    ui->password->setFocus();
}


void Signup::on_password_returnPressed()
{
    ui->phonenumber->setFocus();
}


void Signup::on_phonenumber_returnPressed()
{
    ui->email->setFocus();
}



