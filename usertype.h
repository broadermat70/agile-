#ifndef USERTYPE_H
#define USERTYPE_H
#include "logintype.h"
#include<QString>
#include "productType.h"


class userType: public loginType
{
public:
    userType();
    userType(QString, QString);

    QString getFName();
    QString getLName();
    bool getHasLoggedIn();
    bool getIsAdmin();

    void setFName(QString);
    void setLName(QString);
    void setHasLoggedIn(bool);
    void setHasLoggedIn(QString );
    void setIsAdmin(bool);
    void setIsAdmin(QString);
    productType* customerProduct[50];
    int productsPurchased;


private:
   QString lName;
   QString fName;
   bool isAdmin = false;
   bool hasLoggedIn = false;

};

void addUserToText(userType);
void backupUsers(userType*, int);
userType* readUsers(int&);
bool loginCheck(loginType);
int findHasLoggedIn();

#endif // USERTYPE_H
