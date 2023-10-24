/*
 * Library containing
 */
#pragma once
#include <vector>
#include <map>

/*
 * A struct representing ____
 *
 * @param
 * @param
 * @param
 */
struct Node {
  int symbol;
  int freq;
  Node *left;
  Node *right;
};

/*
 * Class representing ____
 *
 * Constructed ____
 */
class MinHeap {
public:
  int size;

  // Constructor - Initialize size to 0, add empty node to heap
  MinHeap();

  // Destructor
  ~MinHeap();

  // Print tree
  void printHeap();

  // Print tree
  void printHuffman();

  // Getter
  Node *get(int index);

  // Swap nodes at specified indices in the heap
  void swap(int index1, int index2);

  // Add a new node to the heap and update size
  void insert(Node *node);

  // Remove the node at the top of the heap and update size
  Node *pop();

  // Return the node at the top of the heap (also the minimum)
  Node *top();

// private:
  std::vector<Node *> heap;
  void printHeapHelper(int i, std::string prefix);
  void printHuffmanHelper(Node* root, std::string prefix);
};
