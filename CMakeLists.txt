cmake_minimum_required(VERSION 3.7)
#[[  Commented for future use
project(entropy)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    kernel/arch/i386/gdt.c
    kernel/arch/i386/hal.c
    kernel/arch/i386/idt.c
    kernel/arch/i386/isrs.c
    kernel/arch/i386/tty.c
    kernel/arch/i386/vga.h
    kernel/include/kernel/gdt.h
    kernel/include/kernel/hal.h
    kernel/include/kernel/idt.h
    kernel/include/kernel/isrs.h
    kernel/include/kernel/tty.h
    kernel/kernel/kernel.cpp
    libc/arch/i386/make.config
    libc/assert/assert.c
    libc/include/sys/cdefs.h
    libc/include/assert.h
    libc/include/stdio.h
    libc/include/stdlib.h
    libc/include/string.h
    libc/stdio/printf.c
    libc/stdio/putchar.c
    libc/stdio/puts.c
    libc/stdlib/abort.c
    libc/stdlib/itoa.c
    libc/string/memcmp.c
    libc/string/memcpy.c
    libc/string/memmove.c
    libc/string/memset.c
    libc/string/strcmp.c
    libc/string/strlen.c
    libc/tests/string/strcmp.c
    libc/tests/libctest.c
    libc/tests/libctest.h
    libc/tests/main.c)

include_directories(kernel/include)
include_directories(libc/include)

add_executable(entropy ${SOURCE_FILES})]]

add_subdirectory(libc)
