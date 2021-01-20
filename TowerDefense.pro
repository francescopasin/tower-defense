QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    model/gamemodel.cpp \
    model/game.cpp \
    model/enemy.cpp \
    model/turrets/turret.cpp \
    model/turrets/singulartargetturret.cpp \
    model/turrets/multipletargetturret.cpp \
    model/turrets/comboturret.cpp \
    model/turrets/splitturret.cpp \
    model/exception.cpp \
    controller/gamecontroller.cpp \
    view/mainwindow.cpp \
    view/gameview.cpp \
    view/gamescene.cpp \
    view/gridcell.cpp \
    view/hud/infobox.cpp \
    view/hud/iconbutton.cpp \
    view/hud/turretselector.cpp \
    view/hud/turretselectoritem.cpp

HEADERS += \
    model/pathcell.h \
    model/position.h \
    model/gamemodel.h \
    model/game.h \
    model/deepptr.h \
    model/mylist.h \
    model/enemy.h \
    model/turrets/turret.h \
    model/turrets/singulartargetturret.h \
    model/turrets/multipletargetturret.h \
    model/turrets/comboturret.h \
    model/turrets/splitturret.h \
    model/turrets/turrettype.h \
    model/exception.h \
    model/wave.h \
    controller/gamecontroller.h \
    view/mainwindow.h \
    view/gameview.h \
    view/gamescene.h \
    view/gridcelltype.h \
    view/gridcell.h \ 
    view/hud/infobox.h \
    view/hud/iconbutton.h \
    view/hud/turretselector.h \
    view/hud/turretselectoritem.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    resources.qrc
