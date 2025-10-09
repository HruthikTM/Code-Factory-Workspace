cmake_minimum_required(VERSION 3.16)

project(inline_func LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(inline_func main.cpp)

include(GNUInstallDirs)
install(TARGETS inline_func
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
