add_library(minHeap minHeap.cpp minHeap.hpp)

add_executable(huffman huffman.cpp)
target_link_libraries(huffman minHeap)
