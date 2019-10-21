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

  bool operator==(loginType);
  loginType();
  loginType(QString, QString);
};

void backupLogin(QString, QString);
void backupLogin(loginType);
bool loginCheck(loginType);
loginType* readLogin(int&);

#endif // LOGINTYPE_H
