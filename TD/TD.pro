QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gameobject.cpp \
    gamescene.cpp \
    main.cpp \
    mainwindow.cpp \
    powergenerator.cpp

HEADERS += \
    gameobject.h \
    gamescene.h \
    mainwindow.h \
    powergenerator.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recources.qrc

DISTFILES += \
    images/bucket-head-zombie.gif \
    images/cherry-bomb-button.jpg \
    images/cherry-bomb-explosian.gif \
    images/cherry-bomb.gif \
    images/cherry-bomb.png \
    images/chomper-button.jpg \
    images/chomper-eating.gif \
    images/chomper.gif \
    images/chomper.png \
    images/cone-head-zombie.gif \
    images/dirt-row.png \
    images/flag-zombie.gif \
    images/grass-row-alt.png \
    images/grass-row.png \
    images/home-row.png \
    images/img1.png \
    images/img2.png \
    images/img3.png \
    images/img4.png \
    images/lawn-mower.png \
    images/newspaper-zombie.gif \
    images/normal-zombie.gif \
    images/pea-shooter-bullet.png \
    images/pea-shooter-button.jpg \
    images/pea-shooter.gif \
    images/pea-shooter.png \
    images/portal-row.png \
    images/potato-mine-active.gif \
    images/potato-mine-button.jpg \
    images/potato-mine-inactive.gif \
    images/potato-mine.png \
    images/repeater-button.jpg \
    images/repeater.gif \
    images/repeater.png \
    images/snow-pea-bullet.png \
    images/snow-pea-button.jpg \
    images/snow-pea.gif \
    images/snow-pea.png \
    images/sun.png \
    images/sunflower-button.jpg \
    images/sunflower.gif \
    images/sunflower.png \
    images/wallnut-button.jpg \
    images/wallnut.gif \
    images/wallnut.png
