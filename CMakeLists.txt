cmake_minimum_required(VERSION 3.25)
project(myPopen_myPclose C)

set(CMAKE_C_STANDARD 11)

add_executable(myPopen_myPclose main.c mypopen.c mypopen.h mypclose.c definitions.h helpers.c helpers.h cmake-build-debug/mypclose.h)
