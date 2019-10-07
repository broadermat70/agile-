#ifndef H_customerType
#define H_customerType

#include <iostream>

using namespace std;

class customerType
{
private:
  string company;
  string address;
  string city;
  string state;
  int zip;
  string interest;
  bool isKey;
public:
  void setCompany(string);
  void setAddress(string);
  void setCity(string);
  void setState(string);
  void setZip(int);
  void setInterest(string);
  void setIsKey(bool);

  string getCompany();
  string getAddress();
  string getCity();
  string getState();
  int getZip();
  string getInterest();
  bool getIsKey();

  void customerType();
  void customerType(stirng, string, string, string, int, string, bool);
}

void backupCustomer(customerType);

#endif
