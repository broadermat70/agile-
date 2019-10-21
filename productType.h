#ifndef PRODUCTTYPE_H
#define PRODUCTTYPE_H
#include <QString>
#include <iostream>

enum product { None, Basic, Pro, Premium };

class productType
{
public:

    productType();

//	product getLevel();
    QString getLevel();
    int getDaysLeft();

//	void changeLevel(product);
    void changeLevel(QString);
    void addDays(int);

    void cancelSub();

    void printProduct();

private:

//	product Level;
    QString productLevel;
    int subscriptionDaysLeft;

};

#endif // PRODUCTTYPE_H
