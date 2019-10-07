#ifndef H_UserDataBase
#define H_UserDataBase

#include <iostream>

using namespace std;

class userType
{
private:
  string userName;
  string password;
  string fName;
  string lName;
  //string address;
public:
  void setUserName(string);
  void setPassword(string);
  void setFName(string);
  void setLName(string);

  string getUserName();
  string getPassword();
  string getFName();
  string getLName();

  void userType();
  void userType(stirng, string, string, string);
}

void backupLogin(string, string);

#endif
