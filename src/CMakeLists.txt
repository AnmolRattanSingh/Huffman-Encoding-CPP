add_library(min_heap min_heap.cpp min_heap.hpp)
add_library(huffman_helper huffman_helper.cpp huffman_helper.hpp)
add_library(timing_charts timing_charts.cpp timing_charts.hpp)

add_executable(huffman huffman.cpp)
target_link_libraries(huffman min_heap huffman_helper timing_charts)
