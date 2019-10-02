#include "environments.h"
#include "ui_environments.h"

environments::environments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::environments)
{
    ui->setupUi(this);
}

environments::~environments()
{
    delete ui;
}
