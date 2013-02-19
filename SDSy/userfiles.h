#ifndef USERFILES_H
#define USERFILES_H

#include <QtGui\QWidget>
#include <QObject>
#include <QPushButton>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialog>

#include <QDebug>

#include "servicosredes.h"

class UserFiles : public QObject
{
    Q_OBJECT
public:
    UserFiles();   //Construtor
    QWidget * getInterface(); //Retornando interface de lista de arquivos

public slots:
    void logout(); //Metodo para envio de sinal de logout
    void lista(QList<QList<QString> >);
    void checkTypeOfItem(QListWidgetItem *); //Checando o tipo de arquivo, e realizando açao determinada
    void createNewDir();  //Mostrando caixa de dialogo para novo diretorio
    void sendNewDir();    //Chamando servicos de rede para criar nova pasta
    void showNewDir(QList<QString>); //Como diretório não é criado de verdade no servidor, só mostramos na tela, se obtiver sucesso
    void confirmDelete(); //Confirmaçao da deleçao
    void completeDelete(); //Fazendo a deleçao
    void showDelete(QList<QString>);

signals:
    void logoutSucessful(); //Sinal de logout

private:
    QWidget *interface; //Widget de lista de arquivos
    QLayout *layout;    //Layout da tela de lista principal
    QString parentFolder; //Nome do diretório pai
    QString currentFolder; //Nome do diretório atual
    QListWidgetItem *currentFile;
    QListWidget *listWidget; //Lista de arquivos e Diretório
    QLabel *folder; //Widget do nome do diretório na tela
    QLineEdit *newDirName; //Recebe o nome do novo diretório

    void setCurrentFolder(QString);
    void setParentFolder(QString);
    void setFolder(QString);
    void setCurrentFile(QListWidgetItem *);
};

#endif // USERFILES_H
