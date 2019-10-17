#ifndef CARTSCREEN_H
#define CARTSCREEN_H

#include <QDialog>

namespace Ui {
class cartscreen;
}

class cartscreen : public QDialog
{
    Q_OBJECT

public:
    explicit cartscreen(QWidget *parent = nullptr);
    ~cartscreen();

private:
    Ui::cartscreen *ui;
};

#endif // CARTSCREEN_H
