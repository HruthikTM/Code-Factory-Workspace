cmake_minimum_required(VERSION 3.16)

project(Returning_object LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Returning_object main.cpp
    matrix.h matrix.cpp)

include(GNUInstallDirs)
install(TARGETS Returning_object
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
