cmake_minimum_required(VERSION 3.16)

project(Car LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Car main.cpp
    Car.h Car.cpp
    Door.h Door.cpp
    Seat.h Seat.cpp
    Window.h Window.cpp
    Wheel.h Wheel.cpp
    Engine.h Engine.cpp
    Staring.h Staring.cpp
    Light.h Light.cpp
    Break.h Break.cpp
    AlloyWheel.h AlloyWheel.cpp
    SteelWheel.h SteelWheel.cpp
    DiscBreak.h DiscBreak.cpp
    DrumBreak.h DrumBreak.cpp
    WindShield.h WindShield.cpp
    Gear.h Gear.cpp
    ManualTransmission.h ManualTransmission.cpp
    AutoTransmission.h AutoTransmission.cpp
    DashBoard.h DashBoard.cpp
    AirConditioner.h AirConditioner.cpp
    MusicPlayer.h MusicPlayer.cpp
    UsbPort.h UsbPort.cpp
    Tyer.h Tyer.cpp
    TubeTyer.h TubeTyer.cpp
    TubeLessTyer.h TubeLessTyer.cpp
    Headlight.h Headlight.cpp
    TailLight.h TailLight.cpp)

include(GNUInstallDirs)
install(TARGETS Car
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
