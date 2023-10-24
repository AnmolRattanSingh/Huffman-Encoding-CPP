/*
 *
 */

#include "huffman_helper.hpp"
#include "min_heap.hpp"

#include <iostream>
#include <map>

std::map<int, int> map_frequency(std::string input) {
  std::map<int, int> map;

  for (int i = 0; i < input.length(); i++) {
    map[(int)input[i]] += 1;
  }

  return map;
}

// Build huffman tree
MinHeap *build_huffman_tree(std::map<int, int> map_frequency) {
  MinHeap *heap = new MinHeap();
  return heap;
}

void printHuffman(MinHeap *heap) {
  std::cout << " /" << std::endl;
  printHuffmanHelper((*heap).get(0), " |  ");
  std::cout << " //" << std::endl;
}

void printHuffmanHelper(Node *node, std::string prefix) {
  if (node != nullptr) {
    printHuffmanHelper(node->left, prefix + "│   ");
    std::cout << prefix << (char)node->symbol << ":" << node->freq << std::endl;
    printHuffmanHelper(node->right, prefix + "│   ");
  } else {
    std::cout << prefix << "─" << std::endl;
  }
}
