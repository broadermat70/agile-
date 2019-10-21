#ifndef CARTSCREEN_H
#define CARTSCREEN_H

#include <QDialog>

//#include "usertype.h"
#include "productType.h"

namespace Ui {
class cartscreen;
}

class cartscreen : public QDialog
{
    Q_OBJECT

public:
    explicit cartscreen(QWidget *parent = nullptr);
    ~cartscreen();

private slots:
    void on_pushButton_clicked();

    void on_basicAdd_clicked();

    void on_basicAdd_2_clicked();

    void on_basicAdd_3_clicked();

    void on_proAdd_clicked();

    void on_proAdd_2_clicked();

    void on_proAdd_3_clicked();

    void on_premiiumAdd_clicked();

    void on_premiiumAdd_2_clicked();

    void on_premiiumAdd_3_clicked();

private:
    Ui::cartscreen *ui;
};

#endif // CARTSCREEN_H
