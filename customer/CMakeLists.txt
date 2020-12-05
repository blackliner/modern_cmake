cmake_minimum_required(VERSION 3.18)

project(customer CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(modern_cmake 1.0.0 REQUIRED)

add_executable(calculator calculator.cpp)

target_link_libraries(calculator PRIVATE modern_cmake::addition)

add_executable(add_test add_test.cpp)

target_link_libraries(add_test PRIVATE modern_cmake::addition)

enable_testing()
add_test(add_test add_test)
