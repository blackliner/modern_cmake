add_executable(addition_test addition_test.cpp)

target_link_libraries(addition_test PRIVATE addition)

mc_add_test(addition_test)
