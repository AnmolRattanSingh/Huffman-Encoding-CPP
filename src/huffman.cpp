#include "huffman_helper.hpp"
#include "min_heap.hpp"

#include <iostream>
#include <string>

int main(void) {
  std::map<int, int> map = map_frequency("Hello");

  MinHeap heap;
  Node n1 = Node();
  n1.freq = 2;
  n1.symbol = 25;
  heap.insert(&n1);

  Node n2 = Node();
  n2.freq = 1;
  n2.symbol = 20;
  heap.insert(&n2);

  for (int i = 0; i < heap.size; i++) {
    std::cout << "Node " << (*heap.get(i)).symbol << std::endl;
  }
  return 0;
}
