#include "huffman_helper.hpp"
#include "timing_charts.hpp"

#include <iostream>
#include <string>

int main(void) {
  std::map<int, int> map = map_frequency("aaaaabbbbcccdde");

  averageTimes(build_huffman_tree, {10, 100, 1000, 10000, 100000, 1000000}, 26);
  return 0;
}
