cmake_minimum_required(VERSION 3.18)

include(cmake/launcher.cmake)

project(
  modern_cmake
  VERSION 1.0.0
  LANGUAGES CXX)

include(cmake/utils.cmake)
include(cmake/install.cmake)
include(cmake/testing.cmake)

find_package(Catch2 2.13.3 REQUIRED)
find_package(Eigen3 3.3.9 REQUIRED)
find_package(sfml 2.5.1 REQUIRED)

add_subdirectory(catch2_main)
add_subdirectory(addition)
add_subdirectory(addition_types)
add_subdirectory(aero)
add_subdirectory(iron_dome)

include(cmake/package.cmake)
