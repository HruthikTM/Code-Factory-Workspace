cmake_minimum_required(VERSION 3.16)

project(Class_Objects_Constructors_Desstructors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Class_Objects_Constructors_Desstructors main.cpp
    car.h car.cpp
    book.h book.cpp
    laptop.h laptop.cpp
    bankaccount.h bankaccount.cpp
    student.h student.cpp
    teacher.h teacher.cpp
    mobile.h mobile.cpp
    restaurant.h restaurant.cpp
    movie.h movie.cpp
    song.h song.cpp
    creditcard.h creditcard.cpp
    chair.h chair.cpp
    airplane.h airplane.cpp
    train.h train.cpp
    library.h library.cpp
    camera.h camera.cpp
    watch.h watch.cpp
    game.h game.cpp
    employee.h employee.cpp)

include(GNUInstallDirs)
install(TARGETS Class_Objects_Constructors_Desstructors
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
