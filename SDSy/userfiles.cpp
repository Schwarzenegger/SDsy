#include "userfiles.h"

//Construtor
UserFiles::UserFiles()
{
    //Gerando a interface
    interface = new QWidget;

    newDirName = new QLineEdit;

    QPushButton *logoutButton = new QPushButton("Logout");
    QPushButton *newDir = new QPushButton("Novo Diretorio");
    layout = new QVBoxLayout;
    folder = new QLabel;

    layout->addWidget(logoutButton);
    layout->addWidget(newDir);
    layout->addWidget(folder);
    interface->setLayout(layout);

    connect(logoutButton,SIGNAL(clicked()),this,SLOT(logout()));
    connect(newDir,SIGNAL(clicked()),this,SLOT(createNewDir()));
    connect(ServicosRedes::getSingletonInstance(),SIGNAL(facaListagem(QList<QList<QString> >)),this,SLOT(lista(QList<QList<QString> >)));
    connect(ServicosRedes::getSingletonInstance(),SIGNAL(facaCriarPasta(QList<QString>)),this,SLOT(showNewDir(QList<QString>)));
    connect(ServicosRedes::getSingletonInstance(),SIGNAL(facaDeletar(QList<QString>)),this,SLOT(showDelete(QList<QString>)));
}

QWidget * UserFiles::getInterface()
{
    return interface;
}

//Enviando sinal de logout
void UserFiles::logout()
{
    ServicosRedes::getSingletonInstance()->doLogoff();

    emit logoutSucessful(); //Sinal de logout
}

void UserFiles::lista(QList<QList<QString> > allFiles)
{

    listWidget->~QListWidget();
    listWidget = new QListWidget;

    QList<QString>::iterator i;
    QList<QString> pathList = allFiles.at(0);
    QList<QString> nameList = allFiles.at(1);
    QList<QString> folderList = allFiles.at(4);

    setFolder(pathList.at(0));


    //Setando o diretorio atual, se for o path, o diretorio pai sera vazio
    if((pathList.at(0) == "/"))
    {
        setParentFolder("");
    }
    else
    {
        QListWidgetItem *item = new QListWidgetItem(QIcon(":/images/folder.jpeg"),"..",listWidget,1);
        setParentFolder(currentFolder);
    }
    setCurrentFolder(pathList.at(0));



    //Adicionando os arquivos na lista, tipo 0
    for (i = nameList.begin(); i != nameList.end(); ++i)
         QListWidgetItem *item = new QListWidgetItem(QIcon(":/images/file.jpg"),*i,listWidget,0);


    //Adicionando os diretorios, tipo 1
    for (i = folderList.begin(); i != folderList.end(); ++i)
         QListWidgetItem *item = new QListWidgetItem(QIcon(":/images/folder.jpeg"),*i,listWidget,1);


    //Conectando sinal de clique duplo
    connect(listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,SLOT(checkTypeOfItem(QListWidgetItem *)));

    layout->addWidget(listWidget);
}

void UserFiles::checkTypeOfItem(QListWidgetItem *item)
{
    /*
      Tipo 0 = Arquivo
      Tipo 1 = Diretorio
      Tipo 2 = Novo diretorio (Naum faz nada)
     */
   QDialog *menuDialog = new QDialog;
   QVBoxLayout *layoutMenu = new QVBoxLayout;
   QPushButton *deleteButton = new QPushButton("Deletar");
   QPushButton *closeButton = new QPushButton("Fechar");


   switch(item->type())
   {
       case 0:
           setCurrentFile(item);

           layoutMenu->addWidget(deleteButton);
           layoutMenu->addWidget(closeButton);

           connect(deleteButton,SIGNAL(clicked()),this,SLOT(confirmDelete()));
           connect(closeButton,SIGNAL(clicked()),menuDialog,SLOT(close()));
           connect(deleteButton,SIGNAL(clicked()),menuDialog,SLOT(close()));

           menuDialog->setLayout(layoutMenu);
           menuDialog->exec();
           break;
       case 1:
           layout->removeWidget(listWidget);
           if(item->text() == "..")
               ServicosRedes::getSingletonInstance()->listarPasta(parentFolder);
           else
               ServicosRedes::getSingletonInstance()->listarPasta("/" + item->text());
           break;
       case 2: break;
   }
}

void UserFiles::confirmDelete()
{
    QDialog *deleteDialog = new QDialog;
    QLabel *question = new QLabel("Deseja mesmo deletar o arquivo?");
    QPushButton *confirm = new QPushButton("Deletar");
    QPushButton *cancel = new QPushButton("Cancelar");
    QVBoxLayout *deleteLayout = new QVBoxLayout;

    deleteLayout->addWidget(question);
    deleteLayout->addWidget(cancel);
    deleteLayout->addWidget(confirm);

    connect(confirm,SIGNAL(clicked()),deleteDialog,SLOT(close()));
    connect(confirm,SIGNAL(clicked()),this,SLOT(completeDelete()));
    connect(cancel,SIGNAL(clicked()),deleteDialog,SLOT(close()));

    deleteDialog->setLayout(deleteLayout);
    deleteDialog->exec();
}

void UserFiles::completeDelete()
{
    ServicosRedes::getSingletonInstance()->deleteFile(currentFolder,currentFile->text());
}

void UserFiles::showDelete(QList<QString> deleteInformation)
{
    QDialog *deleteDialog = new QDialog;
    QVBoxLayout *deleteLayout = new QVBoxLayout;
    QLabel *information = new QLabel;
    QPushButton *ok = new QPushButton("Ok");

    QString path = deleteInformation.at(0);
    QString name = deleteInformation.at(1);
    QString status = deleteInformation.at(2);

    if(status == "0") information->setText("Arquivo deletado com sucesso!");
    if(status == "1") information->setText("Voce nao esta logado!");
    if(status == "2") information->setText("Ocorreu erro no servidor!");

    deleteLayout->addWidget(information);
    deleteLayout->addWidget(ok);
    deleteDialog->setLayout(deleteLayout);

    connect(ok,SIGNAL(clicked()),deleteDialog,SLOT(close()));

    deleteDialog->exec();

    listWidget->removeItemWidget(currentFile);

}

void UserFiles::createNewDir()
{
    QDialog *createDialog = new QDialog;
    QFormLayout *createLayout = new QFormLayout;
    QPushButton *enterButton = new QPushButton("Criar");

    createLayout->addRow(("&Nome:"),newDirName);

    createLayout->addWidget(enterButton);
    createDialog->setLayout(createLayout);

    connect(enterButton,SIGNAL(clicked()),this,SLOT(sendNewDir()));
    connect(enterButton,SIGNAL(clicked()),createDialog,SLOT(close()));

    createDialog->exec();
}

void UserFiles::showNewDir(QList<QString> newDirList)
{
    QDialog *newDirDialog = new QDialog;
    QPushButton *ok = new QPushButton("Ok");
    QLabel *information = new QLabel;
    QVBoxLayout *informationLayout = new QVBoxLayout;

    QString path = newDirList.at(0);
    QString name = newDirList.at(1);
    QString status = newDirList.at(2);

    if(status == "0") information->setText("Diretorio criado com sucesso!");
    if(status == "1") information->setText("Voce nao esta logado!");
    if(status == "2") information->setText("Ocorreu erro no servidor!");


    informationLayout->addWidget(information);
    informationLayout->addWidget(ok);
    newDirDialog->setLayout(informationLayout);

    connect(ok,SIGNAL(clicked()),newDirDialog,SLOT(close()));

    newDirDialog->exec();

    QListWidgetItem *item = new QListWidgetItem(QIcon(":/images/folder.jpeg"),name,listWidget,2);
}

void UserFiles::sendNewDir()
{
    ServicosRedes::getSingletonInstance()->criarPasta(newDirName->text(),currentFolder);
}

void UserFiles::setCurrentFolder(QString current)
{
    currentFolder = current;
}

void UserFiles::setParentFolder(QString parent)
{
    parentFolder = parent;
}

void UserFiles::setFolder(QString folderName)
{
    folder->setText(folderName);
}

void UserFiles::setCurrentFile(QListWidgetItem *fileItem)
{
    currentFile = fileItem;
}

