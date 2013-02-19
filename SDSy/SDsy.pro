QT += gui \
    core
QT += xml
QT += network
TARGET = SDsy
TEMPLATE = app
HEADERS += sdparserfromxml.h \
    sdparsermsginfo.h \
    sdparsertoxml.h \
    mainwidget.h \
    userlogin.h \
    userfiles.h \
    controlerede.h \
    servicosredes.h
SOURCES += sdparserfromxml.cpp \
    sdparsermsginfo.cpp \
    main.cpp \
    sdparsertoxml.cpp \
    mainwidget.cpp \
    userlogin.cpp \
    userfiles.cpp \
    controlerede.cpp \
    servicosredes.cpp
RESOURCES += res.qrc
