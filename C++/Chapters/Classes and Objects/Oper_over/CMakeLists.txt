cmake_minimum_required(VERSION 3.16)

project(Oper_over LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Oper_over main.cpp)

include(GNUInstallDirs)
install(TARGETS Oper_over
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
