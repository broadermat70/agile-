#include "productType.h"

productType::productType()
{
    productLevel = "None";
    subscriptionDaysLeft = 0;
}



QString productType::getLevel()
{
    return productLevel;
}

int productType::getDaysLeft()
{
    return subscriptionDaysLeft;
}

void productType::changeLevel(QString lev)
{
//    if (lev == "Basic" || "Pro" || "Premium")
//    {
        productLevel = lev;
//    }
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
