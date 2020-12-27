enable_testing()

macro(mc_add_test target)

  add_test(${target} ${target})

  target_link_libraries(${target} PRIVATE Catch2_main)

endmacro()
