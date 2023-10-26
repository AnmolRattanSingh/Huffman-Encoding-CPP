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

void printCodes(Node* root, std::string str) {
  if (root == nullptr) {
    return;
  }
  if (root->symbol != '$') {
    std::cout << (char)root->symbol << ": " << str << std::endl;
  }
  printCodes(root->left, str + "0");
  printCodes(root->right, str + "1");
}
