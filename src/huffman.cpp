#include "huffman_helper.hpp"
#include "min_heap.hpp"

#include <iostream>
#include <string>

int main(void) {
  std::map<int, int> map = map_frequency("Hello");

  MinHeap heap;
  Node node = {
      .symbol = 13,
      .freq = 2,
      .left = nullptr,
      .right = nullptr,
  };
  Node node2 = {
      .symbol = 14,
      .freq = 10,
      .left = nullptr,
      .right = nullptr,
  };
  Node node3 = {
      .symbol = 15,
      .freq = 0,
      .left = nullptr,
      .right = nullptr,
  };
  heap.insert(&node);
  heap.print();
  heap.insert(&node2);
  heap.print();
  heap.insert(&node3);
  heap.print();
  return 0;
}
