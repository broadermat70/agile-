#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QDesktopServices>

adminwindow::adminwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminwindow)
{
    ui->setupUi(this);
}

adminwindow::~adminwindow()
{
    delete ui;
}

void adminwindow::on_pushButton_4_clicked()
{
    this->close();
}

void adminwindow::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile("backupUsers.txt"));
}
