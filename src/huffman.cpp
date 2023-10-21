#include "huffman_helper.hpp"
#include "min_heap.hpp"

#include <iostream>
#include <string>

int main(void) {
  std::map<int, int> map = map_frequency("aaaaabbbbcccdde");

  MinHeap heap;
  for (auto const &pair : map) {
    Node *node = new Node{
        .symbol = pair.first,
        .freq = pair.second,
        .left = nullptr,
        .right = nullptr,
    };
    heap.insert(node);
  }
  heap.print();
  return 0;
}
