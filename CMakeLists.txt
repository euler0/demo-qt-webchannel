cmake_minimum_required(VERSION 3.5)

project(demo-qt-webchannel
    LANGUAGES CXX
)

find_package(Qt6 COMPONENTS Core WebEngineWidgets WebChannel REQUIRED)
qt_standard_project_setup()

add_executable(demo-qt-webchannel)

set_target_properties(demo-qt-webchannel
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_precompile_headers(demo-qt-webchannel
    PRIVATE
        precompiled.h
)

target_sources(demo-qt-webchannel
    PRIVATE
        chartdatasource.cpp
        chartview.cpp
        main.cpp
        mainwindow.cpp
        demo-qt-webchannel.qrc
)

target_link_libraries(demo-qt-webchannel
    PRIVATE
        Qt6::WebEngineWidgets
        Qt6::WebChannel
)
