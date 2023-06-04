#include "sign.h"
#include "ui_sign.h"

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
