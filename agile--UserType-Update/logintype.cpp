#include "logintype.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>


void backupLogin(loginType User)
{
  QFile file("backupUsers.txt");
  if (!file.open(QIODevice::WriteOnly  | QIODevice::Append))
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
  QFile file("backupUsers.TXT");
  if (!file.open(QIODevice::WriteOnly  | QIODevice::Append))
  {
      qDebug() << "Could not open File";
      return;
  }
  QTextStream out(&file);

  out << username << endl
      << password << endl;
  file.close();
}

loginType* readLogin(int &count)
{
    loginType* logins;
    int numLogins = 0;
    QFile file("backupUsers.TXT");
    if(!file.open(QIODevice::ReadOnly  | QIODevice::Text))
    {
        qDebug() << "Could not Read File";
        return nullptr;
    }
    QTextStream in(&file);
    //while (!in.atEnd())
    {
        numLogins++;
    }

    logins = new loginType[numLogins];

    count = 0;
    QString username;
    QString password;
    QTextStream input(&file);
    while(!input.atEnd())
    {
        username = input.readLine();
        password = input.readLine();
        logins[count].setUsername(username);
        logins[count].setPassword(password);
        count++;
    }

    return logins;
}

bool loginType::operator==(loginType C)
{
    return(C.getUsername() == username && C.getPassword() == password);
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
