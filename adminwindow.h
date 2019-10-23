#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include "usertype.h"

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

    void on_pushButton_3_clicked();


    void on_saveButton_clicked();

    void on_textEdit_2_textChanged();

    void on_userNumInput_editingFinished();

    void on_sortfName_clicked();

    void on_sortlName_clicked();

    void on_sortDefault_clicked();

private:
    Ui::adminwindow *ui;
};

#endif // ADMINWINDOW_H
