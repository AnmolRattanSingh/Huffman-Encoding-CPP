#include "min_heap.hpp"
#include <iostream>

Node *MinHeap::get(int index) { return heap.at(index); }

void MinHeap::swap(int index1, int index2) {
  Node *temp = heap.at(index1);
  heap.at(index1) = heap.at(index2);
  heap.at(index2) = temp;
}

void MinHeap::insert(Node *node) {
  heap.push_back(node);
  size += 1;

  int i = size - 1;
  while (i >= 1) {
    int parent = (i - 1) / 2;
    if ((heap.at(parent))->freq > (heap.at(i))->freq) {
      swap(parent, i);
    }
    i = parent;
  }
}

Node *MinHeap::pop() {
  Node *first = top();
  heap.erase(heap.begin());
  size -= 1;
  return first;
}

Node *MinHeap::top() {
  if (size > 0) {
    return heap.at(0);
  } else {
    return nullptr;
  }
}

void MinHeap::printSimpleHeap() {
  for (int i = 0; i < size; i++) {
    std::cout << (char)heap.at(i)->symbol << " freq: " << heap.at(i)->freq
              << std::endl;
  }
}

void MinHeap::printHeap() {
  std::cout << " /" << std::endl;
  printHeapHelper(0, " |  ");
  std::cout << " //" << std::endl;
}

void MinHeap::printHeapHelper(int i, std::string prefix) {
  if (i < heap.size()) {
    // right child = 2i + 2
    printHeapHelper(2 * i + 2, prefix + "│   ");
    std::cout << prefix << (char)heap.at(i)->symbol << ":" << heap.at(i)->freq
              << std::endl;
    // left child = 2i + 1
    printHeapHelper(2 * i + 1, prefix + "│   ");
  } else {
    std::cout << prefix << "─" << std::endl;
  }
}
