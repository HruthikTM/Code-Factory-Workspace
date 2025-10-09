cmake_minimum_required(VERSION 3.16)

project(Objects_as_arguments LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Objects_as_arguments main.cpp)

include(GNUInstallDirs)
install(TARGETS Objects_as_arguments
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
