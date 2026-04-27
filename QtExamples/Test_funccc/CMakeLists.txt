cmake_minimum_required(VERSION 3.16)

project(Test_funccc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Test_funccc main.cpp)

include(GNUInstallDirs)
install(TARGETS Test_funccc
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
