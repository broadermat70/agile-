#include <QMessageBox>
#include "newuser.h"
#include "ui_newuser.h"
#include "logintype.h"

newuser::newuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newuser)
{
    ui->setupUi(this);
}

newuser::~newuser()
{
    delete ui;
}

//void newuser::on_buttonBox_rejected()
//{
//    this->close();
//}

void newuser::on_submitUser_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();
    QString confirmPassword = ui->lineEdit_ConfirmPassword->text();

//    QString fName = ui->lineEdit_firstName->text();
//    QString lName = ui->lineEdit_lastName->text();
//    QString email = ui->lineEdit_customerEmail->text();
//    QString phoneNumber = ui->lineEdit_phone->text();
//    QString companyName = ui->lineEdit_company->text();


    if (password == confirmPassword)
    {
        backupLogin(username, password);

    } else {

        QMessageBox::warning(this, "Error", "Passwords do not match.");

    }


}

void newuser::on_cancel_clicked()
{
   this->close();
}
