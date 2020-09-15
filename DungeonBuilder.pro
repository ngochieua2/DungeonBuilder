TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        basicdungeonlevel.cpp \
        basicdungeonlevelbuilder.cpp \
        blockeddoorway.cpp \
        doorway.cpp \
        dungeonlevel.cpp \
        dungeonlevelbuilder.cpp \
        game.cpp \
        lockeddoor.cpp \
        magicaldungeonlevelbuilder.cpp \
        magicdungeonlevel.cpp \
        main.cpp \
        menuinterface.cpp \
        onewaydoor.cpp \
        opendoorway.cpp \
        room.cpp \
        roomedge.cpp \
        wall.cpp

HEADERS += \
    basicdungeonlevel.h \
    basicdungeonlevelbuilder.h \
    blockeddoorway.h \
    doorway.h \
    dungeonlevel.h \
    dungeonlevelbuilder.h \
    game.h \
    lockeddoor.h \
    magicaldungeonlevelbuilder.h \
    magicdungeonlevel.h \
    menuinterface.h \
    onewaydoor.h \
    opendoorway.h \
    room.h \
    roomedge.h \
    wall.h
