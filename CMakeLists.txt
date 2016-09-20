cmake_minimum_required(VERSION 3.6)
project(TD2C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES Main.c fonctions.c)
add_executable(TD1C ${SOURCE_FILES})