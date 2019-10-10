#include "usertype.h"

UserType::UserType()
{

}

UserType::UserType(QString initlName, QString initfName, loginType initKey)
{
    fname = initfName;
    lname = initlName;
    key = initKey;

}

QString UserType:: getfName()
{
    return fname;
}

QString UserType:: getlName()
{
    return lname;
}

void UserType:: setfName(QString fName)
{
    fname = fName;
}

void UserType:: setlName(QString lName)
{
    lname = lName;
}
