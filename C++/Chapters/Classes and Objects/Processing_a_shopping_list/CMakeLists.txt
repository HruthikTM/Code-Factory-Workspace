cmake_minimum_required(VERSION 3.16)

project(Processing_a_shopping_list LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Processing_a_shopping_list main.cpp)

include(GNUInstallDirs)
install(TARGETS Processing_a_shopping_list
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
