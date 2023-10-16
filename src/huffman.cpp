#include <iostream>
#include "minHeap.hpp"

int main(void) {
    MinHeap heap;
    heap.Pop();
    std::cout << "Hello, world!" << std::endl;
    std::cout << "Heap size: " << heap.size << std::endl;
    return 0;
}
