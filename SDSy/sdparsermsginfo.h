#ifndef SDPARSERMSGINFO_H
#define SDPARSERMSGINFO_H

class SdParserMsgInfo
{


public:
    SdParserMsgInfo();
    enum MType
    {
        MTPNewCon                = 0,  // mensagem para criar nova Conexão
        MTPNewDesCon             = 1,  // mensagem para criar nova Conexão
        MTPNewDownload           = 2,  // mensagem para criar nova Conexão
        MTPNewUpload             = 3,  // mensagem para criar nova Conexão
        MTPNewList               = 4,  // mensagem para criar nova Conexão
        MTPNewMove               = 5,  // mensagem para criar nova Conexão
        MTPNewDel                = 6,  // mensagem para criar nova Conexão
        MTPNewCP                 = 7,  // mensagem para criar nova Conexão
        MTPNewCopy               = 8,  // mensagem para criar nova Conexão
        MTPNewVersion            = 9,  // mensagem para criar nova Conexão

    };
};

#endif // SDPARSERMSGINFO_H
