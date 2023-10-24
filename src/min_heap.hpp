/*
 * Library containing
 */
#pragma once

#include <map>
#include <string>
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
 *
 * This includes functions to insert a node into the min heap, remove or return
 * the first (minimum) value, and swap two nodes.
 */
class MinHeap {
public:
  int size;

  MinHeap() {
    size = 0;
    Node empty = Node();
    heap = std::vector<Node *>();
  };

  ~MinHeap() { heap.clear(); };

  Node *get(int index);

  void swap(int index1, int index2);

  void insert(Node *node);

  Node *pop();

  Node *top();

  void printSimpleHeap();
  void printHeap();

private:
  std::vector<Node *> heap;
  void printHeapHelper(int i, std::string prefix);
};
