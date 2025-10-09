cmake_minimum_required(VERSION 3.16)

project(Temp_to_fahrenheit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Temp_to_fahrenheit main.cpp)

include(GNUInstallDirs)
install(TARGETS Temp_to_fahrenheit
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
