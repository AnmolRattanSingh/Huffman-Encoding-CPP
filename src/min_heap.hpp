/*
 * Library containing
 */

#include <vector>

/*
 * A struct representing ____
 *
 * @param
 * @param
 * @param
 */
struct Node {
  std::byte symbol;
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

  // Constructor
  MinHeap();

  // Destructor
  ~MinHeap();

  // Swap nodes at specified indices in the heap
  void swap(int index1, int index2);

  // Add a new node to the heap and update size
  void insert(int value);

  // Remove the node at the top of the heap and update size
  Node *pop();

  // Return the node at the top of the heap (also the minimum)
  Node *top();

private:
  std::vector<int> heap;
};
