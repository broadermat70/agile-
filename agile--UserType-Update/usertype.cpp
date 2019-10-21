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

bool userType:: getisLogin()
{
    return isLoggedIn;
}

void userType:: setisLogin(bool isLoggedin)
{
    isLoggedIn = isLoggedin;
}

void backupUsers(userType Users)
{
    QFile file("backupUsers.txt");
    if (!file.open(QIODevice::WriteOnly  | QIODevice::Append))
    {
        return;
    }
    QTextStream out(&file);

    out << Users.getUsername()<< endl
        << Users.getPassword() << endl
        << Users.getFName() << endl
        << Users.getLName() << endl << endl;
    file.close();
}

userType* readUsers(int& numUsers)
{
    userType* users;
    int count = 0;
    QFile file("backupUsers.TXT");
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

userType findLogginInUser()
{
    qDebug() << "Starting LoginUserCheck";
    int count = 0;

    userType* allUsers = readUsers(count);

    for(int i = 0; i < count; i++)
    {
        qDebug() << "Starting forloop for loginuserCheck";
//        qDebug() << logins.getPassword() << allUsers[i].getPassword();
        if(allUsers[i].getisLogin() == true)
        {
            return allUsers[i];
        }

}
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
            allUsers[i].setisLogin(true);
            return true;
        }
        else if(i == count-1)
        {
            return false;
        }
    }
}

