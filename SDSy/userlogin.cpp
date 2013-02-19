#include "userlogin.h"

//Construtor
UserLogin::UserLogin()
{
    //Gerando a interface
    interface = new QWidget;
    interface->setWindowTitle(QString("Login - Disco Virtual UFC"));

     //Inicializando identificador e senha
    identify = new QLineEdit;
    password = new QLineEdit;
    this->status = "1";

    QFormLayout *loginForm = new QFormLayout;
    QPushButton *enterButton = new QPushButton("Entrar");

    //Caixa de password deve mostrar caracteres escondidos
    password->setEchoMode(QLineEdit::Password);

    loginForm->addRow(("&Identificador:"),identify);
    loginForm->addRow(("&Senha:"),password);
    loginForm->addWidget(enterButton);
    interface->setLayout(loginForm);

    //Conectando o sinal do botao de entrar
    connect(enterButton,SIGNAL(clicked()),this,SLOT(login()));

}

//Retorna interface
QWidget * UserLogin::getInterface()
{
    return interface;
}

//Checa login
void UserLogin::login()
{
    //Checando Login
    ServicosRedes::getSingletonInstance()->doLogin(identify->text(),password->text());

    connect(ServicosRedes::getSingletonInstance(),SIGNAL(facaLogin(QString)),this,SLOT(validaLogin(QString)));

    //Enviando sinal de login autorizado
    //emit loginSucessful();
}


void UserLogin::validaLogin(QString status)
{
    if(status == "0")
    {
        ServicosRedes::getSingletonInstance()->listarPasta("/");
        emit loginSucessful();
    }
}

void UserLogin::setStatus(QString Status)
{
    this->status = Status;

}
