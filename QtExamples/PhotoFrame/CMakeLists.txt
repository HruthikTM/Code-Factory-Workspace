cmake_minimum_required(VERSION 3.16)

project(PhotoFrame VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appPhotoFrame
    main.cpp
)

qt_add_qml_module(appPhotoFrame
    URI PhotoFrame
    QML_FILES
        Main.qml
        QML_FILES CustomRectangle.qml
        QML_FILES CustomImage.qml
        RESOURCES images/pic1.jpg images/pic2.jpg images/pic3.jpg images/pic4.jpg images/pic5.jpg images/pic6.jpg images/pic7.jpg
        QML_FILES CustomText.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appPhotoFrame PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appPhotoFrame
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appPhotoFrame
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appPhotoFrame
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
