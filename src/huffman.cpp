#include "huffman_helper.hpp"
#include "min_heap.hpp"

#include <iostream>
#include <string>

int main(void) {
  std::map<int, int> map = map_frequency("Hello");

  MinHeap heap;
  Node node = {
      .symbol = 13,
      .freq = 0,
      .left = nullptr,
      .right = nullptr,
  };
  Node node2 = {
      .symbol = 14,
      .freq = 1,
      .left = nullptr,
      .right = nullptr,
  };
  heap.insert(&node);
  heap.insert(&node2);
  std::cout << "before: "
            << "idx0: " << heap.get(0)->symbol
            << " idx1: " << heap.get(1)->symbol << std::endl;
  heap.swap(0, 1);
  std::cout << "after: "
            << "idx0: " << heap.get(0)->symbol
            << " idx1: " << heap.get(1)->symbol << std::endl;
  return 0;
}
