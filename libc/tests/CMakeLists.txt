cmake_minimum_required(VERSION 3.7)
project(libctest)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_C_COMPILER $ENV{HOME}/opt/cross/bin/i686-elf-gcc)
set(CMAKE_C_FLAGS "-O2 -g -ffreestanding -Wall -Wextra")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
    main.c
    libctest.c
    string/strcmp.c)

include_directories(../include include)
link_directories(../)

add_executable(libctest ${SOURCE_FILES})
target_link_libraries (libctest libk_x86-64.a)
