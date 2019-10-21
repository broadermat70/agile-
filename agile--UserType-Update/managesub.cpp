#include "managesub.h"
#include "ui_managesub.h"

managesub::managesub(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managesub)
{
    ui->setupUi(this);
}

managesub::~managesub()
{
    delete ui;
}
