cmake_minimum_required(VERSION 3.12)

project(Lab1)

add_subdirectory(googletest)

include_directories(googletest/include)

add_executable(tests_work test.cpp)

target_link_libraries(tests_work PRIVATE gtest)
