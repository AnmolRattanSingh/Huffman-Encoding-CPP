#include "min_heap.hpp"

// Constructor
MinHeap::MinHeap() {
  size = 0;
  Node empty = Node();
  heap.push_back(&empty);
}

// Destructor
MinHeap::~MinHeap() { heap.clear(); }

// Getter
Node *MinHeap::get(int index) { return heap.at(index); }

// Swap nodes at specified indices in the heap
void MinHeap::swap(int index1, int index2) {
  int temp1 = index1;
  heap[index1] = heap[index2];
  heap[index2] = heap[temp1];
}

// Add a new node to the heap and update size
void MinHeap::insert(Node *node) {
  heap.push_back(node);
  size += 1;

  int i = size - 1;
  while (i > 1) {
    int parent = (i - 1) / 2;

    if ((*heap.at(parent)).freq > (*heap.at(i)).freq) {
      swap(parent, i);
    }
    i = parent;
  }
}

// Remove the node at the top of the heap and update size
Node *MinHeap::pop() { return nullptr; }

// Return the node at the top of the heap (also the minimum)
Node *MinHeap::top() { return nullptr; }
