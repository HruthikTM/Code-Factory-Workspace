cmake_minimum_required(VERSION 3.16)

project(Static_Class_members LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Static_Class_members main.cpp)

include(GNUInstallDirs)
install(TARGETS Static_Class_members
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
