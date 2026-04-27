cmake_minimum_required(VERSION 3.16)

project(struct_size LANGUAGES C)

add_executable(struct_size main.c)

include(GNUInstallDirs)
install(TARGETS struct_size
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
