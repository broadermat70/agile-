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

void backupLogin(QString username, QString password)
{
  QFile file("backupLogin.txt");
  if (!file.open(QIODevice::WriteOnly  | QIODevice::Text))
  {
      return;
  }
  QTextStream out(&file);

  out << username << endl
      << password << endl << endl;
  file.close();
}

bool loginCheck(loginType logins)
{
    QString username[10];
    QString password[10];
    int i = 0;

    QFile file("backupLogin.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

    }

    QTextStream in(&file);
    while (!in.atEnd() && i<10)
    {
        username[i] = in.readLine();
        password[i] = in.readLine();
        in.readLine();
        i++;
    }
    for(int j = 0; j < 10; j++)
    {
        if(logins.getUsername() == username[j] && logins.getPassword() == password[j])
        {
            return true;
        }
    }
    return false;
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
