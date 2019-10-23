#include "usertype.h"
#include "QFile"
#include "QTextStream"
#include "QDebug"

userType::userType()
{
    isAdmin = false;
    hasLoggedIn = false;
    customerProduct = nullptr;
}

userType::userType(QString FName, QString LName)
{
    fName = FName;
    lName = LName;
    isAdmin = false;
    hasLoggedIn = false;
    customerProduct = new productType();
    customerProduct->changeLevel("NONE");
    customerProduct->changeDays(0);
}

userType::userType(const userType &obj)
{
    fName = obj.getFName();
    lName = obj.getLName();
    isAdmin = obj.getIsAdmin();
    hasLoggedIn = obj.getHasLoggedIn();
    customerProduct = new productType();
    customerProduct->changeLevel(obj.customerProduct->getLevel());
    customerProduct->changeDays(obj.customerProduct->getDaysLeft());
}

QString userType:: getFName() const
{
    return fName;
}

QString userType:: getLName() const
{
    return lName;
}

bool userType:: getHasLoggedIn() const
{
    return hasLoggedIn;
}

bool userType:: getIsAdmin() const
{
    return isAdmin;
}

void userType:: setFName(QString FName)
{
    fName = FName;
}

void userType:: setLName(QString LName)
{
    lName = LName;
}

void userType:: setHasLoggedIn(QString HasLoggedIn)
{
    if(HasLoggedIn == "1")
    {
        hasLoggedIn = true;
    }
    else
    {
        hasLoggedIn = false;
    }
}

void userType:: setHasLoggedIn(bool HasLoggedIn)
{
    hasLoggedIn = HasLoggedIn;
}

void userType:: setIsAdmin(bool IsAdmin)
{
    isAdmin = IsAdmin;
}

void userType:: setIsAdmin(QString IsAdmin)
{
    if(IsAdmin == "1")
    {
        isAdmin = true;
    }
    else
    {
        isAdmin = false;
    }}

void backupUsers(userType* Users, int numUsers)
{
    QFile file("backupUsers.txt");
    if (!file.open(QIODevice::WriteOnly  | QIODevice::Text))
    {
        return;
    }
    QTextStream out(&file);

    for(int i = 0; i < numUsers; i++)
    {
        out << Users[i].getUsername()<< endl
            << Users[i].getPassword() << endl
            << Users[i].getFName() << endl
            << Users[i].getLName() << endl
            << Users[i].getHasLoggedIn() << endl
            << Users[i].getIsAdmin() << endl
            << Users[i].customerProduct->getLevel() << endl
            << Users[i].customerProduct->getDaysLeft() << endl << endl;
    }

    file.close();
}

void addUserToText(userType Users)
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
        << Users.getLName() << endl
        << Users.getHasLoggedIn() << endl
        << Users.getIsAdmin() << endl
        << Users.customerProduct->getLevel() << endl
        << Users.customerProduct->getDaysLeft() << endl << endl;
    file.close();
}

userType* readUsers(int& numUsers)
{
    userType* users;
    QFile file("backupUsers.TXT");
    if(!file.open(QIODevice::ReadOnly  | QIODevice::Text))
    {
        qDebug() << "Could not Read File";
        return nullptr;
    }
    QTextStream in(&file);

    numUsers = 0;
    QString username[50];
    QString password[50];
    QString first[50];
    QString last[50];
    QString hasLoggedIn[50];
    QString isAdmin[50];
    QString productLevel[50];
    QString daysLeft[50];
    int i = 0;

    QTextStream input(&file);
    while(!input.atEnd())
    {
        qDebug() << "Inside While";
        username[i] = input.readLine();
        password[i] = input.readLine();
        first[i] = input.readLine();
        last[i] = input.readLine();
        hasLoggedIn[i] = input.readLine();
        isAdmin[i] = input.readLine();
        productLevel[i] = input.readLine();
        daysLeft[i] = input.readLine();
        input.readLine();
        numUsers++;
        i++;
     }
    users = new userType[numUsers];
    for(int i = 0; i<numUsers; i++)
    {
        users[i].setUsername(username[i]);
        users[i].setPassword(password[i]);
        users[i].setFName(first[i]);
        users[i].setLName(last[i]);
        users[i].setHasLoggedIn(hasLoggedIn[i]);
        users[i].setIsAdmin(isAdmin[i]);
        users[i].customerProduct->changeLevel(productLevel[i]);
        int dayLeft = daysLeft[i].toInt();
        users[i].customerProduct->changeDays(dayLeft);
    }

    return users;
    delete[] users;
}

int findHasLoggedIn()
{
    qDebug() << "Starting findHasLoggedIn";
    int count = 0;

    userType* allUsers = readUsers(count);

    for(int i = 0; i < count; i++)
    {
        if(allUsers[i].getHasLoggedIn() == true)
        {
            return i;
        }
    }
    return -1;
}

bool loginCheck(loginType logins)
{
    qDebug() << "Starting LoginCheck";
    int count = 0;

    userType* allUsers = readUsers(count);

    for(int i = 0; i < count; i++)
    {
        qDebug() << "Starting forloop for loginCheck";
        qDebug() << allUsers[i].getUsername() << allUsers[i].getPassword();
        if(logins == allUsers[i])
        {
            qDebug() << "setting";
            allUsers[i].setHasLoggedIn(true);
            backupUsers(allUsers, count);
            return true;
        }
        else if(i == count-1)
        {
            return false;
        }
    }
    return false;
}
