cmake_minimum_required(VERSION 3.16)

project(Operator_logic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Operator_logic main.cpp)

include(GNUInstallDirs)
install(TARGETS Operator_logic
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
