/*
 * Helper functions for Huffman Encoding
 */

#pragma once

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
 * Print the Huffman tree in a tree format.
 *
 *
 * Print's each node's symbol and frequency in the tree in a tree format using
 * the helper function printHuffmanHelper.
 *
 *
 * @param heap: A pointer to a MinHeap to be printed
 */
void printHuffman(MinHeap *heap);

/**
 * Helper function to print the Huffman tree in a tree format.
 *
 *
 * Recursively prints the tree by traversing the tree through the left and right
 * child nodes of each node.
 *
 *
 * @param root: A pointer to the root node of the Huffman tree
 * @param prefix: A string representing the prefix to be printed before the
 * each node
 */
void printHuffmanHelper(Node *root, std::string prefix);

/**
 * Helper function to print the Huffman codes for each character in the tree.
 *
 * Recursively prints the codes for each character in the tree by traversing the
 * tree through the left and right child nodes of each node.
 *
 * @param root: A pointer to the root node of the Huffman tree
 * @param str: A string representing the prefix to be printed before the
 * each node
 */
void printCodes(Node *root, std::string str,
                std::map<Node *, std::string> *node_map);

/**
 * Get the compression ratio of the inputted string.
 *
 * @param input: A string to be mapped to the frequency of occurrence of each
 * character in it
 * @param node_map: A map mapping each node in the Huffman tree to its
 * corresponding Huffman code
 */
void getCompressionRatio(std::string input,
                         std::map<Node *, std::string> *node_map);
