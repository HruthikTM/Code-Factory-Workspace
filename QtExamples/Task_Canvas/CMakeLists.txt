cmake_minimum_required(VERSION 3.16)

project(Task_Canvas VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appTask_Canvas
    main.cpp
)

qt_add_qml_module(appTask_Canvas
    URI Task_Canvas
    VERSION 1.0
    QML_FILES main.qml
    QML_FILES FreeDrawCanvas.qml
    QML_FILES ConnectDotsCanvas.qml
    QML_FILES ImageCanvas.qml
    SOURCES CanvasData.h CanvasData.cpp
    SOURCES CanvasReceiver.h CanvasReceiver.cpp
    SOURCES CanvasModel.h CanvasModel.cpp
    SOURCES CanvasBackend.h CanvasBackend.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTask_Canvas PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTask_Canvas
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTask_Canvas
    PRIVATE Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS appTask_Canvas
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
