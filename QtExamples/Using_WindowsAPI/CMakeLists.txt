cmake_minimum_required(VERSION 3.16)

project(Using_WindowsAPI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Using_WindowsAPI main.cpp)

include(GNUInstallDirs)
install(TARGETS Using_WindowsAPI
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
