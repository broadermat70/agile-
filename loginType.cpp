#include "loginType.h"
#include <fstream>

void backupLogin(loginType User)
{
  ofstream myfile;
  myfile.open("backupLogin.txt");
  myfile << User.getUsername() << endl
         << User.getPassword() << endl << endl;
  myfile.close();
}

void loginType::setUsername(string Username)
{
  username = Username;
}

void loginType::setPassword(string Password)
{
  password = Password;
}

string loginType::getUsername()
{
  return username;
}

string loginType::getPassword()
{
  return password;
}

void loginType::loginType()
{
  username = " ";
  password = " ";
}

void loginType::loginType(stirng Username, string Password)
{
  username = Username;
  password = Password;
}
