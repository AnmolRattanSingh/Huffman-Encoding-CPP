#include "timing_charts.hpp"
#include <chrono>
#include <iostream>

double averageTime(void (*convert_to_tree)(MinHeap *heap), int size, int rng) {
  double num_trials = 10.0;
  double total_time = 0;
  for (int i = 0; i < num_trials; i++) {
    // generate random string
    std::string str = "";
    for (int j = 0; j < size; j++) {
      int r = rand() % rng;
      str += (char)(r + 97);
    }
    // build huffman tree from random string
    std::map<int, int> map = map_frequency(str);

    MinHeap heap;
    // start timer
    auto start = std::chrono::high_resolution_clock::now();
    for (auto const &pair : map) {
      Node *node = new Node{
          .symbol = pair.first,
          .freq = pair.second,
          .left = nullptr,
          .right = nullptr,
      };
      heap.insert(node);
    }
    convert_to_tree(&heap);
    // end timer
    auto end = std::chrono::high_resolution_clock::now();

    // calculate duration
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // convert to milliseconds
    auto duration_ms = duration.count();

    total_time += duration_ms;
  }
  return total_time / num_trials;
}

std::vector<double> averageTimes(void (*convert_to_tree)(MinHeap *heap),
                                 std::vector<int> sizes, int rng) {
  std::vector<double> times;
  for (int i = 0; i < sizes.size(); i++) {
    double t = averageTime(convert_to_tree, sizes[i], rng);
    times.push_back(t);
    std::cout << "size: " << sizes[i] << " time: " << t << "µs" << std::endl;
  }
  return times;
}
