TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        abstractcreature.cpp \
        basicdungeonlevel.cpp \
        basicdungeonlevelbuilder.cpp \
        blockeddoorway.cpp \
        consumable.cpp \
        doorway.cpp \
        dungeonlevel.cpp \
        dungeonlevelbuilder.cpp \
        game.cpp \
        item.cpp \
        lockeddoor.cpp \
        main.cpp \
        menuinterface.cpp \
        monster.cpp \
        onewaydoor.cpp \
        opendoorway.cpp \
        quartzchamber.cpp \
        rockchamber.cpp \
        rockwall.cpp \
        room.cpp \
        roomedge.cpp \
        wall.cpp \
        weapon.cpp

HEADERS += \
    abstractcreature.h \
    basicdungeonlevel.h \
    basicdungeonlevelbuilder.h \
    blockeddoorway.h \
    consumable.h \
    doorway.h \
    dungeonlevel.h \
    dungeonlevelbuilder.h \
    game.h \
    item.h \
    lockeddoor.h \
    menuinterface.h \
    monster.h \
    onewaydoor.h \
    opendoorway.h \
    quartzchamber.h \
    rockchamber.h \
    rockwall.h \
    room.h \
    roomedge.h \
    wall.h \
    weapon.h
