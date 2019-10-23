#ifndef MANAGESUB_H
#define MANAGESUB_H
#include "usertype.h"
#include <QDebug>
#include <QDialog>
#include <QString>
namespace Ui {
class managesub;
}

class managesub : public QDialog
{
    Q_OBJECT

public:
    explicit managesub(QWidget *parent = nullptr);
    ~managesub();

private:
    Ui::managesub *ui;
};

#endif // MANAGESUB_H
