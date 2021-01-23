// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// BST class
// Creates a BST to store values
// Uses Node which holds the data
// Uses templates to store any type of data
// binarysearchtreee.cpp file is included at the bottom of the .h file
// binarysearchtreee.cpp is part of the template, cannot be compiled separately

#ifndef BSTMAP_H
#define BSTMAP_H

#include <cstdint>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class BSTMap 
{

  // display BST tree in a human-readable format
  // comment out printSideways or printVertical
  friend ostream &operator<<(ostream &out, const BSTMap &bst);

public:
  using key_type = string;
  using mapped_type = uint64_t;
  using value_type = pair<key_type, mapped_type>;

  // constructor, empty tree
  BSTMap() = default;

  // copy constructor
  BSTMap(const BSTMap &bst);

  // given an array of length n
  // create a tree to have all items in that array
  // with the minimum height (uses same helper as rebalance)
  explicit BSTMap(const vector<value_type> &v);

  // destructor
  virtual ~BSTMap();

  // move not allowed
  BSTMap(BSTMap &&other) = delete;

  // assignment not allowed
  BSTMap &operator=(const BSTMap &other) = delete;

  // move assignment not allowed
  BSTMap &operator=(BSTMap &&other) = delete;

  // true if no nodes in BST
  bool empty() const;

  // Number of nodes in BST
  int size() const;

  // 0 if empty, 1 if only root, otherwise
  // height of root is max height of subtrees + 1
  int height() const;

  // delete all nodes in tree
  void clear();

  // true if item is in BST
  bool contains(const key_type &key) const;

  // same as contains, but returns 1 or 0
  // compatibility with std::map
  size_t count(const key_type &k) const;

  // If k matches the key returns a reference to its value
  // If k does not match any key, inserts a new element
  // with that key and returns a reference to its mapped value.
  mapped_type &operator[](const key_type &k);

  // inorder traversal: left-root-right
  // takes a function that takes a single parameter of type T
  void inorder(void visit(const value_type &item)) const;

  // preorder traversal: root-left-right
  void preorder(void visit(const value_type &item)) const;

  // postorder traversal: left-right-root
  void postorder(void visit(const value_type &item)) const;

  // balance the BST by saving all nodes to a vector inorder
  // and then recreating the BST from the vector
  void rebalance();

  // returns true if item successfully erased - BONUS
  bool erase(const key_type &k);

  vector<value_type> getAll(const key_type &k) const;

  void insert(value_type toAdd);

  // trees are equal if they have the same structure
  // AND the same item values at all the nodes
  bool operator==(const BSTMap &other) const;

  // not == to each other
  bool operator!=(const BSTMap &other) const;

private:
  // Node for BST
  struct Node {
    // key-value pair
    value_type data;
    // children
    struct Node *left;
    struct Node *right;
  };

  // recursive helper method for size.
  int sizeHelper(Node* root) const;

  // refer to data type "struct Node" as Node
  using Node = struct Node;

  // print Node
  friend ostream &operator<<(ostream &out, const Node &n);

  // root of the tree
  Node *root{nullptr};

  // print tree sideways with root on left
  static ostream &printSideways(ostream &out, const Node *curr, int level = 0);

  // helper for printVertical
  static ostream &centeredPrint(ostream &out, int space, const string &str,
                                char fillChar = ' ');

  // print tree with the root at top
  static ostream &printTreeLevel(ostream &out, queue<const Node *> &q,
                                 int width, int depth, int maxDepth);

  // helper function for displaying tree sideways, works recursively
  static ostream &printVertical(ostream &out, Node *curr);

  // height of a Node, nullptr is 0, root is 1, static, no access to 'this'
  // helper function to height(), used by printVertical
  static int getHeight(const Node *n);

  // Insert method to add values
  Node* insertHelper(Node* toAdd, Node* current);

  // Contains recursive traversal helper method
  bool contains(Node* root, const key_type &key) const;

  void clearHelper(Node* current);

  // Copy constructor recursive traversal helper: Traverses both trees
  void copyHelper(Node* currentNewTree, Node* currentOldTree);

  // == helper  
  bool isSameTree(Node* tree1, Node* tree2) const;

  // traversal helpers
  void inorder(Node* current, void visit(const value_type &item)) const;
  void preorder(Node* current, void visit(const value_type &item)) const;
  void postorder(Node* current, void visit(const value_type &item)) const;

  //helpers for rebalance()
  void storeNodes(Node* curr, vector<Node*> &save);
  Node* rebalanceHelper(vector<Node*> &save, int start, int end);

  // getAll traverser
  void getAllHelper(vector<value_type>& vect, Node* curr, const key_type &k) const;

  bool getMapType(mapped_type& retVal, const key_type &k, Node* curr);
};

#endif // BSTMAP_H
