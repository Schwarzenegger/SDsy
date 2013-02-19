#include "servicosredes.h"
#include <QtDebug>
#include <QHash>
#include <QString>
#include <QVariant>

ServicosRedes * ServicosRedes::uniqueInstance = NULL;

void ServicosRedes::configure(const QUrl & remoteUrl)
{
    if(ServicosRedes::uniqueInstance != NULL)
    {
        qFatal("Servico ja configurado");
    }

    ServicosRedes::uniqueInstance = new ServicosRedes(remoteUrl);
}

ServicosRedes * ServicosRedes::getSingletonInstance()
{
    if(ServicosRedes::uniqueInstance == NULL)
    {
        qFatal("Servico nao configurado");
    }
    return ServicosRedes::uniqueInstance;
}

ServicosRedes::ServicosRedes(const QUrl & remoteUrl) : QObject(0)
{
    this->responseParser = new SdParserFromXml();
    this->Controle = new ControleRede(remoteUrl,this);

    // plug in events
    connect(this->Controle,SIGNAL(resultado(QString&)),this,SLOT(networkResponse(QString&)));
}

void ServicosRedes::doLogin(QString user, QString password)
{

        requestLogin(user,password);

}

void ServicosRedes::doLogoff()
{
        requestLogoff();
}



void ServicosRedes::requestLogin(QString user, QString password)
{
    QHash<QString,QString> params;
    QList<QByteArray> data;

    params["todo"] = "login";
    params["user"] = user;
    params["password"] = password;


    Controle->Post(params,data);
}

void ServicosRedes::requestLogoff()
{
    QHash<QString,QString> params;
    QList<QByteArray> data;
    params["todo"] = "logoff";


    Controle->Post(params,data);
}

void ServicosRedes::networkResponse(QString & data)
{
    //qDebug() << data;

    QDomDocument doc;
    QDomElement root;
    QDomNode node;
    QString status;
    QList<QString> results;
    QList< QList<QString> > Lista;


    doc.setContent(data,true);
    root = doc.documentElement();
    node = root;

    if ( node.toElement().tagName() == "answerLogin")
    {

        status = responseParser->parserConnection(data);
        emit facaLogin(status);

    }

    if ( root.toElement().tagName() == "answerLogoff")
    {
        emit facaLogoff();

    }

    if ( root.toElement().tagName() == "answerDownload")
    {
        results = responseParser->parserDownload(data);

        emit facaDownload(results);

    }

    if ( root.toElement().tagName() == "answerUpload")
    {

    }

    if ( root.toElement().tagName() == "answerList")
    {
        Lista = responseParser->parserListar(data);
        emit facaListagem(Lista);
    }

    if ( root.toElement().tagName() == "answerMove")
    {
        results = responseParser->parserMover(data);
        emit facaMover(results);

    }

     if ( root.toElement().tagName() == "answerMkdir")
    {
        results = responseParser->parserCriarPasta(data);
        emit facaCriarPasta(results);
    }

    if ( root.toElement().tagName() == "answerDelete")
    {

        results = responseParser->parserDeletar(data);
        emit facaDeletar(results);
    }

    if ( root.toElement().tagName() == "answerVersion")
    {

        results = responseParser->parserVersaoArquivo(data);
        emit facaVersion(results);
    }
}

void ServicosRedes::criarPasta(const QString & pastaNome, const QString path)
{
    QHash<QString,QString> params;
    QList<QByteArray> data;

    params["todo"] = "mkdir";
    params["path"] = path;
    params["name"] = pastaNome;

    Controle->Post(params,data);
}

void ServicosRedes::listarPasta(const QString path)
{
    QHash<QString,QString> params;
    QList<QByteArray> data;

    params["todo"] = "list";
    params["path"] = path;

    Controle->Post(params,data);
}

void ServicosRedes::downloadFile(const QString path,const QString name)
{
    QHash<QString,QString> params;
    QList<QByteArray> data;

    params["todo"] = "download";
    params["path"] = path;
    params["name"] = name;

    Controle->Post(params,data);
}

void ServicosRedes::deleteFile(const QString  Path, const QString  name)
{
    QHash<QString,QString> params;
    QList<QByteArray> data;
    params["todo"] = "delete";
    params["path"] = Path;
    params["name"] = name;

    Controle->Post(params,data);
}

void ServicosRedes::versionFile(const QString  Path, const QString  name)
{
    QHash<QString,QString> params;
    QList<QByteArray> data;
    params["todo"] = "version";
    params["path"] = Path;
    params["name"] = name;

    Controle->Post(params,data);
}


void ServicosRedes::moveFile(const QString  oldPath, const QString  oldname, const QString  newPath, const QString  newname)
{
    QHash<QString,QString> params;
    QList<QByteArray> data;
    params["todo"] = "move";
    params["oldPath"] = oldPath;
    params["oldName"] = oldname;
    params["newPath"] = newPath;
    params["newName"] = newname;

    Controle->Post(params,data);
}
