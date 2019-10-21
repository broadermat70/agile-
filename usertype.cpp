#include "usertype.h"
#include "QFile"
#include "QTextStream"
#include "QDebug"

userType::userType()
{

}

userType::userType(QString FName, QString LName)
{
    fName = FName;
    lName = LName;
}

QString userType:: getFName()
{
    return fName;
}

QString userType:: getLName()
{
    return lName;
}

void userType:: setFName(QString FName)
{
    fName = FName;
}

void userType:: setLName(QString LName)
{
    lName = LName;
}

void backupUsers(userType Users)
{
    QFile file("backupUsers.txt");
    if (!file.open(QIODevice::WriteOnly  | QIODevice::Text))
    {
        return;
    }
    QTextStream out(&file);

    out << Users.getUsername()<< endl
        << Users.getPassword() << endl
        << Users.getFName() << endl
        << Users.getLName() << endl;
    file.close();
}

userType* readUsers(int& numUsers)
{
    userType* users;
    int count = 0;
    QFile file("backupLogin.TXT");
    if(!file.open(QIODevice::ReadOnly  | QIODevice::Text))
    {
        qDebug() << "Could not Read File";
        return nullptr;
    }
    QTextStream in(&file);
    //while (!in.atEnd())
    {
        count++;
    }

    users = new userType[count];

    numUsers = 0;
    QString username;
    QString password;
    QString first;
    QString last;

    QTextStream input(&file);
    while(!input.atEnd())
    {
        username = input.readLine();
        password = input.readLine();
        first = input.readLine();
        last = input.readLine();
        users[numUsers].setUsername(username);
        users[numUsers].setPassword(password);
        users[numUsers].setFName(first);
        users[numUsers].setLName(last);
        numUsers++;
    }

    return users;
}

bool loginCheck(loginType logins, int& userPosition)
{
    qDebug() << "Starting LoginCheck";
    int count = 0;
    userPosition = -1;

    userType* allUsers = readUsers(count);

    for(int i = 0; i < count; i++)
    {
        qDebug() << "Starting forloop for loginCheck";
        qDebug() << logins.getPassword() << allUsers[i].getPassword();
        if(logins == allUsers[i])
        {
            userPosition = i;
            return true;
        }
        else if(i == count-1)
        {
            return false;
        }
    }
   /* QString username[10];
    QString password[10];
    int i = 0;

    QFile file("backupLogin.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

    }

    QTextStream in(&file);
    while (!in.atEnd() && i<10)
    {
        username[i] = in.readLine();
        password[i] = in.readLine();
        in.readLine();
        i++;
    }
    for(int j = 0; j < 10; j++)
    {
        if(logins.getUsername() == username[j] && logins.getPassword() == password[j])
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;*/
}
