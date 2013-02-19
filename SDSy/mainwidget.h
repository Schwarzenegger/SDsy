#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtGui\QStackedWidget>
#include <QObject>

#include "userlogin.h"
#include "userfiles.h"

class MainWidget : public QObject
{
    Q_OBJECT
public:
    MainWidget();    //Construtor
    void show();     //Método para mostrar Widget na tela

public slots:
    void setFilesInterface();   //Mudar tela para lista de arquivos
    void setLoginInterface();   //Mudar tela para login

private:
    QStackedWidget *stackedWidget;  //Guarda todas as widgets, telas do software
    UserLogin *loginInterface;      //Widget de login
    UserFiles *filesInterface;      //Widget da lista de arquivos
};

#endif // MAINWIDGET_H
