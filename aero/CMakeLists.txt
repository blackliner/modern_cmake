add_library(aero src/aero.cpp include/aero/aero.h)

target_link_libraries(aero PUBLIC Eigen3::Eigen3)

target_include_directories(
  aero PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                  $<INSTALL_INTERFACE:include>)

add_subdirectory(tests)

mc_install(aero)
