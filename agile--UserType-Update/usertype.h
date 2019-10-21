#ifndef USERTYPE_H
#define USERTYPE_H
#include "logintype.h"
#include "productType.h"
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
    bool getisLogin();
    void setisLogin(bool isLoggedin);
       productType customerPlan;

private:
   QString lName;
   QString fName;
   bool isLoggedIn;


};

void backupUsers(userType);
userType* readUsers(int&);
bool loginCheck(loginType, int&);
userType findLogginInUser();

#endif // USERTYPE_H
