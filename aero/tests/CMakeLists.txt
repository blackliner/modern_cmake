add_executable(aero_test aero_test.cpp)

target_link_libraries(aero_test PRIVATE aero)

mc_add_test(aero_test)
