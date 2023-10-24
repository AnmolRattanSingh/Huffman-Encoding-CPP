/*
 * Library containing
 */
#pragma once
#include <map>
#include <vector>

/*
 * A struct representing a node in the binary tree for Huffman Encoding
 *
 * @param symbol: An int representing the symbol associated with the node
 * @param freq: An int representing the total occurrences of the symbol in the
 * string being encoded
 * @param left: A pointer to a Node that is the left "child" of the current node
 * @param right: A pointer to a Node that is the right "child" of the current
 * node
 */
struct Node {
  int symbol;
  int freq;
  Node *left;
  Node *right;
};

/*
 * Class representing a minimum heap used to map the frequencies of each
 * character in the string being encoded so that each parent node is smaller
 * than or equal to the children nodes
 *
 * Constructed void by initializing size of heap to 0 and initializes an empty
 * vector of nodes (heap)
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

  // Remove the node at the top of the heap and update size and return removed
  Node *pop();

  // Return the node at the top of the heap (also the minimum)
  Node *top();

  // private:
  std::vector<Node *> heap;
  void printHeapHelper(int i, std::string prefix);
  void printHuffmanHelper(Node *root, std::string prefix);
};
