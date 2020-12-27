add_executable(iron_dome iron_dome.cpp)

target_link_libraries(iron_dome PRIVATE aero sfml::sfml)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/arial.ttf ${CMAKE_CURRENT_BINARY_DIR}/arial.ttf COPYONLY)

mc_install(iron_dome)
