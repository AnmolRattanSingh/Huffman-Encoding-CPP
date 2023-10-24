#include "min_heap.hpp"
#include <iostream>

/**
 * Given an index, return a pointer to the node at that index in the min heap
 *
 * @param index: An int representing the index of the node in the min heap that
 * is to be returned
 * @return: A pointer to the node found at the inputted index in the min heap
 */
Node *MinHeap::get(int index) { return heap.at(index); }

/**
 * Given two indexes, swap the nodes that those indexes in the min heap.
 *
 * This is done in place by switching the locations of the pointers to the two
 * nodes in the min heap
 *
 * @param index1: An int representing the first index of the node to be swapped
 * @param index2: An int representing the second index of the node to be swapped
 */
void MinHeap::swap(int index1, int index2) {
  Node *temp = heap.at(index1);
  heap.at(index1) = heap.at(index2);
  heap.at(index2) = temp;
}

/**
 * Given a pointer to a node, insert it in the correct position in the min heap
 *
 * This first appends the node to the end of the heap and then compared the
 * frequency of the new node to the parent node (at index (i - 1) / 2). This is
 * because the min heap is stored layer by layer, listing the nodes of the tree
 * from left to right. If the new node is at a lower frequency than the parent,
 * then they are swapped.
 *
 * @param node: A pointer to the node to be inserted into the min heap
 */
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

/**
 * Remove the first node of the min heap (the node with the lowest frequency)
 * and returns a pointer to the node just removed. Size is decreased by one.
 *
 * @return: A pointer to the node found at the first index of the min heap (that
 * was just removed from it)
 */
Node *MinHeap::pop() {
  Node *first = top();
  heap.erase(heap.begin());
  size -= 1;
  return first;
}

/*
 * Return a pointer to the first node of the min heap if it exists, else null.
 */
Node *MinHeap::top() {
  if (size > 0) {
    return heap.at(0);
  } else {
    return nullptr;
  }
}

/*
 * Print min heap in a list format
 */
void MinHeap::printSimpleHeap() {
  for (int i = 0; i < size; i++) {
    std::cout << (char)heap.at(i)->symbol << " freq: " << heap.at(i)->freq
              << std::endl;
  }
}

/*
 * Print min heap in a tree format
 */
void MinHeap::printHeap() {
  std::cout << " /" << std::endl;
  printHeapHelper(0, " |  ");
  std::cout << " //" << std::endl;
}

/*
 * Helper to print min heap in a tree format
 */
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
