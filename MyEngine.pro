#-------------------------------------------------
#
# Project created by QtCreator 2019-06-24T14:11:20
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -lassimp


TARGET = MyEngine
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += object_parallel_to_source

INCLUDEPATH += $$PWD/include

VPATH += ./resources
VPATH += ./ui

SOURCES += \
        Engine/engine.cpp \
        mainwindow.cpp \
        Engine/scene.cpp \
        Engine/object.cpp \
        Engine/import.cpp \
        Engine/shader.cpp \
        main.cpp \
        Engine/mesh.cpp \
        shapes.cpp \
        Engine/viewport.cpp

HEADERS += \
        assimp/Compiler/poppack1.h \
        assimp/Compiler/pstdint.h \
        assimp/Compiler/pushpack1.h \
        assimp/DefaultIOStream.h \
        assimp/DefaultIOSystem.h \
        assimp/DefaultLogger.hpp \
        assimp/Defines.h \
        assimp/Exporter.hpp \
        assimp/IOStream.hpp \
        assimp/IOSystem.hpp \
        assimp/Importer.hpp \
        assimp/LogStream.hpp \
        assimp/Logger.hpp \
        assimp/NullLogger.hpp \
        assimp/ProgressHandler.hpp \
        assimp/SceneCombiner.h \
        assimp/ai_assert.h \
        assimp/anim.h \
        assimp/camera.h \
        assimp/cexport.h \
        assimp/cfileio.h \
        assimp/cimport.h \
        assimp/color4.h \
        assimp/defs.h \
        assimp/importerdesc.h \
        assimp/light.h \
        assimp/material.h \
        assimp/matrix3x3.h \
        assimp/matrix4x4.h \
        assimp/mesh.h \
        assimp/metadata.h \
        assimp/port/AndroidJNI/AndroidJNIIOSystem.h \
        assimp/postprocess.h \
        assimp/quaternion.h \
        assimp/scene.h \
        assimp/texture.h \
        assimp/types.h \
        assimp/vector2.h \
        assimp/vector3.h \
        assimp/version.h \
        Engine/engine.h \
        Engine/import.h \
        mainwindow.h \
        Engine/mesh.h \
        Engine/object.h \
        Engine/scene.h \
        Engine/shader.h \
        Engine/viewport.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
 models.qrc \
 shaders.qrc

FORMS += \
	mainwindow.ui
