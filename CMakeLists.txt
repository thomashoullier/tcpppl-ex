cmake_minimum_required(VERSION 3.20)
project(tcpppl-ex)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set (SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src/")

add_executable(x_3_3 "${SRC_DIR}/x_3_3.cpp")
