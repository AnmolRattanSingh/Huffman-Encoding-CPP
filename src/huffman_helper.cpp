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

void convert_to_tree(MinHeap *heap) {
  while (heap->size > 1) {
    Node *left = heap->pop();
    Node *right = heap->pop();

    // Create new node with left and right as the two new minimum frequencies
    // and frequency as the sum of the two
    Node *temp = new Node{.symbol = '$',
                          .freq = left->freq + right->freq,
                          .left = left,
                          .right = right};
    heap->insert(temp);
  }
}

void printHuffman(MinHeap *heap) {
  std::cout << " /" << std::endl;
  printHuffmanHelper(heap->get(0), " |  ");
  std::cout << " //" << std::endl;
}

void printHuffmanHelper(Node *node, std::string prefix) {
  if (node != nullptr) {
    printHuffmanHelper(node->right, prefix + "│   ");
    std::cout << prefix << (char)node->symbol << ":" << node->freq << std::endl;
    printHuffmanHelper(node->left, prefix + "│   ");
  } else {
    std::cout << prefix << "─" << std::endl;
  }
}

void printCodes(Node *root, std::string str,
                std::map<Node *, std::string> *node_map) {
  if (root == nullptr) {
    return;
  }

  if (root->symbol != '$') {
    std::cout << (char)root->symbol << ": " << str << std::endl;
    node_map->insert(std::pair<Node *, std::string>(root, str));
  }

  printCodes(root->left, str + "0", node_map);
  printCodes(root->right, str + "1", node_map);
}

void getCompressionRatio(int num_unique, std::string input,
                         std::map<Node *, std::string> *node_map) {
  // find total size of input data
  double input_size = input.length() * 8;

  // find total size of compressed data including the lookup table
  double compressed_size = 0;
  // loop through node_map and multiply each node's frequency by the length of
  // its code
  for (auto const &pair : *node_map) {
    compressed_size += pair.first->freq * pair.second.length();
  }
  // add 8 bits (ASCII) for each unique character in the map
  compressed_size += node_map->size() * 8;

  std::cout << num_unique << "," << (compressed_size / input_size) << std::endl;
}
