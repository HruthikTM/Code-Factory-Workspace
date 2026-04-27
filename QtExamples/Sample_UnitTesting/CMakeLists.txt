cmake_minimum_required(VERSION 3.16)

project(Sample_UnitTesting LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your test executable with both main.cpp and test files
add_executable(Sample_UnitTesting
    main.cpp
    test/math_test.cpp
)

# Add GoogleTest (assuming googletest folder is inside Sample_UnitTesting)
add_subdirectory(googletest)

# Link GoogleTest libraries
target_link_libraries(Sample_UnitTesting
    gtest
    gtest_main
)

include(GNUInstallDirs)
install(TARGETS Sample_UnitTesting
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
