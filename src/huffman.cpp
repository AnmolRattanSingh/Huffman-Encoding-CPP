#include "huffman_helper.hpp"
#include "timing_charts.hpp"

#include <iostream>
#include <string>

using namespace std;

int main(void) {
  map<int, int> map = map_frequency("aa");

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
  // heap.printHeap();
  convert_to_tree(&heap);
  std::cout << "Changed " << (heap.size > 0) << std::endl;

  // printHuffman(&heap);

  // averageTimes(build_huffman_tree, {10, 100, 1000, 10000, 100000,
  // 1000000}, 26);
  return 0;
}
