#include "logintype.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>


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
  QFile file("backupLogin.TXT");
  if (!file.open(QIODevice::WriteOnly  | QIODevice::Text))
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
    QFile file("backupLogin.TXT");
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


bool loginCheck(loginType logins)
{
    qDebug() << "Starting LoginCheck";
    int count = 0;
    loginType* allLogins = readLogin(count);
    for(int i = 0; i < count; i++)
    {
        qDebug() << "Starting forloop for loginCheck";
        qDebug() << logins.getPassword() << allLogins[i].getPassword();
        if(logins == allLogins[i])
        {
            return true;
        }
        else if(i == count-1)
        {
            return false;
        }
    }
   /* QString username[10];
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
            file.close();
            return true;
        }
    }
    file.close();
    return false;*/
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
