/*
 * Helper functions for Huffman Encoding
 */
#include "min_heap.hpp"
#include <string>

/*
 *
 */
std::map<int, int> map_frequency(std::string input);

void convert_to_tree(MinHeap *heap);

void printHuffman(MinHeap *heap);

void printHuffmanHelper(Node *root, std::string prefix);
