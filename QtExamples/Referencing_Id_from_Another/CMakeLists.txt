cmake_minimum_required(VERSION 3.16)

project(Referencing_Id_from_Another VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appReferencing_Id_from_Another
    main.cpp
)

qt_add_qml_module(appReferencing_Id_from_Another
    URI Referencing_Id_from_Another
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES
        QML_FILES Myqml.qml
        QML_FILES
        QML_FILES CustomItem.qml
        QML_FILES Another.qml
        QML_FILES Wrapper.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appReferencing_Id_from_Another PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appReferencing_Id_from_Another
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appReferencing_Id_from_Another
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appReferencing_Id_from_Another
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
