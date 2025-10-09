cmake_minimum_required(VERSION 3.16)

project(Scope_Resolution LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Scope_Resolution main.cpp)

include(GNUInstallDirs)
install(TARGETS Scope_Resolution
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
