#include "cartscreen.h"
#include "ui_cartscreen.h"
#include "usertype.h"
#include <QDebug>

cartscreen::cartscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cartscreen)
{
    ui->setupUi(this);
}

cartscreen::~cartscreen()
{
    delete ui;
}

void cartscreen::on_pushButton_clicked()
{
    this->close();
}

void cartscreen::on_basicAdd_clicked()
{
    qDebug() << "Here\n";
    int count = 0;

    userType* allUsers = readUsers(count);
    qDebug() << "Here\n" << count;

    for(int i = 0; i < count; i++)
    { qDebug() << allUsers[i].getFName() <<  allUsers[i].getIsAdmin() <<allUsers[i].getHasLoggedIn() ;
        if(allUsers[i].getHasLoggedIn() == true)
        {

            qDebug() << "Stuck?\n";
           allUsers[i].customerProduct[allUsers[i].productsPurchased] = new productType;
           allUsers[i].customerProduct[allUsers[i].productsPurchased]->changeLevel("Basic");
           allUsers[i].customerProduct[allUsers[i].productsPurchased]->addDays(90);
            qDebug() << "Added\n";
        }
    }
}

void cartscreen::on_basicAdd_2_clicked()
{
//    userType users;
//    users.customerPlan.changeLevel("Basic");
//    users.customerPlan.addDays(180);
}

void cartscreen::on_basicAdd_3_clicked()
{
//    userType users;
//    users.customerPlan.changeLevel("Basic");
//    users.customerPlan.addDays(365);
}

void cartscreen::on_proAdd_clicked()
{
    //    user."productType".changeLevel("Professional");
    //    user."productType".addDays(90);
}

void cartscreen::on_proAdd_2_clicked()
{
    //    user."productType".changeLevel("Professional");
    //    user."productType".addDays(180);
}

void cartscreen::on_proAdd_3_clicked()
{
    //    user."productType".changeLevel("Professional");
    //    user."productType".addDays(365);
}

void cartscreen::on_premiiumAdd_clicked()
{
    //    user."productType".changeLevel("Premium");
    //    user."productType".addDays(90);
}

void cartscreen::on_premiiumAdd_2_clicked()
{
    //    user."productType".changeLevel("Premium");
    //    user."productType".addDays(180);
}

void cartscreen::on_premiiumAdd_3_clicked()
{
    //    user."productType".changeLevel("Premium");
    //    user."productType".addDays(365);
}
