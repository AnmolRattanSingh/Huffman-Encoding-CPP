#include <chrono>
#include <iostream>
#include "timing_charts.hpp"

double averageTime(MinHeap* (*buildHuffman)(std::map<int, int> map_frequency), int size, int rng) {
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

    // start timer
    auto start = std::chrono::high_resolution_clock::now();
    MinHeap* heap = buildHuffman(map);
    // end timer
    auto end = std::chrono::high_resolution_clock::now();

    // calculate duration
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // convert to milliseconds
    auto duration_ms = duration.count() / 1000.0;

    total_time += duration_ms;

    delete heap;
  }
  return total_time / num_trials;
}

std::vector<double> averageTimes(MinHeap* (*buildHuffman)(std::map<int, int> map_frequency), std::vector<int> sizes, int rng) {
  std::vector<double> times;
  for (int i = 0; i < sizes.size(); i++) {
    double t = averageTime(buildHuffman, sizes[i], rng);
    times.push_back(t);
    std::cout << "size: " << sizes[i] << " time: " << t << "ms" << std::endl;
  }
  return times;
}
