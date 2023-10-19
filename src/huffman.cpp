#include "huffman_helper.hpp"
#include "min_heap.hpp"

#include <iostream>

int main(void) {
  std::map<int, int> map = map_frequency("Hello");

  return 0;
  //   MinHeap heap;
  //   heap.pop();
  //   std::cout << "Hello, world!" << std::endl;
  //   std::cout << "Heap size: " << heap.size << std::endl;
  //   return 0;
}
