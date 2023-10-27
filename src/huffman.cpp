#include "huffman_helper.hpp"
#include "timing_charts.hpp"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  // std::vector<int> sizes;
  // for (int i = 0; i < 30; i++) {
  //   sizes.push_back((i + 1) * 1000);
  // }
  // averageTimes(convert_to_tree, sizes);

  std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < 26; i++) {
    // Create a test string with `i` repetitions of the first letter
    std::string test = alphabet;
    for (int j = 0; j <= i; j++) {
      test[j] = alphabet[0];
    }

    // Compute Huffman encoding for the test string
    std::map<int, int> freqs = map_frequency(test);
    MinHeap heap;
    for (auto const &pair : freqs) {
      Node *node = new Node{
          .symbol = pair.first,
          .freq = pair.second,
          .left = nullptr,
          .right = nullptr,
      };
      heap.insert(node);
    }
    // Redirect standard output to a null stream
    std::ofstream devnull("/dev/null");
    std::streambuf *oldbuf = std::cout.rdbuf(devnull.rdbuf());

    convert_to_tree(&heap);

    std::map<Node *, std::string> node_map;

    printCodes(heap.get(0), "", &node_map);

    // Restore standard output
    std::cout.rdbuf(oldbuf);

    // Get compression ratio
    getCompressionRatio(26 - i, test, &node_map);
  }
  return 0;
}
