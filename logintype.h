#ifndef LOGINTYPE_H
#define LOGINTYPE_H

#include <QString>

class loginType
{
private:
  QString username;
  QString password;
public:
  void setUsername(QString);
  void setPassword(QString);

  QString getUsername();
  QString getPassword();

  loginType();
  loginType(QString, QString);
};

void backupLogin(QString, QString);

#endif // LOGINTYPE_H
