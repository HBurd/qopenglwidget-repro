cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

list(APPEND CMAKE_PREFIX_PATH $ENV{QT_ROOT})

project(qt_qopenglwidget_repro VERSION 1.0.0 LANGUAGES CXX)

# Qt Setup
find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGLWidgets)
qt_standard_project_setup()

# Executable target for demo application
qt_add_executable(qt_openglwidget_repro
    main.cpp
    demowindow.cpp demowindow.h
)

target_link_libraries(qt_openglwidget_repro PUBLIC
    Qt6::Widgets
    Qt6::OpenGLWidgets
)

# Run windeployqt so that all the required DLLs will get copied
if(WIN32)
    get_target_property(QT6_WIDGETS_LIB Qt6::Widgets LOCATION)
    get_filename_component(QT6_BIN_DIR ${QT6_WIDGETS_LIB} PATH)
    set(QT6_WINDEPLOYQT_EXECUTABLE "${QT6_BIN_DIR}/windeployqt.exe")

    add_custom_command(TARGET qt_openglwidget_repro POST_BUILD
        COMMAND ${QT6_WINDEPLOYQT_EXECUTABLE} $<TARGET_FILE_DIR:qt_openglwidget_repro> --no-translations)
endif()
