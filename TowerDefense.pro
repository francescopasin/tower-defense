QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    \
    model/gamemodel.cpp \
    model/game.cpp \
    model/enemy.cpp \
    model/exception.cpp \
    \
    model/turrets/turret.cpp \
    model/turrets/singulartargetturret.cpp \
    model/turrets/multipletargetturret.cpp \
    model/turrets/comboturret.cpp \
    model/turrets/splitturret.cpp \
    \
    controller/gamecontroller.cpp \
    controller/navigationcontroller.cpp \
    \
    view/mainwindow.cpp \
    \
    view/hud/infobox.cpp \
    view/hud/iconbutton.cpp \
    view/hud/turretselector.cpp \
    view/hud/turretselectoritem.cpp \
    view/hud/standardbutton.cpp \
    \
    view/screens/gameScreen/gameview.cpp \
    view/screens/gameScreen/gamescene.cpp \
    view/screens/gameScreen/gridcell.cpp \
    view/screens/gameScreen/enemyitem.cpp \
    view/screens/gameScreen/gridfield.cpp \
    \
    view/screens/initialScreen/initialscreenview.cpp \
    view/screens/initialScreen/initialscreenscene.cpp \
    \
    view/screens/setMapScreen/setmapgrid.cpp \
    view/screens/setMapScreen/setmapview.cpp \
    view/screens/setMapScreen/setmapscene.cpp \
    view/screens/setMapScreen/setmapcell.cpp

HEADERS += \
    app/routes.h \
    \
    model/pathcell.h \
    model/position.h \
    model/gamemodel.h \
    model/game.h \
    model/sharedptr.h \
    model/mylist.h \
    model/enemy.h \
    model/exception.h \
    model/wave.h \
    \
    model/turrets/turret.h \
    model/turrets/singulartargetturret.h \
    model/turrets/multipletargetturret.h \
    model/turrets/comboturret.h \
    model/turrets/splitturret.h \
    model/turrets/turrettype.h \
    \
    controller/gamecontroller.h \
    controller/navigationcontroller.h \
    \
    view/mainwindow.h \
    \
    view/hud/infobox.h \
    view/hud/iconbutton.h \
    view/hud/turretselector.h \
    view/hud/turretselectoritem.h \
    view/hud/standardbutton.h \
    \
    view/screens/gameScreen/gameview.h \
    view/screens/gameScreen/gamescene.h \
    view/screens/gameScreen/gridcelltype.h \
    view/screens/gameScreen/gridcell.h \  \
    view/screens/gameScreen/enemyitem.h \
    view/screens/gameScreen/gridfield.h \
    \
    view/screens/initialScreen/initialscreenview.h \
    view/screens/initialScreen/initialscreenscene.h \
    \
    view/screens/setMapScreen/setmapview.h \
    view/screens/setMapScreen/setmapscene.h \
    view/screens/setMapScreen/setmapgrid.h \
    view/screens/setMapScreen/setmapcell.h




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    resources.qrc
