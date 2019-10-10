#ifndef ADMINTYPE_H
#define ADMINTYPE_H
#include<QString>
#include "logintype.h"

class AdminType
{
public:
    AdminType();
    AdminType(QString initlName, QString initfName, loginType initKey);

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
