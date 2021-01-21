// Yusuf Pisan pisan@uw.edu
// 17 Jan 2021

// BST class
// Creates a BST to store values
// Uses Node which holds the data

#include "bstmap.h"
#include <cassert>

using namespace std;

// copy constructor
BSTMap::BSTMap(const BSTMap &bst) 
{
  copyHelper(root, bst.root);
}

void BSTMap::copyHelper(Node* currentNewTree, Node* currentOldTree)
{
  if(currentOldTree == nullptr)
  {
    return;
  }
  currentNewTree = new Node();
  currentNewTree->data = currentOldTree->data;
  copyHelper(currentNewTree->right, currentOldTree->right);
  copyHelper(currentNewTree->left, currentOldTree->left);
}

// given an array of length n
// create a tree to have all items in that array
// with the minimum height (uses same helper as rebalance)
BSTMap::BSTMap(const vector<value_type> &v) 
{
  for(int i = 0; i < v.size(); i++)
  {
    Node* theNode = new Node();
    theNode->data = v[i];
    insert(theNode, root);
  }
}

// destructor
BSTMap::~BSTMap() 
{
  clear();
}



void BSTMap::insert(Node* toAdd, Node* current)
{
  if(current == nullptr)
  {
    current = toAdd;
  }
  else if(current->data.first < toAdd->data.first)
  {
    return insert(toAdd, current->right);
  }
  else if(current->data.first > toAdd->data.first)
  {
    return insert(toAdd, current->left);
  }
}


// delete all nodes in tree
void BSTMap::clear() 
{
  if(root == nullptr)
  {
    return;
  }
  clearHelper(root);
}

void BSTMap::clearHelper(Node* current)
{
  if(current == nullptr)
  {
    return;
  }
  clearHelper(root->left);
  clearHelper(root->right);
  delete current;
}


// true if no nodes in BST
bool BSTMap::empty() const 
{ 
  if(root == nullptr)
  {
    return true;
  }
  return false;
}

int BSTMap::size() const {
  int return_val = sizeHelper(root);
  return return_val;
}

int BSTMap::sizeHelper(Node* root) const
{
  if(root == nullptr)
  {
    return 0;
  } else
    return sizeHelper(root->left) + 1 + sizeHelper(root->right);
}

// true if item is in BST
bool BSTMap::contains(const key_type &key) const 
{ 
  return contains(root, key); 
}

bool BSTMap::contains(Node* root, const key_type &key) const 
{
  if(root->data.first == key)
  {
    return true;
  }
  if(root == nullptr)
  {
    return false;
  }
  return(contains(root->left, key) || contains(root->right, key));
}

// If k matches the key returns a reference to its value
// If k does not match any key, inserts a new element
// with that key and returns a reference to its mapped value.
BSTMap::mapped_type &BSTMap::operator[](const key_type &k) 
{
  assert(false && "operator[] has not been implemented");
  return root->data.second;
}

vector<BSTMap::value_type> BSTMap::getAll(const key_type &k) const 
{
  vector<value_type> v;
  return v;
}

// 0 if empty, 1 if only root, otherwise
// height of root is max height of subtrees + 1
int BSTMap::height() const 
{ 
  return getHeight(root); 
}

// height of a Node, nullptr is 0, root is 1, static, no access to 'this'
// helper function to height(), used by printVertical
int BSTMap::getHeight(const Node* n)
{ 
  if(n == nullptr)
  {
    return 0;
  }
  if(n->left == nullptr && n->right == nullptr)
  {
    return 1;
  }
  int left = getHeight(n->left);
  int right = getHeight(n->right);
  return max(left,right)+1; 
}

// same as contains, but returns 1 or 0
// compatibility with std::map
size_t BSTMap::count(const string &k) const 
{ 
  if(!contains(k))
  {
    return 0;
  }
  return 1;
}

// inorder traversal: left-root-right
// takes a function that takes a single parameter of type T
void BSTMap::inorder(void visit(const value_type &item)) const 
{
  inorder(root, visit);
}

void BSTMap::inorder(Node* current, void visit(const value_type &item)) const{
    if(current == nullptr)
    {
        return;
    }
    inorder(current->left, visit);
    value_type v = current->data;
    visit(v);
    inorder(current->right, visit);
}

// preorder traversal: root-left-right
void BSTMap::preorder(void visit(const value_type &item)) const 
{
  preorder(root, visit);
}

void BSTMap::preorder(Node* current, void visit(const value_type &item)) const{
    if(current == nullptr)
    {
        return;
    }
    value_type v = current->data;
    visit(v);
    preorder(current->left, visit);
    preorder(current->right, visit);
}

// postorder traversal: left-right-root
void BSTMap::postorder(void visit(const value_type &item)) const 
{
  postorder(root, visit);
}

void BSTMap::postorder(Node* current, void visit(const value_type &item)) const{
    if(current == nullptr)
    {
        return;
    }
    preorder(current->left, visit);
    preorder(current->right, visit);
    value_type v = current->data;
    visit(v);
}

// balance the BST by saving all nodes to a vector inorder
// and then recreating the BST from the vector
void BSTMap::rebalance() 
{
  vector<Node*> save;
  storeNodes(root, save);
}
void BSTMap::storeNodes(Node* curr, vector<Node*> &save)
{
  if(curr == nullptr)
  {
    return;
  }
  storeNodes(curr->left, save);
  save.push_back(curr);
  storeNodes(curr->right, save);
}

void BSTMap::rebalanceHelper(vector<Node*> &save, int start, int end)
{
  
}
// trees are equal if they have the same structure
// AND the same item values at all the nodes
bool BSTMap::operator==(const BSTMap &other) const 
{ 
  return isSameTree(root, other.root);
}

bool BSTMap::isSameTree(Node* tree1, Node* tree2) const
{
  if(tree1 == nullptr && tree2 == nullptr)
  {
    return true;
  }
  else if((tree1 == nullptr && tree2 != nullptr) || (tree1 != nullptr && tree2 == nullptr))
  {
    return false;
  }
  else if(tree1->data != tree2->data)
  {
    return false;
  }
  return (isSameTree(tree1->left, tree2->left) && isSameTree(tree1->right, tree2->right));
}

// not == to each other
bool BSTMap::operator!=(const BSTMap &other) const 
{ 
  bool return_value = isSameTree(root, other.root);
  return !(return_value);
}
