/*
 * Test file for huffman_helper library testing Huffman Encoding helper
 * functions
 */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <iostream>
#include <string>
#include <vector>

#include "../src/huffman_helper.hpp"
#include "../src/min_heap.hpp"

std::vector<std::string> strings = {"", "aaa", "aba",
                                    "aaabbbbbbbbbbbcccdcccdewleiew"};

std::vector<std::map<int, int>> map_answers = {
    std::map<int, int>{}, std::map<int, int>{{97, 3}},
    std::map<int, int>{{97, 2}, {98, 1}},
    std::map<int, int>{{97, 3},
                       {98, 11},
                       {99, 6},
                       {100, 2},
                       {101, 3},
                       {105, 1},
                       {108, 1},
                       {119, 2}}};

Test(test_huffman_helper, LengthMapFrequency) {
  // Ensure frequency mapping gets all unique characters
  std::vector<int> map_lengths = {0, 1, 2, 8};

  for (int i = 0; i < 4; i++) {
    cr_assert(map_frequency(strings[i]).size() == map_lengths[i]);
  }
}

Test(test_huffman_helper, MapFrequency) {
  for (int i = 0; i < 4; i++) {
    cr_assert(map_frequency(strings[i]) == map_answers[i]);
  }
}

Test(test_huffman_helper, ConvertTreeFrequency) {
  for (int i = 0; i < 4; i++) {
    std::map<int, int> this_map = map_frequency(strings[i]);
    MinHeap this_heap;
    for (auto const &pair : this_map) {
      Node *node = new Node{
          .symbol = pair.first,
          .freq = pair.second,
          .left = nullptr,
          .right = nullptr,
      };
      this_heap.insert(node);
    }
    convert_to_tree(&this_heap);

    int freq = 0;
    if ((this_heap.size > 0) == 1) {
      freq = this_heap.get(0)->freq;
    }
    cr_assert(freq == strings[i].size());
  }
}
