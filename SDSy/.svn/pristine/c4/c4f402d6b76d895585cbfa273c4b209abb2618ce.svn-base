#ifndef REMOTESERVICECONTROLLER_H
#define REMOTESERVICECONTROLLER_H

#include <QObject>
#include <QUrl>

#include "controlerede.h"
#include "sdparserfromxml.h"
#include "userlogin.h"

/**
 * Servico de diretorio remoto
 */
class ServicosRedes : public QObject
{
Q_OBJECT

public:
    static ServicosRedes * uniqueInstance;
    ControleRede *Controle;
    SdParserFromXml *responseParser;

    /**
     * faz um pedido de requisicao de login no servidor remoto
     */
    void requestLogin(QString,QString);
    /**
     * faz um pedido de requisicao de logoff no servidor remoto
     */
    void requestLogoff();
    /**
     *Pedido de criar pasta
     */
    void criarPasta(const QString & pastaNome, const QString path);
    /**
      * Pedido de listagem
      */
    void listarPasta(const QString path);
    /**
      * Pedido de download
      */
    void downloadFile(const QString path,const QString name);
      /**
      * Pedido de deleçao
      */
    void deleteFile(const QString path,const QString name);

       /**
      * Pedido de versão
      */
    void versionFile(const QString  Path, const QString  name);

      /**
      * Pedido mover
      */
    void moveFile(const QString  oldPath, const QString  oldname, const QString  newPath, const QString  newname);




    /**
     * Construtor
     */
    explicit ServicosRedes(const QUrl & remoteUrl);

    /**
     * configura o servico remoto
     */
    static void configure(const QUrl & remoteUrl);
    /**
     * recupera o objeto dessa classe
     */
    static ServicosRedes * getSingletonInstance();
    /**
     * faz o login
     */
    void doLogin(QString,QString);

    /**
     * faz o logoff
     */
    void doLogoff();

    /**
     * verifica o estado do usuario
     */
    bool isLogged();



    /**
     * retorna o usuario
     */

signals:
    /**
     * evento disparado login
     */
    void responseDoLogin();
    /**
     * evento disparadologout
     */
    void responseDoLogoff();
    /**
     * evento falha
     */
    void fault();

    /**
      *Sinal Log in
      */
    void facaLogin(QString status);
     /**
      *Sinal Logoff
      */
    void facaLogoff();
      /**
      *Sinal Mkdir
      */
    void facaCriarPasta(QList<QString> results);
        /**
      *Sinal List
      */
    void facaListagem(QList<QList<QString > > results);
      /**
      *Sinal Download
      */
    void facaDownload(QList<QString> results);

     /**
      *Sinal Download
      */
    void facaDeletar(QList<QString> results);

     /**
      *Sinal Download
      */
    void facaVersion(QList<QString> results);


      /**
      *Sinal Mover
      */
    void facaMover(QList<QString> results);

public slots:
    /**
     * handler para network controller
     */
    void networkResponse(QString & data);

};

#endif // REMOTESERVICECONTROLLER_H
