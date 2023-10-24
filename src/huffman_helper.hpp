/*
 * Helper functions for Huffman Encoding
 */
#include <string>
#include "min_heap.hpp"

/*
 *
 */
std::map<int, int> map_frequency(std::string input);

MinHeap* build_huffman_tree(std::map<int, int> map_frequency);
