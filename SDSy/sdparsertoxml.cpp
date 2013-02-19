#include "sdparsertoxml.h"

QString SdParserToXML::newConnection(const QString &user, const QString &password)
{
    QDomDocument doc;
    QDomElement root = doc.createElement("login");
    doc.appendChild(root);

    QDomElement nodeUser = doc.createElement("user");
    root.appendChild(nodeUser);
    QDomText nodeUserText = doc.createTextNode(user);
    nodeUser.appendChild(nodeUserText);

    QDomElement nodePasswd = doc.createElement("password");
    root.appendChild(nodePasswd);
    QDomText nodePasswdText = doc.createTextNode(password);
    nodePasswd.appendChild(nodePasswdText);



    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString SdParserToXML::newDesConnection()
{

    QDomDocument doc;
    QDomElement root = doc.createElement("logoff");
    doc.appendChild(root);


    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;

}

QString SdParserToXML::newDownload(const QString &path,const QString &name)
{
    QDomDocument doc;
    QDomElement root = doc.createElement("download");
    doc.appendChild(root);





    QDomElement nodePath = doc.createElement("path");
    root.appendChild(nodePath);
    QDomText nodePathText = doc.createTextNode(path);
    nodePath.appendChild(nodePathText);

    QDomElement nodeName = doc.createElement("name");
    root.appendChild(nodeName);
    QDomText nodeNameText = doc.createTextNode(name);
    nodeName.appendChild(nodeNameText);



    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;


}

QString SdParserToXML::newUpload(const QString &path,const QString &name,const QString &version)
{
    QDomDocument doc;
    QDomElement root = doc.createElement("upload");
    doc.appendChild(root);




    QDomElement nodePath = doc.createElement("path");
    root.appendChild(nodePath);
    QDomText nodePathText = doc.createTextNode(path);
    nodePath.appendChild(nodePathText);

    QDomElement nodeName = doc.createElement("name");
    root.appendChild(nodeName);
    QDomText nodeNameText = doc.createTextNode(name);
    nodeName.appendChild(nodeNameText);

    QDomElement nodeVersion = doc.createElement("version");
    root.appendChild(nodeVersion);
    QDomText nodeVersionText = doc.createTextNode(version);
    nodeName.appendChild(nodeVersionText);


    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;

}

QString SdParserToXML::newListar(const QString &path)
{
    QDomDocument doc;
    QDomElement root = doc.createElement("listar");
    doc.appendChild(root);





    QDomElement nodePath = doc.createElement("path");
    root.appendChild(nodePath);
    QDomText nodePathText = doc.createTextNode(path);
    nodePath.appendChild(nodePathText);


    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;


}

QString SdParserToXML::newMover(const QString &oldpath,const QString &oldname,const QString &newpath,const QString &newname)
{
    QDomDocument doc;
    QDomElement root = doc.createElement("move");
    doc.appendChild(root);





    QDomElement nodeOldPath = doc.createElement("oldpath");
    root.appendChild(nodeOldPath);
    QDomText nodeOldPathText = doc.createTextNode(oldpath);
    nodeOldPath.appendChild(nodeOldPathText);

    QDomElement nodeOldName = doc.createElement("oldname");
    root.appendChild(nodeOldName);
    QDomText nodeOldNameText = doc.createTextNode(oldname);
    nodeOldName.appendChild(nodeOldNameText);


    QDomElement nodeNewPath = doc.createElement("newpath");
    root.appendChild(nodeNewPath);
    QDomText nodeNewPathText = doc.createTextNode(newpath);
    nodeNewPath.appendChild(nodeNewPathText);

    QDomElement nodeNewName = doc.createElement("newname");
    root.appendChild(nodeNewName);
    QDomText nodeNewNameText = doc.createTextNode(newname);
    nodeNewName.appendChild(nodeNewNameText);


    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;


}

QString SdParserToXML::newDeletar(const QString &path,const QString &name)
{
    QDomDocument doc;
    QDomElement root = doc.createElement("delete");
    doc.appendChild(root);




    QDomElement nodePath = doc.createElement("path");
    root.appendChild(nodePath);
    QDomText nodePathText = doc.createTextNode(path);
    nodePath.appendChild(nodePathText);

    QDomElement nodeName = doc.createElement("name");
    root.appendChild(nodeName);
    QDomText nodeNameText = doc.createTextNode(name);
    nodeName.appendChild(nodeNameText);


    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;

}

QString SdParserToXML::newCriarPasta(const QString &path, const QString &name)
{
    QDomDocument doc;
    QDomElement root = doc.createElement("mkdir");
    doc.appendChild(root);



    QDomElement nodePath = doc.createElement("path");
    root.appendChild(nodePath);
    QDomText nodePathText = doc.createTextNode(path);
    nodePath.appendChild(nodePathText);

    QDomElement nodeName = doc.createElement("name");
    root.appendChild(nodeName);
    QDomText nodeNameText = doc.createTextNode(name);
    nodeName.appendChild(nodeNameText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;


}

QString SdParserToXML::newCopiar(const QString &path,const QString &name,const QString &copypath)
{

    QDomDocument doc;
    QDomElement root = doc.createElement("version");
    doc.appendChild(root);




    QDomElement nodePath = doc.createElement("path");
    root.appendChild(nodePath);
    QDomText nodePathText = doc.createTextNode(path);
    nodePath.appendChild(nodePathText);

    QDomElement nodeName = doc.createElement("name");
    root.appendChild(nodeName);
    QDomText nodeNameText = doc.createTextNode(name);
    nodeName.appendChild(nodeNameText);


    QDomElement nodeCopyPath = doc.createElement("copypath");
    root.appendChild(nodeCopyPath);
    QDomText nodeCopyPathText = doc.createTextNode(copypath);
    nodeCopyPath.appendChild(nodeCopyPathText);


    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;


}

QString SdParserToXML::newVersaoArquivo(const QString &path,const QString &name)
{

    QDomDocument doc;
    QDomElement root = doc.createElement("version");
    doc.appendChild(root);





    QDomElement nodePath = doc.createElement("path");
    root.appendChild(nodePath);
    QDomText nodePathText = doc.createTextNode(path);
    nodePath.appendChild(nodePathText);

    QDomElement nodeName = doc.createElement("name");
    root.appendChild(nodeName);
    QDomText nodeNameText = doc.createTextNode(name);
    nodeName.appendChild(nodeNameText);


    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;


}

