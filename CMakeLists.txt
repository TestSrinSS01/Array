cmake_minimum_required(VERSION 3.17)
project(macros C)

set(CMAKE_C_STANDARD 99)

add_executable(macros main.c Array.h Array.c)