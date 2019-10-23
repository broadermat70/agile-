#ifndef PRODUCTTYPE_H
#define PRODUCTTYPE_H
#include <QString>
#include <iostream>

enum product { None, Basic, Pro, Premium };

class productType
{
public:

    productType();//Basic Constructor

    productType(const productType &obj);//Copy Constructor
    //Saves the values of the passed object's two variables to
    //Their respective variables inside the new object


    QString getLevel() const;//Returns the value of productLevel as a QString
    int getDaysLeft() const; // returns the value of subscriptionDaysLeft as an int


    void changeLevel(QString);
    //Function that changes the value of the productLevel variable
    //Function checks that the passed string it recieves is one of the valid subscription types
    //If it is, it sets the [roductLevel variable to the passed string.
    //If it isnt, the function does nothing.

    void changeDays(int);
    //Function that sets the value of subscriptionDaysLeft to the value of the passed integer

    void addDays(int);
    //Function that adds the passed integer's value to the value of subscriptionDaysLeft

    void cancelSub();
    //Function to cancel the customer's current subscription
    //Sets productLevel to "None" and subscriptionDaysLeft to 0

//    void printProduct();
//unused function that prints on the command line

private:
    QString productLevel;
    //Stores the type of subscription package the customer posesses

    int subscriptionDaysLeft;
    //Stores the number of days left in the customer's subscription

};

#endif // PRODUCTTYPE_H
