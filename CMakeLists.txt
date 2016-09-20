cmake_minimum_required(VERSION 3.6)
project(TD1C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES tp2.c)
add_executable(TD1C ${SOURCE_FILES})