#include "managesub.h"
#include "ui_managesub.h"

managesub::managesub(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managesub)
{
    ui->setupUi(this);

    int dayInt = 0; //*INSERT DAYS LEFT GETTER*;
    QString dayString = QString::number(dayInt);

    ui->displayLevel->setText("*INSERT TEXT GETTER HERE*");
    ui->displayDays->setText(dayString);

}

managesub::~managesub()
{
    delete ui;
}
