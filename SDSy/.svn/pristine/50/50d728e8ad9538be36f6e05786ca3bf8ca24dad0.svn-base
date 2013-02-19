#include "RemoteServiceTest.h"
#include <QtDebug>

RemoteServiceTest::RemoteServiceTest()
{
    virtualDiskService = ServicosRedes::getSingletonInstance();
    connect(virtualDiskService,SIGNAL(responseDoLogin()),SLOT(handlerLogin()));

}

void RemoteServiceTest::test()
{
    virtualDiskService->doLogin();
    virtualDiskService->doLogoff();
}

void RemoteServiceTest::handlerLogin()
{
    qDebug() << "usuario logado";

}

void RemoteServiceTest::handlerLogoff()
{

}
