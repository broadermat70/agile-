#ifndef H_LoginType
#define H_LoginType

#include <iostream>

using namespace std;

class loginType
{
private:
  string username;
  string password;
public:
  void setUsername(string);
  void setPassword(string);

  string getUsername();
  string getPassword();

  void loginType();
  void loginType(stirng, string);
}

void backupLogin(string, string);

#endif
