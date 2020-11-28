cmake_minimum_required(VERSION 3.18)

project(
  modern_cmake
  VERSION 1.0.0
  LANGUAGES CXX)

include(cmake/utils.cmake)
include(cmake/install.cmake)
include(cmake/testing.cmake)

find_package(Catch2 2.13.3 REQUIRED)

add_subdirectory(addition)
add_subdirectory(addition_types)

include(cmake/package.cmake)
