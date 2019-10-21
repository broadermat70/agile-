#include "customerscreen.h"
#include "ui_customerscreen.h"


customerscreen::customerscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerscreen)
{
    ui->setupUi(this);
}

customerscreen::~customerscreen()
{
    int count = 0;
    userType* allUsers = readUsers(count);
    for(int i = 0; i < count; i++)
    {
        allUsers[i].setHasLoggedIn(false);
    }
    backupUsers(allUsers, count);
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
   cart = new cartscreen(this);
   cart->show();
}

void customerscreen::on_subscriptionButton_clicked()
{
    sub = new managesub(this);
    sub->show();
}
