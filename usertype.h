#ifndef USERTYPE_H
#define USERTYPE_H
#include "logintype.h"
#include<QString>


class userType
{
public:
    userType();
    userType(loginType, QString, QString);

    QString getFName();
    QString getLName();
    loginType getKey();
    QString getUsername();
    QString getPassword();

    void setFName(QString);
    void setLName(QString);
    void setKey(loginType);
    void setKey(QString, QString);

private:
   loginType key;
   QString lName;
   QString fName;
};

void backupUsers(userType);
userType* readUsers(int&);

#endif // USERTYPE_H
