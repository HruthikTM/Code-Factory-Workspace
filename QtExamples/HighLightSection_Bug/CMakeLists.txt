# cmake_minimum_required(VERSION 3.19)
# project(HighLightSection_Bug LANGUAGES CXX)

# find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

# qt_standard_project_setup()

# qt_add_executable(HighLightSection_Bug
#     WIN32 MACOSX_BUNDLE
#     main.cpp
#     mainwindow.cpp
#     mainwindow.h
#     mainwindow.ui
# )

# target_link_libraries(HighLightSection_Bug
#     PRIVATE
#         Qt::Core
#         Qt::Widgets
# )

# include(GNUInstallDirs)

# install(TARGETS HighLightSection_Bug
#     BUNDLE  DESTINATION .
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
# )

# qt_generate_deploy_app_script(
#     TARGET HighLightSection_Bug
#     OUTPUT_SCRIPT deploy_script
#     NO_UNSUPPORTED_PLATFORM_ERROR
# )
# install(SCRIPT ${deploy_script})

cmake_minimum_required(VERSION 3.19)
project(HighLightSection_Bug LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(HighLightSection_Bug
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

target_link_libraries(HighLightSection_Bug
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS HighLightSection_Bug
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET HighLightSection_Bug
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})


# cmake_minimum_required(VERSION 3.19)
# project(HighLightSection_Bug LANGUAGES CXX)

# find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

# qt_standard_project_setup()

# qt_add_executable(HighLightSection_Bug
#     main.cpp
#     mainwindow.cpp
#     mainwindow.h
#     mainwindow.ui
# )

# target_link_libraries(HighLightSection_Bug
#     PRIVATE
#         Qt::Core
#         Qt::Widgets
# )

# if (WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Release")
#     set_target_properties(HighLightSection_Bug
#         PROPERTIES
#             WIN32_EXECUTABLE TRUE
#     )
# endif()

# include(GNUInstallDirs)

# install(TARGETS HighLightSection_Bug
#     BUNDLE  DESTINATION .
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
# )

# qt_generate_deploy_app_script(
#     TARGET HighLightSection_Bug
#     OUTPUT_SCRIPT deploy_script
#     NO_UNSUPPORTED_PLATFORM_ERROR
# )
# install(SCRIPT ${deploy_script})

