#include "huffman_helper.hpp"
#include "timing_charts.hpp"

#include <iostream>
#include <string>

using namespace std;

int main(void) {
  std::vector<int> sizes;
  for (int i = 0; i < 50; i++) {
    sizes.push_back((i + 1) * 1000);
  }
  averageTimes(convert_to_tree, sizes, 26);

  // test out printCodes
  std::string test = "hello";
  std::map<int, int> freqs = map_frequency(test);
  MinHeap *heap = new MinHeap();
  for (auto const &pair : freqs) {
    Node *node = new Node{
        .symbol = pair.first,
        .freq = pair.second,
        .left = nullptr,
        .right = nullptr,
    };
    heap->insert(node);
  }
  convert_to_tree(heap);
  printHuffman(heap);
  printCodes(heap->get(0), "");
  return 0;
}
