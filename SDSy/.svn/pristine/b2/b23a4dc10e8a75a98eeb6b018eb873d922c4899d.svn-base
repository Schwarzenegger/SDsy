#include <QObject>
#include <QtGui/QApplication>

#include "sdparserfromxml.h"
#include "mainwidget.h"
#include "controlerede.h"
#include "servicosredes.h"
#include "remoteservicetest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    ServicosRedes::configure(QUrl("http://200.19.176.230:8080/interface/servlet/interface"));

    MainWidget *mainWidget = new MainWidget();
    mainWidget->show();

    return a.exec();
}
