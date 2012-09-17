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


macx: LIBS += -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_core\
              -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_contrib\
              -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_imgproc\
              -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_ml\
              -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_objdetect\
              -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_video\
              -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_photo\
              -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_ts\
              -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_highgui\
              -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_features2d\
              -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_nonfree\
              -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_legacy\
              -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_flann\
              -L$$PWD/../../../../../../../../usr/local/lib/ -lopencv_ts\

INCLUDEPATH += $$PWD/../../../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../../../usr/local/include

#INCLUDEPATH += /usr/local/include/opencv2
#DEPENDPATH += /usr/local/include/opencv2

OTHER_FILES += \
    lembretes.txt \
    temp.txt


