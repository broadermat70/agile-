#include "customerscreen.h"
#include "ui_customerscreen.h"
#include "cartscreen.h"

customerscreen::customerscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerscreen)
{
    ui->setupUi(this);
}

customerscreen::~customerscreen()
{
    delete ui;
}


void customerscreen::on_envButton_clicked()
{
    env = new environments(this);
    env->show();
}

void customerscreen::on_guaranteeButton_clicked()
{
    Guarantee = new guarantee(this);
    Guarantee->show();
}

void customerscreen::on_contactButton_clicked()
{
    Contact = new contact(this);
    Contact->show();
}

void customerscreen::on_purchaseButton_clicked()
{
      cartscreen cart;
      cart.setModal(true);
      cart.exec();
}
