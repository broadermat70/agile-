#include "customerType.h"
#include <fstream>

void backupCustomer(customerType Customer)
{
  ofstream fout;
  fout.open("backupCustomers.txt");
  fout << Customer.getCompany() << endl
       << Customer.getAddress() << endl
       << Customer.getCity() << ", " << Customer.getState() << " " << Customer.getZip() << endl
       << Customer.getInterest() << endl
       << Customer.getIsKey() << endl;
  fout.close();
}

void getCustomer(customerType& Customer)
{
  string company;
  string address;
  string city;
  string state;
  int zip;
  string interest;
  bool isKey;

  ifstream fin;
  fin.open("Customers.txt");
  fin.getline(company, '\n');
  fin.getline(address, '\n');
  fin.getline(city, ',');
  fin >> state;
  fin >> zip;
  fin.getline(interest, '\n');
  fin >> isKey;
  fin.close();

  Customer.setCompany(company);
  Customer.setAddress(address);
  Customer.setCity(city);
  Customer.setState(state);
  Customer.setZip(zip);
  Customer.setInterest(interest);
  Customer.setIsKey(isKey);

}

void customerType::setCompany(string Company)
{
  company = Company;
}

void customerType::setAddress(string Address)
{
  address = Address;
}

void customerType::setCity(string City)
{
  city = City;
}

void customerType::setState(string State)
{
  state = State;
}

void customerType::setZip(int Zip)
{
  zip = Zip;
}

void customerType::setInterest(string Interest)
{
  interest = Interest;
}

void customerType::setIsKey(bool IsKey)
{
  isKey = IsKey;
}

string customerType::getCompany()
{
  return company;
}

string customerType::getAddress()
{
  return address;
}

string customerType::getCity()
{
  return city;
}

string customerType::getState()
{
  return state;
}

int customerType::getZip()
{
  return zip;
}

string customerType::getInterest()
{
  return interest;
}

bool customerType::getIsKey()
{
  return isKey;
}

void customerType::customerType()
{
  company = " ";
  address = " ";
  city = " ";
  state = " ";
  zip = 0;
  interest = " ";
  isKey = false;
}

void customerType::customerType(stirng Company, string Address, string City, string State, int Zip, string Interest, bool IsKey)
{
  company = Company;
  address = Address;
  city = City;
  state = State;
  zip = Zip;
  interest = Interest;
  isKey = IsKey;
}
