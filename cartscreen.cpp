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
           allUsers[i].customerProduct = new productType; //why
           allUsers[i].customerProduct->changeLevel("Basic");
           allUsers[i].customerProduct->addDays(90);
            qDebug() << "Added\n";
        }
    }
}

void cartscreen::on_basicAdd_2_clicked()
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
           allUsers[i].customerProduct = new productType; //why
           allUsers[i].customerProduct->changeLevel("Basic");
           allUsers[i].customerProduct->addDays(180);
            qDebug() << "Added\n";
        }
    }
}

void cartscreen::on_basicAdd_3_clicked()
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
           allUsers[i].customerProduct = new productType; //why
           allUsers[i].customerProduct->changeLevel("Basic");
           allUsers[i].customerProduct->addDays(365);
            qDebug() << "Added\n";
        }
    }
}

void cartscreen::on_proAdd_clicked()
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
           allUsers[i].customerProduct = new productType; //why
           allUsers[i].customerProduct->changeLevel("Pro");
           allUsers[i].customerProduct->addDays(90);
            qDebug() << "Added\n";
        }
    }
}

void cartscreen::on_proAdd_2_clicked()
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
           allUsers[i].customerProduct = new productType; //why
           allUsers[i].customerProduct->changeLevel("Pro");
           allUsers[i].customerProduct->addDays(180);
            qDebug() << "Added\n";
        }
    }
}

void cartscreen::on_proAdd_3_clicked()
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
           allUsers[i].customerProduct = new productType; //why
           allUsers[i].customerProduct->changeLevel("Pro");
           allUsers[i].customerProduct->addDays(365);
            qDebug() << "Added\n";
        }
    }
}

void cartscreen::on_premiiumAdd_clicked()
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
           allUsers[i].customerProduct = new productType; //why
           allUsers[i].customerProduct->changeLevel("Premium");
           allUsers[i].customerProduct->addDays(90);
            qDebug() << "Added\n";
        }
    }
}

void cartscreen::on_premiiumAdd_2_clicked()
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
           allUsers[i].customerProduct = new productType; //why
           allUsers[i].customerProduct->changeLevel("Premium");
           allUsers[i].customerProduct->addDays(180);
            qDebug() << "Added\n";
        }
    }
}

void cartscreen::on_premiiumAdd_3_clicked()
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
           allUsers[i].customerProduct = new productType; //why
           allUsers[i].customerProduct->changeLevel("Premium");
           allUsers[i].customerProduct->addDays(365);
            qDebug() << "Added\n";
        }
    }
}
