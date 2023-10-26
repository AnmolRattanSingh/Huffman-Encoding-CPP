set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-conversion")

list(APPEND CMAKE_CTEST_ARGUMENTS --verbose)

add_executable(test_huffman_helper test_huffman_helper.cpp)
target_link_libraries(test_huffman_helper
   PRIVATE huffman_helper min_heap
   PUBLIC ${CRITERION}
)
add_test(
   NAME test_huffman_helper
   COMMAND test_huffman_helper ${CRITERION_FLAGS}
)
