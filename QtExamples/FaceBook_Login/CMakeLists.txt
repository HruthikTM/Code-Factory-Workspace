cmake_minimum_required(VERSION 3.16)

project(FaceBook_Login VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(Qt6 REQUIRED COMPONENTS Quick)

find_package(Qt6 REQUIRED COMPONENTS
    Quick
    QuickControls2
)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appFaceBook_Login
    main.cpp
)

qt_add_qml_module(appFaceBook_Login
    URI FaceBook_Login
    QML_FILES
        Main.qml
        QML_FILES CustomTextField.qml
        QML_FILES CustomRectangle.qml
        QML_FILES CustomButton.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appFaceBook_Login PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appFaceBook_Login
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# target_link_libraries(appFaceBook_Login
#     PRIVATE Qt6::Quick
# )

target_link_libraries(appFaceBook_Login
    PRIVATE
        Qt6::Quick
        Qt6::QuickControls2
)

include(GNUInstallDirs)
install(TARGETS appFaceBook_Login
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
