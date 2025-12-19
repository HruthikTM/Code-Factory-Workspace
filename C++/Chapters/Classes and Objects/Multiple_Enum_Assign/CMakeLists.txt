cmake_minimum_required(VERSION 3.16)

project(Multiple_Enum_Assign LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Multiple_Enum_Assign main.cpp)

include(GNUInstallDirs)
install(TARGETS Multiple_Enum_Assign
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
