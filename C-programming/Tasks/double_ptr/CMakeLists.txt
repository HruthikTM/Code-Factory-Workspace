cmake_minimum_required(VERSION 3.16)

project(double_ptr LANGUAGES C)

add_executable(double_ptr main.c)

include(GNUInstallDirs)
install(TARGETS double_ptr
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
