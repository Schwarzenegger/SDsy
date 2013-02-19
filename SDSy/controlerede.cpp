#include "controlerede.h"
#include <QtDebug>


ControleRede::ControleRede(const QUrl & url, QObject *parent) : QObject(parent)
{
    rede = new QNetworkAccessManager(this);

    requests = QNetworkRequest(url);

    /**
     * versao 0.1
     */
    this->lastReply = NULL;
    this->isSending = false;
}

void ControleRede::Post(const QHash<QString,QString> & params,const QList<QByteArray> & data)
{
    QPair< QHash<QString,QString>, QList<QByteArray> > newPairRequest(params,data);
    requisicoes.enqueue(newPairRequest);

    warnignNewRequest();
}

QByteArray & ControleRede::processarRequisicao(const QHash<QString,QString> & params,const QList<QByteArray> & data)
{
    QByteArray *result = new QByteArray;

    if(data.length() == 0)
    {
        if(params.count() > 0)
        {
            foreach(QString paramName,params.uniqueKeys())
            {
                result->append(paramName + "=" + params[paramName] + "&");
            }
            // remover o ultimo &
            result->remove(result->length() - 1,1);
        }
    }

    if(!result->isEmpty())
    {
        qDebug() << *result;
    }

    return *result;
}

void ControleRede::warnignNewRequest()
{
    if(!isSending)
    {
        isSending = true;

        enviarRequisicao();
    }

}

void ControleRede::handlerResponse()
{
    lastReply->disconnect();

    QString resultString(lastReply->readAll());
    emit resultado(resultString);

    lastReply->deleteLater();
    isSending = false;
    if(requisicoes.length() > 0)
    {
        isSending = true;
        enviarRequisicao();
    }

}

void ControleRede::enviarRequisicao()
{
    QPair< QHash<QString,QString>, QList<QByteArray> > pairRequest = requisicoes.dequeue();

    if(pairRequest.second.length() == 0)
    {
        this->setDHeader();
    }
    else
    {
        this->setMHeader();
    }

    QByteArray request = this->processarRequisicao(pairRequest.first,pairRequest.second);
    lastReply = rede->post(requests,request);
    connect(lastReply,SIGNAL(finished()),SLOT(handlerResponse()));
    connect(lastReply,SIGNAL(error(QNetworkReply::NetworkError)),SLOT(handlerErrorPost(QNetworkReply::NetworkError)));
}

void ControleRede::handlerErrorPost(QNetworkReply::NetworkError error)
{

    qDebug() << "error de resposta";
}

void ControleRede::setDHeader()
{
    QByteArray headerContent;
    headerContent.append("application/x-www-form-urlencoded");
    requests.setHeader(QNetworkRequest::ContentTypeHeader, headerContent);

}

void ControleRede::setMHeader()
{
    QByteArray headerContent;
    headerContent.append("multipart/form-data; boundary=\"" "\"");
    requests.setHeader(QNetworkRequest::ContentTypeHeader, headerContent);
}
