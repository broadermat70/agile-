#include "customerscreen.h"
#include "ui_customerscreen.h"


customerscreen::customerscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerscreen)
{
    int numUsers = 0;
    userType* allUsers = readUsers(numUsers);

    ui->setupUi(this);
    ui->loggedInUser->setText(ui->loggedInUser->text()+allUsers[findHasLoggedIn()].getFName()+" "+allUsers[findHasLoggedIn()].getLName());
}

customerscreen::~customerscreen()
{
    resetCurrentLogin();
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
