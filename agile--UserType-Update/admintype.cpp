#include "admintype.h"

AdminType::AdminType()
{

}

AdminType::AdminType(QString initlName, QString initfName, loginType initKey)
{
    fname = initfName;
    lname = initlName;
    key = initKey;

}

QString AdminType:: getfName()
{
    return fname;
}

QString AdminType:: getlName()
{
    return lname;
}

void AdminType:: setfName(QString fName)
{
    fname = fName;
}

void AdminType:: setlName(QString lName)
{
    lname = lName;
}
