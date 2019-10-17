#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "newuser.h"
#include "ui_newuser.h"
#include "guarantee.h"
#include "contact.h"
#include "environments.h"
#include "customerscreen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_guaranteePolicyButton_clicked();

    void on_contactInfoButton_clicked();

    void on_supportedEnvironmentsButton_clicked();

    void on_pushButton_Login_clicked();

    void on_pushButton_NewCustomer_clicked();

    void on_tempAccess_clicked();

private:
    Ui::MainWindow *ui;
    newuser *newUser;
    guarantee *Guarantee;
    contact *Contact;
    environments *env;
    customerscreen *cust;
};
#endif // MAINWINDOW_H
