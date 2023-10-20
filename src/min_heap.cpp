#include "min_heap.hpp"

#include <iostream>

// Constructor
MinHeap::MinHeap() {
  size = 0;
  Node empty = Node();
  heap = std::vector<Node *>();
}

// Destructor
MinHeap::~MinHeap() { heap.clear(); }

// Getter
Node *MinHeap::get(int index) { return heap.at(index); }

// Repr
void MinHeap::print() {
  for (int i = 0; i < size; i++) {
    std::cout << "Symbol: " << heap.at(i)->symbol
              << " Freq: " << heap.at(i)->freq << std::endl;
  };
}

// Swap nodes at specified indices in the heap
void MinHeap::swap(int index1, int index2) {
  Node *temp = heap.at(index1);
  heap.at(index1) = heap.at(index2);
  heap.at(index2) = temp;
}

// Add a new node to the heap and update size
void MinHeap::insert(Node *node) {
  heap.push_back(node);
  size += 1;

  int i = size - 1;
  while (i > 1) {
    int parent = (i - 1) / 2;
    if ((heap.at(parent))->freq > (heap.at(i))->freq) {
      swap(parent, i);
    }
    i = parent;
  }
}

// Remove the node at the top of the heap and update size
Node *MinHeap::pop() { return nullptr; }

// Return the node at the top of the heap (also the minimum)
Node *MinHeap::top() { return nullptr; }
