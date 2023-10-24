/*
 *
 */

#include <map>
#include <string>
#include "huffman_helper.hpp"

std::map<int, int> map_frequency(std::string input) {
  std::map<int, int> map;

  for (int i = 0; i < input.length(); i++) {
    map[(int)input[i]] += 1;
  }

  return map;
}

// build huffman tree
MinHeap* build_huffman_tree(std::map<int, int> map_frequency) {
  MinHeap *heap = new MinHeap();
  return heap;
}
