cmake_minimum_required(VERSION 3.16)

project(Dynamic_Constructors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Dynamic_Constructors main.cpp)

include(GNUInstallDirs)
install(TARGETS Dynamic_Constructors
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
