#include "logintype.h"
#include <QFile>
#include <QTextStream>


void backupLogin(loginType User)
{
  QFile file("backupLogin.txt");
  if (!file.open(QIODevice::WriteOnly  | QIODevice::Text))
  {
      return;
  }
  QTextStream out(&file);

  out << User.getUsername() << endl
      << User.getPassword() << endl << endl;
  file.close();
}

void loginType::setUsername(QString Username)
{
  username = Username;
}

void loginType::setPassword(QString Password)
{
  password = Password;
}

QString loginType::getUsername()
{
  return username;
}

QString loginType::getPassword()
{
  return password;
}

loginType::loginType()
{
  username = " ";
  password = " ";
}

loginType::loginType(QString Username, QString Password)
{
  username = Username;
  password = Password;
}
