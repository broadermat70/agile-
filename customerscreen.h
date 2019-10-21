#ifndef CUSTOMERSCREEN_H
#define CUSTOMERSCREEN_H

#include <QDialog>
#include "guarantee.h"
#include "contact.h"
#include "environments.h"
#include "cartscreen.h"
#include "managesub.h"
#include "usertype.h"

namespace Ui {
class customerscreen;
}

class customerscreen : public QDialog
{
    Q_OBJECT

public:
    explicit customerscreen(QWidget *parent = nullptr);
    ~customerscreen();

private slots:
    void on_envButton_clicked();

    void on_guaranteeButton_clicked();

    void on_contactButton_clicked();

    void on_purchaseButton_clicked();

    void on_subscriptionButton_clicked();

private:
    Ui::customerscreen *ui;
    guarantee *Guarantee;
    contact *Contact;
    environments *env;
    cartscreen *cart;
    managesub *sub;
};

#endif // CUSTOMERSCREEN_H
