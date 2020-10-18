QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcities.cpp \
    city.cpp \
    distancetable_class.cpp \
    executetrip.cpp \
    food.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    parser.cpp \
    plantripform.cpp \
    presettripform.cpp \
    selectform.cpp \
    serializer.cpp

HEADERS += \
    addcities.h \
    city.h \
    delegators.h \
    distancetable_class.h \
    executetrip.h \
    food.h \
    login.h \
    mainwindow.h \
    parser.h \
    plantripform.h \
    presettripform.h \
    selectform.h \
    serializer.h \
    user.h

FORMS += \
    addcities.ui \
    executetrip.ui \
    login.ui \
    mainwindow.ui \
    plantripform.ui \
    presettripform.ui \
    selectform.ui

TRANSLATIONS += \
    sas_EuropeanVacation_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    data/cities/cit.sas \
    data/cities/dist.sas
