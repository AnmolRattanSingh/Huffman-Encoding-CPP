/*
 * Helper functions for Huffman Encoding
 */
#include "min_heap.hpp"
#include <string>

/*
 *
 */
std::map<int, int> map_frequency(std::string input);

MinHeap *build_huffman_tree(std::map<int, int> map_frequency);

void printHuffman();

void printHuffmanHelper(Node *root, std::string prefix);
