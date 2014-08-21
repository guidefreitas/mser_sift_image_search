#-------------------------------------------------
#
# Project created by QtCreator 2012-06-07T12:42:26
#
#-------------------------------------------------


#-L$$PWD/../../../../../../../../usr/local/lib/ -lmorph4cpp16

QT       += core gui

TARGET = Descritores
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    util.cpp \
    imageprocessor.cpp

HEADERS  += mainwindow.h \
    util.h \
    imageprocessor.h

FORMS    += mainwindow.ui


LIBS += -L/usr/local/lib/ -lopencv_core\
              -L/usr/local/lib/ -lopencv_contrib\
              -L/usr/local/lib/ -lopencv_imgproc\
              -L/usr/local/lib/ -lopencv_ml\
              -L/usr/local/lib/ -lopencv_objdetect\
              -L/usr/local/lib/ -lopencv_video\
              -L/usr/local/lib/ -lopencv_photo\
              -L/usr/local/lib/ -lopencv_ts\
              -L/usr/local/lib/ -lopencv_highgui\
              -L/usr/local/lib/ -lopencv_features2d\
              -L/usr/local/lib/ -lopencv_nonfree\
              -L/usr/local/lib/ -lopencv_legacy\
              -L/usr/local/lib/ -lopencv_flann\
              -L/usr/local/lib/ -lopencv_ts\

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include

#QMAKE_CC = gcc-4.7
#QMAKE_CXX = g++-4.7

QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS += -fopenmp

QMAKE_CFLAGS_DEBUG += -fopenmp
QMAKE_CFLAGS_RELEASE += -fopenmp



#INCLUDEPATH += /usr/local/include/opencv2
#DEPENDPATH += /usr/local/include/opencv2

OTHER_FILES += \
    lembretes.txt \
    temp.txt


