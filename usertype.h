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
    bool getHasLoggedIn();
    bool getIsAdmin();

    void setFName(QString);
    void setLName(QString);
    void setHasLoggedIn(bool);
    void setHasLoggedIn(QString );
    void setIsAdmin(bool);
    void setIsAdmin(QString);
    productType* customerProduct;




private:
   QString lName;
   QString fName;
   bool isAdmin;
   bool hasLoggedIn;
};

void addUserToText(userType);
void backupUsers(userType*, int);
userType* readUsers(int&);
bool loginCheck(loginType);
int findHasLoggedIn();
void resetCurrentLogin();
QString stringCut(QString input, int width);
int findLargestString();
userType* sortfName();
userType* sortlName();

#endif // USERTYPE_H
