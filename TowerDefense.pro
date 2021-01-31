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
    controller/controller.cpp \
    controller/initialscreencontroller.cpp \
    controller/gamescreencontroller.cpp \
    controller/setmapscreencontroller.cpp \
    \
    view/mainwindow.cpp \
    \
    view/hud/infobox.cpp \
    view/hud/iconbutton.cpp \
    view/hud/standardbutton.cpp \
    view/hud/modal.cpp \
    \
    view/screens/gameScreen/gameview.cpp \
    view/screens/gameScreen/gamescene.cpp \
    view/screens/gameScreen/gridcell.cpp \
    view/screens/gameScreen/enemyitem.cpp \
    view/screens/gameScreen/turretitem.cpp \
    view/screens/gameScreen/gridfield.cpp \
    view/screens/gameScreen/turretselector.cpp \
    view/screens/gameScreen/turretselectoritem.cpp \
    view/screens/gameScreen/pausemodal.cpp \
    view/screens/gameScreen/projectile.cpp \
    \
    view/screens/initialScreen/initialscreenview.cpp \
    view/screens/initialScreen/initialscreenscene.cpp \
    \
    view/screens/setMapScreen/setmapgrid.cpp \
    view/screens/setMapScreen/setmapview.cpp \
    view/screens/setMapScreen/setmapscene.cpp \
    view/screens/setMapScreen/setmapcell.cpp \
    view/screens/setMapScreen/cellselectoritem.cpp \
    view/screens/setMapScreen/cellselector.cpp 

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
    controller/controller.h \
    controller/initialscreencontroller.h \
    controller/gamescreencontroller.h \
    controller/setmapscreencontroller.h \
    \
    view/mainwindow.h \
    \
    view/hud/infobox.h \
    view/hud/iconbutton.h \
    view/hud/standardbutton.h \
    view/hud/modal.h \
    \
    view/screens/gameScreen/gameview.h \
    view/screens/gameScreen/gamescene.h \
    view/screens/gameScreen/gridcelltype.h \
    view/screens/gameScreen/gridcell.h \  \
    view/screens/gameScreen/enemyitem.h \
    view/screens/gameScreen/turretitem.h \
    view/screens/gameScreen/gridfield.h \
    view/screens/gameScreen/turretselector.h \
    view/screens/gameScreen/turretselectoritem.h \
    view/screens/gameScreen/pausemodal.h \
    view/screens/gameScreen/projectile.h \
    \
    view/screens/initialScreen/initialscreenview.h \
    view/screens/initialScreen/initialscreenscene.h \
    \
    view/screens/setMapScreen/setmapview.h \
    view/screens/setMapScreen/setmapscene.h \
    view/screens/setMapScreen/setmapgrid.h \
    view/screens/setMapScreen/setmapcell.h \
    view/screens/setMapScreen/cellselectoritem.h \
    view/screens/setMapScreen/cellselector.h 




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    resources.qrc
