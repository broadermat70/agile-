#ifndef ENVIRONMENTS_H
#define ENVIRONMENTS_H

#include <QDialog>

namespace Ui {
class environments;
}

class environments : public QDialog
{
    Q_OBJECT

public:
    explicit environments(QWidget *parent = nullptr);
    ~environments();

private:
    Ui::environments *ui;
};

#endif // ENVIRONMENTS_H
