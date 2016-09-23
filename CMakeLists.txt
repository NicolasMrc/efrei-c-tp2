cmake_minimum_required(VERSION 3.6)
project(example)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c fonctions.h fonctions.c )
add_executable(dbsg ${SOURCE_FILES})