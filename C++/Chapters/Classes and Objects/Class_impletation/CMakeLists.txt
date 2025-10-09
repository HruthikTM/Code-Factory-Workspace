cmake_minimum_required(VERSION 3.16)

project(Class_impletation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Class_impletation main.cpp)

include(GNUInstallDirs)
install(TARGETS Class_impletation
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
