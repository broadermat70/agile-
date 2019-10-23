#ifndef USERTYPE_H
#define USERTYPE_H
#include "logintype.h"
#include<QString>
#include "productType.h"


class userType: public loginType
{
public:
    userType();
    //Basic Consturctor
    //Sets isAdmin and hasLoggedIn to false

            //fname   //lname
    userType(QString, QString);
    //Full constructor
    //Sets fname and lname to their respective parameters
    //Sets isAdmin and hasLoggedIn to false

             //Object being copied
    userType(const userType &obj);
    //Copy Constructor
    //Copies values of passed object's variables to the new object

    QString getFName() const; //Returns fName variable as QString
    QString getLName() const; //Returns lName variable as QString
    bool getHasLoggedIn() const; //Returns hasLoggedIn variable as bool
    bool getIsAdmin() const; //Returns isAdmin variable as bool

    void setFName(QString);
    //Stores the passed string in the fName variable

    void setLName(QString);
    //Stores the passed string in the lName variable

    void setHasLoggedIn(bool);
    //Used to set the hasLoggedIn bool variable to passed value

    void setHasLoggedIn(QString);
    //Is passed a QString pulled from text storage file
    //Converts "0" to False or "1" to True and stores the result.

    void setIsAdmin(bool);
    //Used to set the isAdmin bool variable to passed value

    void setIsAdmin(QString);
    //Is passed a QString pulled from text storage file
    //Converts "0" to False or "1" to True and stores the result.

    productType* customerProduct;
    //productType pointer to point to user's current subscription plan


private:
   QString lName; //Stores The Last Name of the user
   QString fName; //Stores the First Name of the user

   bool isAdmin; //Stores the admin status of the user
   // False = not an admin, True = is an Admin

   bool hasLoggedIn;//Stores the logged in status of the user
   // False = Hasn't logged in, True = Has logged in

};

void addUserToText(userType);
void backupUsers(userType*, int);
userType* readUsers(int&);
bool loginCheck(loginType);
int findHasLoggedIn();

#endif // USERTYPE_H
