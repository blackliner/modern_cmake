add_library(addition_types INTERFACE)

target_include_directories(
  addition_types
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>)

mc_install(addition_types)
