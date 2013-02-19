#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QtGui\QWidget>
#include <QtGui\QPushButton>
#include <QtGui\QFormLayout>
#include <QtGui\QLineEdit>
#include <QtGui\QPushButton>
#include <QString>
#include <QObject>

#include "servicosredes.h"

class UserLogin : public QObject
{
    Q_OBJECT
public:
    UserLogin();
    QWidget * getInterface(); //Metodo para retornar widget do login
    void setStatus(QString Status);

public slots:
    void login(); //Slot para checar login
    void validaLogin(QString);

signals:
    void loginSucessful(); //Sinal que o login foi bem sucedido

private:
    QWidget *interface;  //Widget da interface de login
    QLineEdit *identify;
    QLineEdit *password;
    QString status;
};

#endif // USERLOGIN_H
