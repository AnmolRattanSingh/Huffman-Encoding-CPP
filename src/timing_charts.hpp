#include "huffman_helper.hpp"
#include <iostream>
#include <string>

double averageTime(MinHeap *(*buildHuffman)(std::map<int, int> map_frequency),
                   int size, int rng);
std::vector<double>
averageTimes(MinHeap *(*buildHuffman)(std::map<int, int> map_frequency),
             std::vector<int> sizes, int rng);
