cmake_minimum_required(VERSION 3.16)

project(Matrix_Multiplication LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(matrix_app
    Matrix.h
    main.cpp
    Matrix.cpp
)

target_include_directories(matrix_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(googletest)

add_executable(matrix_tests
    test/Matrix_test.cpp
    Matrix.cpp
)

target_include_directories(matrix_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(matrix_tests
    gtest
    gtest_main
)

