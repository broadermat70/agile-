#include "mainwindow.h"
#include "usertype.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int count = 0;
    userType* allUsers = readUsers(count);
    for(int i = 0; i < count; i++)
    {
        allUsers[i].setHasLoggedIn(false);
    }
    backupUsers(allUsers, count);

    return a.exec();
}
