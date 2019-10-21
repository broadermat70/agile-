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
    bool followsConditions = true;
    QString messageUser = "";
    QString messagePass = "";
    QString messageCPas = "";
    QString messagefNam = "";
    QString messagelNam = "";
    QString messageEmai = "";
    QString messagePhon = "";
    QString messageComp = "";

    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();
    QString confirmPassword = ui->lineEdit_ConfirmPassword->text();

    QString fName = ui->lineEdit_fName->text();
    QString lName = ui->lineEdit_lName->text();
    QString email = ui->lineEdit_customerEmail->text();
    QString phoneNumber = ui->lineEdit_phone->text();
    QString companyName = ui->lineEdit_company->text();

        if(username == "")
        {
            messageUser = "Username is empty!";
            followsConditions = false;
        }
        if(password == "")
        {
            messagePass = "Passwords is empty!";
            followsConditions = false;
        }
        if(confirmPassword == "")
        {
            messageCPas = "Confirm Password is empty!";
            followsConditions = false;
        }
        if(fName == "")
        {
            messagefNam = "First Name is empty!";
            followsConditions = false;
        }
        if(lName == "")
        {
            messagelNam = "Last Name is empty!";
            followsConditions = false;
        }
        if(email == "")
        {
            messageEmai = "email is empty!";
            followsConditions = false;
        }
        if(phoneNumber == "")
        {
            messagePhon = "Phone Number is empty!";
            followsConditions = false;
        }
        if(companyName == "")
        {
            messageComp = "Company Name is empty!";
            followsConditions = false;
        }
        if(!followsConditions)
        {
            QMessageBox::warning(this, "Error" , QString("%1\n%2\n%3\n%4\n%5\n%6\n%7\n%8").arg(messageUser).arg(messagePass).arg(messageCPas).arg(messagefNam).arg(messagelNam).arg(messageEmai).arg(messagePhon).arg(messageComp));
        }

    if (password == confirmPassword && followsConditions)
    {
        backupLogin(username, password);
        QMessageBox::information(this, "Signup", QString("Welcome %1 %2 to CyberSecurity!\nUsername is under %3").arg(fName).arg(lName).arg(username));
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Passwords do not match.");
    }
}

void newuser::on_cancel_clicked()
{
   this->close();
}
