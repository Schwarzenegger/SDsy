#include "mainwidget.h"

MainWidget::MainWidget()
{
    //Inicializando a pilha de telas, e as telas
    stackedWidget = new QStackedWidget;
    loginInterface = new UserLogin();
    filesInterface = new UserFiles();

    //Adicionando as telas na pilha
    stackedWidget->addWidget(loginInterface->getInterface());
    stackedWidget->addWidget(filesInterface->getInterface());

    //Conectando sinais de troca de tela
    connect(loginInterface,SIGNAL(loginSucessful()),this,SLOT(setFilesInterface()));
    connect(filesInterface,SIGNAL(logoutSucessful()),this,SLOT(setLoginInterface()));
}

void MainWidget::show()
{
    //Mostrando na tela widget atual
    stackedWidget->show();
}

void MainWidget::setFilesInterface()
{
    stackedWidget->removeWidget(loginInterface->getInterface());
    stackedWidget->show();
    stackedWidget->addWidget(loginInterface->getInterface());
    //Alterando para tela de lista de arquivos
}

void MainWidget::setLoginInterface()
{
    stackedWidget->removeWidget(filesInterface->getInterface());
    stackedWidget->show();
    stackedWidget->addWidget(filesInterface->getInterface());
    //Alterando para tela de login
}
