#include "min_heap.hpp"

// Constructor
MinHeap::MinHeap() {
  size = 0;
  heap.push_back(0);
}

// Destructor
MinHeap::~MinHeap() { heap.clear(); }

// Swap nodes at specified indices in the heap
void MinHeap::swap(int index1, int index2) {}

// Add a new node to the heap and update size
void MinHeap::insert(int value) {}

// Remove the node at the top of the heap and update size
Node *MinHeap::pop() { return nullptr; }

// Return the node at the top of the heap (also the minimum)
Node *MinHeap::top() { return nullptr; }
