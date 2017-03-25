cmake_minimum_required(VERSION 3.5)
project(vtu_usp_lab)

set(CMAKE_C_STANDARD 99)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(q1 src/q1.c)
add_executable(q2 src/q2.c)
add_executable(q4_writer src/q4_writer.c)
add_executable(q4_reader src/q4_reader.c)
add_executable(q5a src/q5a.c)
add_executable(q5b src/q5b.c)