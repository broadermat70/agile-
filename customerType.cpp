#include "customerType.h"
#include <fstream>

void backupCustomer(customerType Customer)
{
  ofstream myfile;
  myfile.open("backupCustomers.txt");
  myfile << Customer.getCompany() << endl
         << Customer.getAddress() << endl
         << Customer.getCity() << ", " << Customer.getState() << " " << Customer.getZip() << endl
         << Customer.getInterest() << endl
         << Customer.getIsKey() << endl;
  myfile.close();
}

void customerType::setUsername(string Username)
{
  username = Username;
}

void customerType::setPassword(string Password)
{
  password = Password;
}

void customerType::setFName(string FName)
{
  fName = FName;
}

void customerType::setLName(string LName)
{
 lName = LName;
}

string customerType::getUserName()
{
  return username;
}

string customerType::getPassword()
{
  return password;
}

string customerType::getFName()
{
  return fName;
}

string customerType::getLName()
{
  return lName;
}

void customerType::customerType()
{
  username = " ";
  password = " ";
  fName = " ";
  lName = " ";
}

void customerType::customerType(stirng Username, string Password, string FName, string LName)
{
  username = Username;
  password = Password;
  fName = FName;
  lName = LName;
}
