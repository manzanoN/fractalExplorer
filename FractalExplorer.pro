QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    aboutmandel.cpp \
    credits.cpp \
    main.cpp \
    mainwindow.cpp \
    mandel.cpp \
    meetthedevs.cpp \
    plotwindow.cpp \
    settingsdialog.cpp

HEADERS += \
    about.h \
    aboutmandel.h \
    credits.h \
    mainwindow.h \
    mandel.h \
    meetthedevs.h \
    plotwindow.h \
    settingsdialog.h

FORMS += \
    about.ui \
    aboutmandel.ui \
    credits.ui \
    mainwindow.ui \
    meetthedevs.ui \
    plotwindow.ui \
    settingsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Icons/003-directions-3.png \
    Icons/004-directions-2.png \
    Icons/005-directions-1.png \
    Icons/006-directions.png \
    Icons/007-up-9.png \
    Icons/008-left-13.png \
    Icons/009-left-12.png \
    Icons/010-left-11.png \
    Icons/011-right-15.png \
    Icons/012-right-14.png \
    Icons/013-right-13.png \
    Icons/014-down-9.png \
    Icons/015-up-8.png \
    Icons/016-left-10.png \
    Icons/017-right-12.png \
    Icons/018-down-8.png \
    Icons/019-up-7.png \
    Icons/020-left-9.png \
    Icons/021-right-11.png \
    Icons/022-down-7.png \
    Icons/023-up-6.png \
    Icons/024-left-8.png \
    Icons/025-right-10.png \
    Icons/026-down-6.png \
    Icons/027-up-5.png \
    Icons/028-left-7.png \
    Icons/029-left-6.png \
    Icons/030-left-down-4.png \
    Icons/031-right-9.png \
    Icons/032-right-8.png \
    Icons/033-right-7.png \
    Icons/034-down-5.png \
    Icons/035-up-4.png \
    Icons/036-left-5.png \
    Icons/037-left-4.png \
    Icons/038-left-down-3.png \
    Icons/039-right-6.png \
    Icons/040-right-5.png \
    Icons/041-right-4.png \
    Icons/042-down-4.png \
    Icons/043-up-3.png \
    Icons/044-left-down-2.png \
    Icons/045-left-3.png \
    Icons/046-left-up-2.png \
    Icons/047-right-3.png \
    Icons/048-right-up-2.png \
    Icons/049-right-down-2.png \
    Icons/050-down-3.png \
    Icons/051-up-2.png \
    Icons/052-left-2.png \
    Icons/053-left-up-1.png \
    Icons/054-left-down-1.png \
    Icons/055-right-2.png \
    Icons/056-right-up-1.png \
    Icons/057-right-down-1.png \
    Icons/058-down-2.png \
    Icons/059-up-1.png \
    Icons/060-left-1.png \
    Icons/061-right-1.png \
    Icons/062-down-1.png \
    Icons/063-up.png \
    Icons/064-left-up.png \
    Icons/065-left.png \
    Icons/066-left-down.png \
    Icons/067-right.png \
    Icons/068-right-up.png \
    Icons/069-right-down.png \
    Icons/070-down.png

RESOURCES += \
    Icons.qrc \
    img.qrc
