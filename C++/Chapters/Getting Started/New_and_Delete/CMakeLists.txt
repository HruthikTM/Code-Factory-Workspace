cmake_minimum_required(VERSION 3.16)

project(New_and_Delete LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(New_and_Delete main.cpp)

include(GNUInstallDirs)
install(TARGETS New_and_Delete
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
