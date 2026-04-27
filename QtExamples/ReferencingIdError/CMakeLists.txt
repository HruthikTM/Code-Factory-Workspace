cmake_minimum_required(VERSION 3.16)

project(ReferencingIdError LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Qml)

qt_standard_project_setup()

qt_add_executable(ReferencingIdError
    main.cpp
)

target_link_libraries(ReferencingIdError
    PRIVATE
        Qt6::Gui
        Qt6::Qml
)
