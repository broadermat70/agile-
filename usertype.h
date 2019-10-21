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
    bool getHasLoggedIn();

    void setFName(QString);
    void setLName(QString);
    void setHasLoggedIn(bool);
    void setHasLoggedIn(QString );


private:
   QString lName;
   QString fName;
   bool hasLoggedIn = false;
};

void addUserToText(userType);
void backupUsers(userType*, int);
userType* readUsers(int&);
bool loginCheck(loginType);
int findHasLoggedIn();

#endif // USERTYPE_H
