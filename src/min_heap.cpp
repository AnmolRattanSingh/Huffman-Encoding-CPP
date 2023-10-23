#include "min_heap.hpp"
#include <iostream>
#include <string>

#include <iostream>

// Constructor
MinHeap::MinHeap() {
  size = 0;
  Node empty = Node();
  heap = std::vector<Node *>();
}

// Destructor
MinHeap::~MinHeap() { heap.clear(); }

// Print tree
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

// Print tree
void MinHeap::printHuffman() {
  std::cout << " /" << std::endl;
  printHuffmanHelper(heap.at(0), " |  ");
  std::cout << " //" << std::endl;
}

void MinHeap::printHuffmanHelper(Node *node, std::string prefix) {
  if (node != nullptr) {
    printHuffmanHelper(node->left, prefix + "│   ");
    std::cout << prefix << (char)node->symbol << ":" << node->freq << std::endl;
    printHuffmanHelper(node->right, prefix + "│   ");
  } else {
    std::cout << prefix << "─" << std::endl;
  }
}

// Getter
Node *MinHeap::get(int index) { return heap.at(index); }

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
Node *MinHeap::top() {
  if (size > 0) {
    return heap.at(0);
  } else {
    return nullptr;
  }
}
