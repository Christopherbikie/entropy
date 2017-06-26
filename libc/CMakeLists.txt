cmake_minimum_required(VERSION 3.7)
project(libc)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_C_COMPILER $ENV{HOME}/opt/cross/bin/i686-elf-gcc)
set(CMAKE_C_FLAGS "-O2 -g -ffreestanding -Wall -Wextra")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
    assert/assert.c
    stdio/printf.c
    stdio/putchar.c
    stdio/puts.c
    stdlib/abort.c
    stdlib/itoa.c
    string/memcmp.c
    string/memcpy.c
    string/memmove.c
    string/memset.c
    string/strcmp.c
    string/strlen.c)

include_directories(include)

add_library(k_x86-64 ${SOURCE_FILES})

add_subdirectory(tests)
