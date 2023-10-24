#include "timing_charts.hpp"

int averageTime(int size, int rng) {
  int num_trials = 10;
  int total_time = 0;
  for (int i = 0; i < num_trials; i++) {
    std::vector<int> xs(size);
    for (int i = 0; i < xs.size(); i++) {
      xs[i] = rand() % rng;
    }
  }
  return 0;
}

std::vector<int> averageTimes(std::vector<int> sizes, int rng) {
  std::vector<int> times;
  for (int i = 0; i < sizes.size(); i++) {
    int t = averageTime(sizes[i], rng);
    times.push_back(t);
  }
  return times;
}
