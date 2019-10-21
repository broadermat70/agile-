#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "guarantee.h"
//#include "contact.h"
//#include "environments.h"
#include "logintype.h"
#include "usertype.h"
#include <QMessageBox>

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
//    guarantee guarantee;
//    guarantee.setModal(true);
//    guarantee.exec();
//      this->hide();
      Guarantee = new guarantee(this);
      Guarantee->show();
}

void MainWindow::on_contactInfoButton_clicked()
{
//    contact contact;
//    contact.setModal(true);
//    contact.exec();
//      this->hide();
      Contact = new contact(this);
      Contact->show();
}

void MainWindow::on_supportedEnvironmentsButton_clicked()
{
//    environments env;
//    env.setModal(true);
//    env.exec();
//      this->hide();
      env = new environments(this);
      env->show();
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    loginType currentLogin(username, password);

    if(loginCheck(currentLogin))
    {
        int count = 0;
        userType* allUsers = readUsers(count);
        if(allUsers[findHasLoggedIn()].getIsAdmin())
        {
            admin = new adminwindow(this);
            admin->show();
            this->hide();
        }
        else
        {
            cust = new customerscreen(this);
            cust->show();
            this->hide();
        }

    } else {

        QMessageBox::warning(this, "Login", "Username and password is not correct");

    }
}

void MainWindow::on_pushButton_NewCustomer_clicked()
{
    newuser newUser;
    newUser.setModal(true);
    newUser.exec();
}

void MainWindow::on_tempAccess_clicked()
{
    cust = new customerscreen(this);
    cust->show();
    this->hide();
}

void MainWindow::on_lineEdit_Password_returnPressed()
{
    MainWindow::on_pushButton_Login_clicked();
}
