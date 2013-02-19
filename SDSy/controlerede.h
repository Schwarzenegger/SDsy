#ifndef CONTROLEREDE_H
#define CONTROLEREDE_H

#include <QObject>
#include <QQueue>
#include <QPair>
#include <QHash>
#include <QList>
#include <QByteArray>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QNetworkAccessManager>

#include "sdparsertoxml.h"


/**
  *Controla as Requisiçoes pro servidor
  */
class ControleRede : public QObject
{

Q_OBJECT

public:

    explicit ControleRede(const QUrl & url, QObject *parent = 0);

    /**
     * faz uma requisicao post para o servidor
     */
    void Post(const QHash<QString,QString> & params,const QList<QByteArray> & data);

signals:
    /**
     * evento envia informacao do retorno sem falha
     */
    void resultado(QString & data);
    /**
     * evento de falha
     * TODO: adicionar argumento que passem informacoes detalhadas sobre o erro
     */
    void falha();

private:
    QNetworkAccessManager *rede;
    QNetworkRequest requests;
    bool isSending;


    /**
     * requisicoes para processar
     */
    QQueue<QPair< QHash<QString,QString>,  QList<QByteArray> > > requisicoes;

    /**
     * indica que existe uma requisicao
     */
    void warnignNewRequest();
    /**
     * envia requisicao pendente
     */
    void enviarRequisicao();

     QByteArray & processarRequisicao(const QHash<QString,QString> & params,const QList<QByteArray> & data);


    /**
     * ultima resposta a ser recebida
     */
    QNetworkReply *lastReply;


private slots:
    /**
     * controla o evento de resposta
     */
    void handlerResponse();
    /**
     * controla evento de erro de reposta do Post
     */
    void handlerErrorPost(QNetworkReply::NetworkError error);

    /**
     * configura o header para:
     * application /
     */
    void setDHeader();

    /**
     * configura para multipart/form-data
     */
    void setMHeader();

};

#endif // CONTROLEREDE_H
