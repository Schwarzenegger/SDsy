#include "sdparserfromxml.h"

QString SdParserFromXml::parserConnection(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root;

    QString status;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "answerLogin"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "status")
                {
                    status = childNode2.toText().data();
                }
                childNode = childNode.nextSibling();

            }
        }
        node = node.nextSibling();
    }

    if ( status.length() == 0 )
    {
        return "fail";
    }

    return status;

}

QString SdParserFromXml::parserDesconnect(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root;

    QString status;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "answerLogoff"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "status")
                {
                    status = childNode2.toText().data();
                }
                childNode = childNode.nextSibling();

            }
        }
        node = node.nextSibling();
    }

    if ( status.length() == 0 )
    {
        return "fail";
    }


    return status;

}

QList<QString> SdParserFromXml::parserDownload(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;
    QList<QString> downloadResult;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root;

    QString nome;
    QString status;
    QString path;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "answerDownload"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "path")
                {
                    path = childNode2.toText().data();
                }
                if ( tagName == "name")
                {
                    nome = childNode2.toText().data();
                }
                if ( tagName == "status")
                {
                    status = childNode2.toText().data();
                }
                childNode = childNode.nextSibling();

            }
        }
        node = node.nextSibling();
    }


    if ( status.length() == 0  || nome.length() == 0)
    {
        downloadResult.append("fail");
        return downloadResult;
    }


    downloadResult.append(path);
    downloadResult.append(nome);
    downloadResult.append(status);

    return downloadResult;
}

QList<QString> SdParserFromXml::parserUpload(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;
    QList<QString> uploadResult;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root;

    QString path;
    QString nome;
    QString version;
    QString status;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "answerUpload"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "path")
                {
                    path = childNode2.toText().data();
                }
                if ( tagName == "name")
                {
                    nome = childNode2.toText().data();
                }
                if ( tagName == "version")
                {
                    version = childNode2.toText().data();
                }
                if ( tagName == "status")
                {
                    status = childNode2.toText().data();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }


    if ( path.length() == 0  || nome.length() == 0 || version.length() == 0 || status.length() == 0)
    {
        uploadResult.append("fail");
        return uploadResult;
    }

    uploadResult.append(path);
    uploadResult.append(nome);
    uploadResult.append(version);
    uploadResult.append(status);

    return uploadResult;

}

QList< QList<QString> > SdParserFromXml::parserListar(const QString &xml)
{

    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root;

    QList<QString> path;
    QList<QString> nome;
    QList<QString> size;
    QList<QString> version;
    QList<QString> status;
    QList<QString> nameFolder;
    QList<QString> sizeFolder;
    QList<QString> itens;

    QList< QList<QString> > listResult;


    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "answerList"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "path")
                {
                    path << childNode2.toText().data();
                }
                if ( tagName == "file")
                {
                    childNode2 = childNode.firstChild();
                    while(!childNode2.isNull() ){
                        QString tagName = childNode2.toElement().tagName();
                        QDomNode childNode3 = childNode2.firstChild();
                        if (tagName == "name")
                        {
                            nome << childNode3.toText().data();
                        }
                        if (tagName == "size")
                        {
                            size << childNode3.toText().data();
                        }
                        if (tagName == "version")
                        {
                            version << childNode3.toText().data();
                        }

                        childNode2 = childNode2.nextSibling();
                    }

                }
                if ( tagName == "folder")
                {
                    childNode2 = childNode.firstChild();
                    while(!childNode2.isNull() ){
                        QString tagName = childNode2.toElement().tagName();
                        QDomNode childNode3 = childNode2.firstChild();
                        if (tagName == "name")
                        {
                            nameFolder << childNode3.toText().data();
                        }

                        if (tagName == "itens")
                        {
                            itens << childNode3.toText().data();
                        }

                        childNode2 = childNode2.nextSibling();
                    }

                }
                if ( tagName == "status")
                {
                    status.append(childNode2.toText().data());
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }


    if ( status.length() == 0)
    {
        return listResult;
    }


    listResult.append(path);
    listResult.append(nome);
    listResult.append(size);
    listResult.append(version);
    listResult.append(nameFolder);
    listResult.append(sizeFolder);
    listResult.append(itens);
    listResult.append(status);


    return listResult;
}

QList<QString> SdParserFromXml::parserMover(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root;

    QString oldpath;
    QString oldnome;
    QString newpath;
    QString newnome;
    QString status;

    QList<QString> moveResult;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "answerMove"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "oldPath")
                {
                    oldpath = childNode2.toText().data();
                }
                if ( tagName == "oldName")
                {
                    oldnome = childNode2.toText().data();
                }
                if ( tagName == "newPath")
                {
                    newpath = childNode2.toText().data();
                }
                if ( tagName == "newName")
                {
                    newnome = childNode2.toText().data();
                }
                if ( tagName == "status")
                {
                    status = childNode2.toText().data();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( status.length() == 0)
    {
        moveResult.append("fail");
        return moveResult;
    }


    moveResult.append(oldpath);
    moveResult.append(oldnome);
    moveResult.append(newpath);
    moveResult.append(newnome);
    moveResult.append(status);

    return moveResult;

}

QList<QString> SdParserFromXml::parserDeletar(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root;

    QString path;
    QString nome;
    QString status;

    QList<QString> deleteResult;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "answerDelete"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "path")
                {
                    path = childNode2.toText().data();
                }
                if ( tagName == "name")
                {
                    nome = childNode2.toText().data();
                }
                if ( tagName == "status")
                {
                    status = childNode2.toText().data();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }


    if ( path.length() == 0  || nome.length() == 0  || status.length() == 0)
    {
        deleteResult.append("fail");
        return deleteResult;
    }


    deleteResult.append(path);
    deleteResult.append(nome);
    deleteResult.append(status);

    return deleteResult;
}

QList<QString> SdParserFromXml::parserCriarPasta(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root;

    QString path;
    QString nome;
    QString status;

    QList<QString> createResult;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "answerMkdir"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "path")
                {
                    path = childNode2.toText().data();
                }
                if ( tagName == "name")
                {
                    nome = childNode2.toText().data();
                }
                if ( tagName == "status")
                {
                    status = childNode2.toText().data();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }


    if ( path.length() == 0  || nome.length() == 0  || status.length() == 0)
    {
        createResult.append("fail");
        return createResult;
    }


    createResult.append(path);
    createResult.append(nome);
    createResult.append(status);

    return createResult;


}

QList<QString> SdParserFromXml::parserCopiar(const QString &xml)
{

    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root;

    QString path;
    QString nome;
    QString copypath;
    QString status;

    QList<QString> copyResult;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "answerCopy"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "path")
                {
                    path = childNode2.toText().data();
                }
                if ( tagName == "name")
                {
                    nome = childNode2.toText().data();
                }
                if ( tagName == "copyPath")
                {
                    copypath = childNode2.toText().data();
                }
                if ( tagName == "status")
                {
                    status = childNode2.toText().data();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }


    if ( path.length() == 0  || nome.length() == 0 || copypath.length() == 0 || status.length() == 0)
    {
        copyResult.append("fail");
        return copyResult;
    }

    copyResult.append(path);
    copyResult.append(nome);
    copyResult.append(copypath);
    copyResult.append(status);

    return copyResult;
}

QList<QString> SdParserFromXml::parserVersaoArquivo(const QString &xml)
{

    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root;

    QString path;
    QString nome;
    QString version;
    QString status;

    QList<QString> versionResult;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "answerVersion"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "path")
                {
                    path = childNode2.toText().data();
                }
                if ( tagName == "name")
                {
                    nome = childNode2.toText().data();
                }
                if ( tagName == "version")
                {
                    version = childNode2.toText().data();
                }
                if ( tagName == "status")
                {
                    status = childNode2.toText().data();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }


    if ( status.length() == 0)
    {
        versionResult.append("fail");
        return versionResult;
    }


    versionResult.append(path);
    versionResult.append(nome);
    versionResult.append(version);
    versionResult.append(status);

    return versionResult;

}




/*
QString SdParserFromXml::parser(const QString &xml, int code)
{
    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomDocument doc;

    if (!doc.setContent(xml,true,&errorStr,&errorLine,&errorColumn) )
    {
        qDebug() << "SdParserFromXml :: erro no parsing | Li " << errorLine << " Col " << errorColumn << "  Msg " << errorStr;
        emit error(errorStr,errorLine,errorColumn);
        return;
    }



    switch (code)
    {
        case (SdParserMsgInfo::MTPNewCon) :
            parserConnection(xml);
            break;
        case (SdParserMsgInfo::MTPNewDesCon) :
            parserDesconnect(xml);
            break;
        case (SdParserMsgInfo::MTPNewDownload) :
            parserDownload(xml);
            break;
        case (SdParserMsgInfo::MTPNewUpload):
            parserUpload(xml);
            break;
        case (SdParserMsgInfo::MTPNewList) :
            parserListar(xml);
            break;
        case (SdParserMsgInfo::MTPNewMove) :
            parserMover(xml);
            break;
        case (SdParserMsgInfo::MTPNewDel):
            parserDeletar(xml);
            break;
        case (SdParserMsgInfo::MTPNewCP):
            parserCriarPasta(xml);
            break;
        case (SdParserMsgInfo::MTPNewCopy):
            parserCopiar(xml);
            break;
        case (SdParserMsgInfo::MTPNewVersion):
            parserVersaoArquivo(xml);
            break;

        default :
            qDebug() << "SdParserFromXml :: tipo de mensagem nao existe";
            return;
    }
}
*/
