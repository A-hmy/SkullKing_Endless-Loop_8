#include <QMessageBox>
#include <QRegularExpressionValidator>
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

    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[com]{2,4}$");
     QRegularExpressionMatch match = regex.match(ui->email->text());
      if (!match.hasMatch()) {
       ui->email->clear();
       ui->email->setStyleSheet("color:red");
       ui->email->setPlaceholderText("Email invalid input.");

      }
      else{
           ui->email->setStyleSheet("color:black");
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
              bool check= false;
              for (auto x : Players){
              if(ui->username->text()==x->get_UserName()){
                  check=true;
                  break;
              }
              }
      if(check==false){
          Player* newuser=new Player(ui->name->text(), ui->username->text(), ui->phonenumber->text(), ui->email->text(), ui->password->text());
          Players.push_back(newuser);
          QMessageBox::information(this," Sign up","  Done 🤩 ");
          if(ch==false){
              this->close();
          }
          Sign *m=new Sign();
          m->show();
      }
      else
          QMessageBox:: warning(this,"❗❗❗","This Username exist . Enter again Username ");

          }
      }
}


void Signup::on_cancle_clicked()
{
    Sign *m=new Sign();
    m->show();
    this->close();
}

