#include <vector>

struct Node
{
    std::byte symbol;
    int freq;
    Node* left;
    Node* right;
};


class MinHeap {
public:
    int size;

    // Constructor
    MinHeap();

    // Destructor
    ~MinHeap();

    // Swap nodes at specified indices in the heap
    void Swap(int index1, int index2);
    
    // Add a new node to the heap and update size
    void Insert(int value);

    // Remove the node at the top of the heap and update size
    Node* Pop();

    // Return the node at the top of the heap (also the minimum)
    Node* Top();

private:
    std::vector<int> heap;
};
