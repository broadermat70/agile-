#include "usertype.h"
#include "QFile"
#include "QTextStream"
#include "QDebug"

userType::userType()
{
    fName = "unknown";
    lName = "unknown";
    isAdmin = false;
    hasLoggedIn = false;
}

userType::userType(QString FName, QString LName)
{
    fName = FName;
    lName = LName;
    isAdmin = false;
    hasLoggedIn = false;
}

QString userType:: getFName()
{
    return fName;
}

QString userType:: getLName()
{
    return lName;
}

bool userType:: getHasLoggedIn()
{
    return hasLoggedIn;
}

bool userType:: getIsAdmin()
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
            << Users[i].getIsAdmin() << endl << endl;
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
        << Users.getIsAdmin() << endl << endl;
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
    int i = 0;

    QTextStream input(&file);
    while(!input.atEnd())
    {
        username[i] = input.readLine();
        password[i] = input.readLine();
        first[i] = input.readLine();
        last[i] = input.readLine();
        hasLoggedIn[i] = input.readLine();
        isAdmin[i] = input.readLine();
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
        qDebug() << allUsers[i].getUsername() << allUsers[i].getPassword();
        if(logins == allUsers[i])
        {
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

void resetCurrentLogin()
{
    int count = 0;
    userType* allUsers = readUsers(count);
    for(int i = 0; i < count; i++)
    {
        allUsers[i].setHasLoggedIn(false);
    }
    backupUsers(allUsers, count);
}

QString stringCut(QString input, int width)
{
    QString final = "";
    for(int i = 0; i < width; i++)
    {
        if(i < input.length())
        {
           final += input[i];
        }
        else
        {
            final += " ";
        }
    }
    final += "    ";
    return final;
}

int findLargestString()
{
    int numUsers = 0;
    userType* allUsers = readUsers(numUsers);
    int maxLength = 0;
    for(int i = 0; i < numUsers; i++)
    {
        if(allUsers[i].getFName().length() > maxLength)
        {maxLength = allUsers[i].getFName().length();}
        if(allUsers[i].getLName().length() > maxLength)
        {maxLength = allUsers[i].getLName().length();}
        if(allUsers[i].getUsername().length() > maxLength)
        {maxLength = allUsers[i].getUsername().length();}
        if(allUsers[i].getPassword().length() > maxLength)
        {maxLength = allUsers[i].getPassword().length();}
        qDebug() << "Max set to " << maxLength;
    }
    return maxLength;
}

userType* sortfName()
{
    int numUsers = 0;
    userType* allUsers = readUsers(numUsers);
    userType tempUsers;

    for(int i = 0; i < numUsers; i++)
    {
        for(int j = i; j < numUsers; j++)
        {
            if(allUsers[i].getFName()[0] > allUsers[j].getFName()[0])
            {
                tempUsers = allUsers[j];
                allUsers[j] = allUsers[i];
                allUsers[i] = tempUsers;
            }
        }
    }
    return allUsers;
}

userType* sortlName()
{
    int numUsers = 0;
    userType* allUsers = readUsers(numUsers);
    userType tempUsers;

    for(int i = 0; i < numUsers; i++)
    {
        for(int j = i; j < numUsers; j++)
        {
            if(allUsers[i].getLName()[0] > allUsers[j].getLName()[0])
            {
                tempUsers = allUsers[j];
                allUsers[j] = allUsers[i];
                allUsers[i] = tempUsers;
            }
        }
    }
    return allUsers;
}
