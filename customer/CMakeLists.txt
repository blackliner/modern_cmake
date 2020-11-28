cmake_minimum_required(VERSION 3.18)

project(customer CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(modern_cmake 1.0.0 REQUIRED)

add_executable(calculator calculator.cpp)

target_link_libraries(calculator PRIVATE modern_cmake::addition)
