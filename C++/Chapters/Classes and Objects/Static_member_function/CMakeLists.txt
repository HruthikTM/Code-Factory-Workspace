cmake_minimum_required(VERSION 3.16)

project(Static_member_function LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Static_member_function main.cpp)

include(GNUInstallDirs)
install(TARGETS Static_member_function
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
