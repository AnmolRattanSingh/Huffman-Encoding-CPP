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

add_executable(test_min_heap test_min_heap.cpp)
target_link_libraries(test_min_heap
   PRIVATE min_heap
   PUBLIC ${CRITERION}
)
add_test(
   NAME test_min_heap
   COMMAND test_min_heap ${CRITERION_FLAGS}
)

