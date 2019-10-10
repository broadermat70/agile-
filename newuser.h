#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>

namespace Ui {
class newuser;
}

class newuser : public QDialog
{
    Q_OBJECT

public:
    explicit newuser(QWidget *parent = nullptr);
    ~newuser();

private slots:
    void on_buttonBox_rejected();

    void on_pushButton_clicked();

    void on_submitUser_clicked();

    void on_cancel_clicked();

private:
    Ui::newuser *ui;
};

#endif // NEWUSER_H
