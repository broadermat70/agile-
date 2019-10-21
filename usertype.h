#ifndef USERTYPE_H
#define USERTYPE_H
#include "logintype.h"
#include<QString>


class userType: public loginType
{
public:
    userType();
    userType(QString, QString);

    QString getFName();
    QString getLName();

    void setFName(QString);
    void setLName(QString);

private:
   QString lName;
   QString fName;
};

void backupUsers(userType);
userType* readUsers(int&);
bool loginCheck(loginType, int&);

#endif // USERTYPE_H
