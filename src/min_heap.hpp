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

  /**
   * Given an index, return a pointer to the node at that index in the min heap
   *
   * @param index: An int representing the index of the node in the min heap
   * that is to be returned
   * @return: A pointer to the node found at the inputted index in the min heap
   */
  Node *get(int index);

  /**
   * Given two indexes, swap the nodes that those indexes in the min heap.
   *
   * This is done in place by switching the locations of the pointers to the two
   * nodes in the min heap
   *
   * @param index1: An int representing the first index of the node to be
   * swapped
   * @param index2: An int representing the second index of the node to be
   * swapped
   */
  void swap(int index1, int index2);

  /**
   * Given a pointer to a node, insert it in the correct position in the min
   * heap
   *
   * This first appends the node to the end of the heap and then compared the
   * frequency of the new node to the parent node (at index (i - 1) / 2). This
   * is because the min heap is stored layer by layer, listing the nodes of the
   * tree from left to right. If the new node is at a lower frequency than the
   * parent, then they are swapped.
   *
   * @param node: A pointer to the node to be inserted into the min heap
   */
  void insert(Node *node);

  /**
   * Remove the first node of the min heap (the node with the lowest frequency)
   * and returns a pointer to the node just removed. Size is decreased by one.
   *
   * @return: A pointer to the node found at the first index of the min heap
   * (that was just removed from it)
   */
  Node *pop();

  /**
   * Return a pointer to the first node of the min heap if it exists, else null.
   *
   * @return: A pointer to the node found at the first index of the min heap
   */
  Node *top();

  /**
   * Print min heap in a list format
   */
  void printSimpleHeap();

  /**
   * Print min heap in a tree format
   */
  void printHeap();

private:
  std::vector<Node *> heap;

  /**
   * Helper to print min heap in a tree format
   *
   * @param i: An int representing the index of the node to be printed
   * @param prefix: A string representing the prefix to be printed before the
   * each node
   */
  void printHeapHelper(int i, std::string prefix);
};
