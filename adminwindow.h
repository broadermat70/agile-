#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>

namespace Ui {
class adminwindow;
}

class adminwindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminwindow(QWidget *parent = nullptr);
    ~adminwindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::adminwindow *ui;
};

#endif // ADMINWINDOW_H
