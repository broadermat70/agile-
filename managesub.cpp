#include "managesub.h"
#include "ui_managesub.h"

managesub::managesub(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managesub)
{
    ui->setupUi(this);

    int count = 0;
    int dayInt = 0;
    QString subString;

    userType* allUsers = readUsers(count);

    for(int i = 0; i < count; i++)
    { qDebug() << allUsers[i].getFName() <<  allUsers[i].getIsAdmin() <<allUsers[i].getHasLoggedIn() ;
        if(allUsers[i].getHasLoggedIn() == true)
        {
            dayInt = allUsers[i].customerProduct->getDaysLeft();
            subString = allUsers[i].customerProduct->getLevel();
        }
    }
    QString dayString = QString::number(dayInt);

    ui->displayLevel->setText(subString);
    ui->displayDays->setText(dayString);

}

managesub::~managesub()
{
    delete ui;
}
