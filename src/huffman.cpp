#include "huffman_helper.hpp"
#include "min_heap.hpp"

#include <iostream>

int main(void) {
  std::map<int, int> map = map_frequency("Hello");

  MinHeap heap;
  heap.heap.push_back(1);
  // heap.pop();
  //   std::cout << "Heap size: " << heap.size << std::endl;
  return 0;
}
