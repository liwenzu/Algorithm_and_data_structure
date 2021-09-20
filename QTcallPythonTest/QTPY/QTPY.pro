QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui


#INCLUDEPATH += -I D:\python\include
#LIBS += -L D:\python\libs -1python36

#INCLUDEPATH += -I D:\Program Files\Python37\include
#LIBS += -LD:\Program Files\Python37\libs -1python37




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    print.py

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../Program Files/Python37/libs/' -lpython37
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../Program Files/Python37/libs/' -lpython37d

INCLUDEPATH += $$PWD/'../../../../Program Files/Python37/include'
DEPENDPATH += $$PWD/'../../../../Program Files/Python37/include'

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/'../../../../Program Files/Python37/libs/libpython37.a'
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/'../../../../Program Files/Python37/libs/libpython37d.a'
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/'../../../../Program Files/Python37/libs/python37.lib'
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/'../../../../Program Files/Python37/libs/python37d.lib'
