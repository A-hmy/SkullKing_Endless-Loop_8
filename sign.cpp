#include "sign.h"
#include "mainwindow.h"
#include "ui_sign.h"
#include "signup.h"
#include "menu.h"
#include "QMessageBox"
#include "forgotpassword.h"
Sign::Sign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sign)
{
    ui->setupUi(this);
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
      QMessageBox::warning(this,"❗❗❗","Please complete all the lines 🙄");
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
          QMessageBox::warning(this,"❗❗❗","Username or Password is wrong 🙁");
      }
  }
}

