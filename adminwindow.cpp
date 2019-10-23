#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "QDebug"
#include <QDesktopServices>

adminwindow::adminwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminwindow)
{
    int numUsers = 0;
    userType* allUsers = readUsers(numUsers);

    qDebug() << "Test 1";

    int maxLength = findLargestString();

    ui->setupUi(this);
    ui->loggedInName->setText(ui->loggedInName->text()+allUsers[findHasLoggedIn()].getFName());

    ui->userEdit->setText(ui->userEdit->toPlainText()+stringCut("    Name", maxLength)+stringCut("Last", maxLength)+stringCut("Username", maxLength)+stringCut("Password", maxLength)+"\n");

    QString intToQString = "";
    for(int i = 0; i < numUsers; i++)
    {
        intToQString = QString::number(i+1);
         ui->userEdit->setText(ui->userEdit->toPlainText()+intToQString+") "+stringCut(allUsers[i].getFName(), maxLength)+stringCut(allUsers[i].getLName(), maxLength)+stringCut(allUsers[i].getUsername(), maxLength)+stringCut(allUsers[i].getPassword(), maxLength)+"\n");
    }


}

adminwindow::~adminwindow()
{
    resetCurrentLogin();
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

void adminwindow::on_pushButton_3_clicked()
{

}


void adminwindow::on_saveButton_clicked()
{
    int userChosen = ui->userNumInput->text().toInt()-1;
    int numUsers = 0;
    userType* allUsers = readUsers(numUsers);
    allUsers[userChosen].setFName(ui->changefName->text());
    allUsers[userChosen].setLName(ui->changelName->text());
    allUsers[userChosen].setUsername(ui->changeUsername->text());
    allUsers[userChosen].setPassword(ui->changePassword->text());
    backupUsers(allUsers, numUsers);

    int maxLength = findLargestString();
    QString intToQString = "";

    ui->userEdit->setText("");
    ui->userEdit->setText(ui->userEdit->toPlainText()+stringCut("    Name", maxLength)+stringCut("Last", maxLength)+stringCut("Username", maxLength)+stringCut("Password", maxLength)+"\n");
    for(int i = 0; i < numUsers; i++)
    {
        intToQString = QString::number(i+1);
         ui->userEdit->setText(ui->userEdit->toPlainText()+intToQString+") "+stringCut(allUsers[i].getFName(), maxLength)+stringCut(allUsers[i].getLName(), maxLength)+stringCut(allUsers[i].getUsername(), maxLength)+stringCut(allUsers[i].getPassword(), maxLength)+"\n");
    }
}

void adminwindow::on_textEdit_2_textChanged()
{

}

void adminwindow::on_userNumInput_editingFinished()
{
    int userChosen = ui->userNumInput->text().toInt()-1;
    qDebug() << "Changing userselection";
    int numUsers = 0;
    userType* allUsers = readUsers(numUsers);
    ui->changefName->setText(allUsers[userChosen].getFName());
    ui->changelName->setText(allUsers[userChosen].getLName());
    ui->changeUsername->setText(allUsers[userChosen].getUsername());
    ui->changePassword->setText(allUsers[userChosen].getPassword());
}


void adminwindow::on_sortfName_clicked()
{
    int numUsers = 0;
    int maxLength = findLargestString();
    QString intToQString = "";
    userType* allUsers = readUsers(numUsers);
    allUsers = sortfName();
    ui->userEdit->setText("");
    ui->userEdit->setText(ui->userEdit->toPlainText()+stringCut("    Name", maxLength)+stringCut("Last", maxLength)+stringCut("Username", maxLength)+stringCut("Password", maxLength)+"\n");
    for(int i = 0; i < numUsers; i++)
    {
        intToQString = QString::number(i+1);
         ui->userEdit->setText(ui->userEdit->toPlainText()+intToQString+") "+stringCut(allUsers[i].getFName(), maxLength)+stringCut(allUsers[i].getLName(), maxLength)+stringCut(allUsers[i].getUsername(), maxLength)+stringCut(allUsers[i].getPassword(), maxLength)+"\n");
    }
}

void adminwindow::on_sortlName_clicked()
{
    int numUsers = 0;
    int maxLength = findLargestString();
    QString intToQString = "";
    userType* allUsers = readUsers(numUsers);
    allUsers = sortlName();
    ui->userEdit->setText("");
    ui->userEdit->setText(ui->userEdit->toPlainText()+stringCut("    Name", maxLength)+stringCut("Last", maxLength)+stringCut("Username", maxLength)+stringCut("Password", maxLength)+"\n");
    for(int i = 0; i < numUsers; i++)
    {
        intToQString = QString::number(i+1);
         ui->userEdit->setText(ui->userEdit->toPlainText()+intToQString+") "+stringCut(allUsers[i].getFName(), maxLength)+stringCut(allUsers[i].getLName(), maxLength)+stringCut(allUsers[i].getUsername(), maxLength)+stringCut(allUsers[i].getPassword(), maxLength)+"\n");
    }
}

void adminwindow::on_sortDefault_clicked()
{
    int numUsers = 0;
    int maxLength = findLargestString();
    QString intToQString = "";
    userType* allUsers = readUsers(numUsers);
    ui->userEdit->setText("");
    ui->userEdit->setText(ui->userEdit->toPlainText()+stringCut("    Name", maxLength)+stringCut("Last", maxLength)+stringCut("Username", maxLength)+stringCut("Password", maxLength)+"\n");
    for(int i = 0; i < numUsers; i++)
    {
        intToQString = QString::number(i+1);
         ui->userEdit->setText(ui->userEdit->toPlainText()+intToQString+") "+stringCut(allUsers[i].getFName(), maxLength)+stringCut(allUsers[i].getLName(), maxLength)+stringCut(allUsers[i].getUsername(), maxLength)+stringCut(allUsers[i].getPassword(), maxLength)+"\n");
    }
}
