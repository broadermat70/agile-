#include "cartscreen.h"
#include "ui_cartscreen.h"

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
