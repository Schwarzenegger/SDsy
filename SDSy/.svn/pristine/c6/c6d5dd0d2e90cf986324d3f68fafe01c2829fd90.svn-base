#ifndef REMOTESERVICETEST_H
#define REMOTESERVICETEST_H

#include <QObject>
#include "servicosredes.h"

class RemoteServiceTest : QObject
{
Q_OBJECT
private:
    ServicosRedes *virtualDiskService;
public:
    RemoteServiceTest();
    void test();
public slots:
    void handlerLogin();
    void handlerLogoff();
};

#endif // REMOTESERVICETEST_H
