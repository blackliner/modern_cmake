add_library(addition src/addition.cpp include/addition/addition.h)

target_link_libraries(addition PUBLIC addition_types)

target_include_directories(
  addition PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                  $<INSTALL_INTERFACE:include>)

add_subdirectory(tests)

mc_install(addition)
