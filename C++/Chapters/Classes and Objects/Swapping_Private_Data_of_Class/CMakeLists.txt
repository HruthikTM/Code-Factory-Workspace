cmake_minimum_required(VERSION 3.16)

project(Swapping_Private_Data_of_Class LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Swapping_Private_Data_of_Class main.cpp
    a.h a.cpp
    b.h b.cpp)

include(GNUInstallDirs)
install(TARGETS Swapping_Private_Data_of_Class
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
