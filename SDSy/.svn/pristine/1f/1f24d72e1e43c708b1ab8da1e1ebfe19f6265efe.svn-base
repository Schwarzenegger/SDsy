#ifndef SDPARSERFROMXML_H
#define SDPARSERFROMXML_H

#include <QtXml>
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QList>

#include "sdparsermsginfo.h"

/**
 * Classe responsavel pela decodificao da mensagem em xml
 */
class SdParserFromXml : public QObject
{

    Q_OBJECT
    public:
        inline SdParserFromXml() {}

        /**
         * Retorna somente o status da acao
         *	0 - Sucesso
         *	1 - Errou usuário ou senha
         * 	2 - Já está logado
         *	3 - Fracasso genérico
         */
         QString parserConnection(const QString &xml);


         /**
         * Retorna somente o status da acao
         *  0 - Sucesso
         *  1 - Não está logado
         *  2 - Fracasso genérico
         */
         QString parserDesconnect(const QString &xml);


         /**
         * Retorna:
         *  path - caminho do arquivo
         *  name - nome do arquivo
         *  status -
         *      1 - Não está logado
         *      2 - Arquivo não existe
         *      3 - Fracasso genérico
         */
         QList<QString> parserDownload(const QString &xml);


         /**
         * Retorna:
         *  path - caminho do arquivo
         *  name - nome do arquivo
         *  version - versão do arquivo
         *  status -
         *      1 - Não está logado
         *      2 - Arquivo não existe
         *      3 - Fracasso genérico
         */
         QList<QString> parserUpload(const QString &xml);


         /**
         * Retorna uma lista de listas, a seguinte ordem:
         *  1 - lista de path
         *  2 - lista de nome
         *  3 - lista de size
         *  4 - lista de version
         *  5 - lista de nameFolder
         *  6 - lista de sizeFolder
         *  7 - lista de itens
         *  8 - lista de status (somente 1 elemento)
         */
         QList< QList<QString> > parserListar(const QString &xml);


         /**
          * Retorna
          *  oldPath - caminho antigo
          *  oldName - nome antigo
          *  newPath - novo caminho
          *  newName - novo nome
          *  status -
          *	0 - Sucesso
          *     1 - Não está logado
          *     2 - Fracasso genérico
          */
         QList<QString> parserMover(const QString &xml);


         /**
         * Faz o parser da mensagem de deletar
         *  0 - Sucesso
         *  1 - Não está logado
         *  2 - Fracasso genérico
         */
         QList<QString> parserDeletar(const QString &xml);


         /**
          *
          *  path - caminho
          *  name - nome do arquivo
          *  status -
          *        0 - Sucesso
          *        1 - Não está logado
          *        2 - Fracasso genérico
          */
         QList<QString> parserCriarPasta(const QString &xml);


         /**
         * Faz o parser da mensagem de copiar
         *  0 - Sucesso
         *  1 - Não está logado
         *  2 - Fracasso genérico
         */
         QList<QString> parserCopiar(const QString &xml);


         /**
         * Faz o parser da mensagem de Versionamento
         *  0 - Sucesso
         *  1 - Não está logado
         *  2 - Fracasso genérico
         */
         QList<QString> parserVersaoArquivo(const QString &xml);




         /**
          * Faz o parser de qualquer mensagem em xml do Sdsy
          * void parser(const QString &xml,int code);
          */



    signals:

         /**
         * emite quando houver erro no parsing
         */
        void error(QString errorMsg, int errorLine, int errorColumn);

         /**
         * emite quando quando a msg codificada for de conexão
         */
        void newCon(QString status);
         /**
         * emite quando quando a msg codificada for de desconexão
         */
        void newDesCon(QString status);
         /**
         * emite quando quando a msg codificada for de download
         */
        void newDownload(QString path,QString status, QString nome);
         /**
         * emite quando quando a msg codificada for de upload
         */
        void newUpload(QString path, QString nome, QString version, QString satus);

         /**
         * emite quando quando a msg codificada for de listar
         */
        void newListar(QList<QString> path,QList<QString> nome,QList<QString> size,QList<QString> version,QList<QString> nameFolder,QList<QString> sizeFolder,QList<QString> itens,QString status);
         /**
         * emite quando quando a msg codificada for de mover
         */
        void newMover(QString oldpath,QString oldnome,QString newpath,QString newnome,QString status);
         /**
         * emite quando quando a msg codificada for de deletar
         */
        void newDeletar(QString path,QString nome,QString status);
         /**
         * emite quando quando a msg codificada for de criar pasta
         */
        void newCriarPasta(QString path,QString nome,QString status);
         /**
         * emite quando quando a msg codificada for de Copiar
         */
        void newCopiar(QString path, QString nome, QString copyPath, QString satus);
         /**
         * emite quando quando a msg codificada for de versionamento
         */
        void newVersaoArquivo(QString path, QString nome, QString version, QString satus);

    };



#endif // SDPARSERFROMXML_H
