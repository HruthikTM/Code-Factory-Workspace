cmake_minimum_required(VERSION 3.16)

project(Structure_class_type LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Structure_class_type main.cpp)

include(GNUInstallDirs)
install(TARGETS Structure_class_type
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
