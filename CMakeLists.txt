cmake_minimum_required(VERSION 3.23)
project(Life)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES include/*.h src/*.cpp)
add_executable(Life ${SOURCES})
