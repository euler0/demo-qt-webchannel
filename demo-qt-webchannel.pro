QT += webenginewidgets webchannel

CONFIG += c++11 precompile_header release

PRECOMPILED_HEADER = precompiled.h

HEADERS += \
    chartdatasource.h \
    chartview.h \
    mainwindow.h

SOURCES += \
    chartdatasource.cpp \
    chartview.cpp \
    main.cpp \
    mainwindow.cpp

RESOURCES += demo-qt-webchannel.qrc
