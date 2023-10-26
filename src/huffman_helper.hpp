/*
 * Helper functions for Huffman Encoding
 */
#include "min_heap.hpp"
#include <string>

using namespace std;

/**
 * Return a map from character (acsii) to frequency in the inputted string.
 *
 * @param input: A string to be mapped to the frequency of occurrence of each
 * character in it
 * @return: A map mapping an integer representation of each character in the
 * input string to the total occurrences of it in the string.
 */
map<int, int> map_frequency(string input);

/**
 * Convert a min heap to a binary tree where each root node's frequency
 * represents the sum of the frequencies of each of the child nodes.
 *
 * This tree is created so that the higher frequencies are found at the surface
 * of the tree and the lower frequencies are nested further down in the tree.
 *
 * @param heap: A pointer to a MinHeap to be converted into the binary tree
 */
void convert_to_tree(MinHeap *heap);

/**
 *
 */
void printHuffman(MinHeap *heap);

/**
 *
 */
void printHuffmanHelper(Node *root, string prefix);
