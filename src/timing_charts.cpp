#include "timing_charts.hpp"
#include <chrono>
#include <iostream>

double averageTime(void (*convert_to_tree)(MinHeap *heap), int size) {
  const double num_trials = 10.0;
  double total_time = 0;

  for (int i = 0; i < num_trials; i++) {
    std::map<int, int> map;
    int start_freq = size;
    for (int j = 0; j < size; j++) {
      map[j] = start_freq;
      start_freq--;
    }

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
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    total_time += duration.count();
  }
  return total_time / num_trials;
}

std::vector<double> averageTimes(void (*convert_to_tree)(MinHeap *heap),
                                 std::vector<int> sizes) {
  std::vector<double> times;
  for (int i = 0; i < sizes.size(); i++) {
    double t = averageTime(convert_to_tree, sizes[i]);
    times.push_back(t);
    std::cout << sizes[i] << "," << t << std::endl;
  }
  return times;
}
