#ifndef USERTYPE_H
#define USERTYPE_H
#include<QString>
#include "logintype.h"

class UserType
{
public:
    UserType();
    UserType(QString initlName, QString initfName, loginType initKey);

    QString getlName();
    QString getfName();

    void setlName(QString lName);
    void setfName(QString fName);

private:
   loginType key;
   QString lname;
   QString fname;

};

#endif // ADMINTYPE_H
