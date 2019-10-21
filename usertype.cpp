#include "usertype.h"
#include "QFile"
#include "QTextStream"
#include "QDebug"

userType::userType()
{

}

userType::userType(loginType Key, QString FName, QString LName)
{
    key = Key;
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

loginType userType::getKey()
{
    return key;
}

QString userType::getUsername()
{
    return key.getUsername();
}

QString userType::getPassword()
{
    return key.getPassword();
}

void userType:: setFName(QString FName)
{
    fName = FName;
}

void userType:: setLName(QString LName)
{
    lName = LName;
}

void userType:: setKey(loginType Key)
{
    key = Key;
}

void userType::setKey(QString Username, QString Password)
{
    key.setUsername(Username);
    key.setPassword(Password);
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
        users[numUsers].setKey(username, password);
        users[numUsers].setFName(first);
        users[numUsers].setLName(last);
        numUsers++;
    }

    return users;
}
