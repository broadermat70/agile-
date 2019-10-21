#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "guarantee.h"
//#include "contact.h"
//#include "environments.h"
#include "logintype.h"
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

       // QMessageBox::information(this, "Login", "Username and password is correct");
        cust = new customerscreen(this);
        cust->show();
        this->hide();

    } else {

        QMessageBox::warning(this, "Login", "Username and password is not correct");

    }
}

void MainWindow::on_pushButton_NewCustomer_clicked()
{
    newuser newUser;
    newUser.setModal(true);
    newUser.exec();

//      this->hide();
//      newUser = new newuser(this);

//    QString username = ui->lineEdit_Username->text();
//    QString password = ui->lineEdit_Password->text();
//    backupLogin(username, password);
//    QMessageBox::information(this, "Signup", QString("You have successfully signed up\nUsername: %1\nPassword: %2").arg(username).arg(password));
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
