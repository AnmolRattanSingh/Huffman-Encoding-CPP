#include "huffman_helper.hpp"
#include <iostream>
#include <string>

/**
 * Calculates the average time taken to build a Huffman tree from a random
 * string of given size.
 *
 * @param convert_to_tree A function pointer to the function that converts the
 * MinHeap to a Huffman tree.
 * @param size The size of the random string to be generated.
 * @return The average time taken to build a Huffman tree in milliseconds.
 */
double averageTime(void (*convert_to_tree)(MinHeap *heap), int size);

/**
 * Calculates the average time taken to build a Huffman tree from random strings
 * of given sizes.
 *
 * Uses the averageTime function to calculate the average time taken to build a
 * Huffman tree for each size in the sizes vector.
 *
 * @param convert_to_tree A function pointer to the function that converts the
 * MinHeap to a Huffman tree.
 * @param sizes A vector of integers representing the sizes of the random
 * strings to be generated.
 * @return A vector of doubles representing the average time taken to build a
 * Huffman tree for each size in the sizes vector, in milliseconds.
 */
std::vector<double> averageTimes(void (*convert_to_tree)(MinHeap *heap),
                                 std::vector<int> sizes);
