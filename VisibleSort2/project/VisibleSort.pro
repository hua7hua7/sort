QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17
QT += core gui webview
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ChartWidget.cpp \
    arraytosort.cpp \
    binarysort.cpp \
    bubblesort.cpp \
    heapsort.cpp \
    insertsort.cpp \
    main.cpp \
    mainwindow.cpp \
    mergesort.cpp \
    page1.cpp \
    page2.cpp \
    page3.cpp \
    painter.cpp \
    quicksort.cpp \
    radixsort.cpp \
    selectionsort.cpp \
    shellsort.cpp \
    sortalgorithms.cpp \
    sortstats.cpp \
    visible.cpp \
    visible2.cpp \
    visible3.cpp

HEADERS += \
    ChartWidget.h \
    SortAlgorithms.h \
    arraytosort.h \
    binarysort.h \
    bubblesort.h \
    heapsort.h \
    insertsort.h \
    mainwindow.h \
    mergesort.h \
    page1.h \
    page2.h \
    page3.h \
    painter.h \
    quicksort.h \
    radixsort.h \
    selectionsort.h \
    shellsort.h \
    sortstats.h \
    visible.h \
    visible2.h \
    visible3.h

FORMS += \
    mainwindow.ui \
    page1.ui \
    page2.ui \
    page3.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
