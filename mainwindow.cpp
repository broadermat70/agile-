#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "guarantee.h"
#include "contact.h"
#include "environments.h"
#include "logintype.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_guaranteePolicyButton_clicked()
{
    guarantee guarantee;
    guarantee.setModal(true);
    guarantee.exec();
}

void MainWindow::on_contactInfoButton_clicked()
{
    contact contact;
    contact.setModal(true);
    contact.exec();
}

void MainWindow::on_supportedEnvironmentsButton_clicked()
{
    environments env;
    env.setModal(true);
    env.exec();
}
