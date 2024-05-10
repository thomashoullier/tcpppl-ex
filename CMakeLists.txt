cmake_minimum_required(VERSION 3.20)
project(tcpppl-ex)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set (SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src/")

# List of exercises as compilation targets
add_executable(x_3_3 "${SRC_DIR}/x_3_3.cpp")
add_executable(x_3_5 "${SRC_DIR}/x_3_5.cpp")
add_executable(x_3_6 "${SRC_DIR}/x_3_6.cpp")
add_executable(x_5_5 "${SRC_DIR}/x_5_5.cpp")
add_executable(x_5_6 "${SRC_DIR}/x_5_6.cpp")
add_executable(x_5_7 "${SRC_DIR}/x_5_7.cpp")
