cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-pg -O0 -Wall -std=c++11 -fPIC ")

add_executable(runTests tests.cpp)
target_link_libraries(runTests)
