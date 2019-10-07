#include "userDataBase.h"
#include <fstream>

void backupLogin(userType User)
{
  ofstream myfile;
  myfile.open("backupUsers.txt");
  myfile << "Username:  " User.getUserName() << endl
         << "Password:  " User.getPassword() << endl
         << "First Na:  " User.getFName() << endl
         << "Last Nam:  " User.getLName() << endl;
  myfile.close();
}

void userType::setUserName(string UserName)
{
  userName = UserName;
}

void userType::setPassword(string Password)
{
  password = Password;
}

void userType::setFName(string FName)
{
  fName = FName;
}

void userType::setLName(string LName)
{
 lName = LName;
}

string userType::getUserName()
{
  return userName;
}

string userType::getPassword()
{
  return password;
}

string userType::getFName()
{
  return fName;
}

string userType::getLName()
{
  return lName;
}

void userType::userType()
{
  userName = " ";
  password = " ";
  fName = " ";
  lName = " ";
}

void userType::userType(stirng UserName, string Password, string FName, string LName)
{
  userName = UserName;
  password = Password;
  fName = FName;
  lName = LName;
}
