add_library(Catch2_main STATIC ${CMAKE_CURRENT_LIST_DIR}/catch2_main.cpp)

target_link_libraries(Catch2_main PUBLIC Catch2::Catch2)
