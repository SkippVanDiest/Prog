TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra
SOURCES += \
    monster.cc \
    plateau.cc \
    SDL.cc \
    main.cc \
    affichage.cc

include(deployment.pri)
qtcAddDeployment()


LIBS+=`sdl-config --libs` -lSDL_image -lSDL_ttf

INCLUDEPATH+=-I/usr/include/SDL/

HEADERS += \
    monster.h \
    SDL.h \
    plateau.h \
    affichage.h
