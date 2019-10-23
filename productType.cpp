#include "productType.h"



productType::productType()
{
    productLevel = "None";
    subscriptionDaysLeft = 0;
}

productType::productType(const productType &obj)
{
    productLevel = obj.getLevel();
    subscriptionDaysLeft = obj.getDaysLeft();
}

QString productType::getLevel() const
{
    return productLevel;
}

int productType::getDaysLeft() const
{
    return subscriptionDaysLeft;
}

void productType::changeLevel(QString lev)
{
    if (lev == "Basic")
    {
        productLevel = lev;
    } else {
        if (lev == "Pro")
        {
            productLevel = lev;
        } else {
               if (lev == "Premium")
               {
                   productLevel = lev;
               }
         }
     }
}

void productType::changeDays(int days)
{
    subscriptionDaysLeft = days;
}

void productType::addDays(int days)
{
    subscriptionDaysLeft = (subscriptionDaysLeft + days);
}

void productType::cancelSub()
{
    productLevel = "None";
    subscriptionDaysLeft = 0;
}
/*
void productType::printProduct()
{
    std::cout << "Subscription Type: " << getLevel() << endl;
    std::cout << "Days left: " << getDaysLeft() << endl;
}
*/
/*
product productType::getLevel()
{
    return Level;
}
*/

/*
void productType::changeLevel(product pro)
{
    Level = pro;
}
*/
