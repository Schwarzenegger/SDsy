#ifndef SDPARSERTOXML_H
#define SDPARSERTOXML_H

#include <QtXml>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QDateTime>
#include <QList>

#include "sdparsermsginfo.h"

class SdParserToXML : public QObject
{
    
public:
    inline SdParserToXML() {}

     /**
      * Faz o XML para uma nova conexão
      * Exemplo:
      *     todo: login
      *     user: thiago
      *     password: 12345
      */
     QString newConnection(const QString &user,const QString &password);

      /**
      * Faz o XML para uma nova desconexão
      * Exemplo:
      *     todo: logoff
      *     token: 345
      */
     QString newDesConnection( );

     /**
      * Faz o XML para uma nova Download
      * Exemplo:
      *   todo: download
      *   token: 345
      *   path: /documentos
      *   name: texto
      */
     QString newDownload(const QString &path,const QString &name);

      /**
      * Faz o XML para uma nova Upload
      * Exemplo:
      *   todo: upload
      *   token: 345
      *   path: /documentos
      *   name: texto
      *   version: 4
      */
     QString newUpload(const QString &path,const QString &name,const QString &version);

      /**
      * Faz o XML para uma nova Listagem
      * Exemplo:
      *    todo: list
      *    token: 345
      *    path: /documentos
      */ 
     QString newListar(const QString &path);

      /**
      * Faz o XML para Mover
      *    todo: move
      *    token: 345
      *    oldPath: /videos
      *    oldName: video
      *    newPath: /videos/tutoriais
      *    newName: videoSD
      */
     QString newMover(const QString &oldpath,const QString &oldname,const QString &newpath,const QString &newname);

      /**
      * Faz o XML para uma nova Deleção
      * Exemplo:
      *    todo: delete
      *    token: 345
      *    path: /documentos
      *    name: texto
      */
     QString newDeletar(const QString &path,const QString &name);

      /**
      * Faz o XML para uma nova Pasta
      * Exemplo:
      *    todo: mkdir
      *    token: 345
      *    path: /
      *    name: musicas
      */
     QString newCriarPasta(const QString &path, const QString &name);

      /**
      * Faz o XML para Copiar
      * Exemplo:
      *    todo: copy
      *    token: 345
      *    path: /documentos
      *    name: texto
      *    copyPath: /documentos/importantes
      */
     QString newCopiar(const QString &path,const QString &name,const QString &copypath);

      /**
      * Faz o XML para pegar versão do arquivo
      * Exemplo:
      *    todo: version
      *    token: 345
      *    path: /documentos
      *    name: texto
      */
     QString newVersaoArquivo(const QString &path,const QString &name);



};

#endif // SDPARSERTOXML_H
