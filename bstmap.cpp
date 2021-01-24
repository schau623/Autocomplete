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
  root = copyHelper(bst.root);
}

//copies tree recursively
BSTMap::Node* BSTMap::copyHelper(Node* copy)
{
  if(copy == nullptr)
  {
    return nullptr;
  }
    Node* copyNode = new Node();
    copyNode->data = copy->data;
    copyNode->right = copyHelper(copy->right);
    copyNode->left = copyHelper(copy->left);
    return copyNode;
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
    insertHelper(theNode, root);
  }
}

// destructor
BSTMap::~BSTMap() 
{
  clear();
}

bool BSTMap::erase(const key_type &k){
    if(contains(k) == false)
    {
      return false;
    }
    else
    {
      eraseHelper(root, k);
      return true;
    }
   
}

BSTMap::Node* BSTMap::eraseHelper(Node* current, const key_type &k){
    if(current == nullptr)
    {
      return nullptr;
    }
    if(k < current->data.first)
    {
      current->left = eraseHelper(current->left, k);
    }
    else if(k > current->data.first)
    {
      current->right = eraseHelper(current->right, k);
    }
      else{
          if(current->left == nullptr && current->right == nullptr)
          {
            return nullptr;
          }
          else if((current->left != nullptr) && (current->right == nullptr))
          {
            return current->left;
          }
          else if(current->right != nullptr && current->left == nullptr)
          {
            return current->right;
          }
          auto successor = current->right;
          while(successor->left != nullptr)
          {
            successor = successor->left;
          }
        current->data.first = successor->data.first;
        current->right = eraseHelper(current->right, successor->data.first);
      }
      return current;
}

//inserts new nodes into tree
void BSTMap::insert(value_type toAdd)
{
  Node* newNode = new Node();
  newNode->data = toAdd;
  root = insertHelper(newNode, root);
}

//recursively traverses tree and addes new nodes
BSTMap::Node* BSTMap::insertHelper(Node* toAdd, Node* current)
{
  if(current == nullptr)
  {
    return toAdd;
  }
  else if(current->data.first > toAdd->data.first)
  {
    current->left = insertHelper(toAdd, current->left);
  }
  else if(current->data.first <= toAdd->data.first)
  {
    current->right = insertHelper(toAdd, current->right);
    
  }
  return current;
}


// delete all nodes in tree
void BSTMap::clear() 
{
  if(root == nullptr)
  {
    return;
  }
  clearHelper(root);
  root = nullptr;
}

//recursively traverses tree and deletes nodes
void BSTMap::clearHelper(Node* current)
{
  if(current == nullptr)
  {
    return;
  }
  clearHelper(current->left);
  clearHelper(current->right);
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

//returns size of tree based on number of nodes
int BSTMap::size() const 
{
  int return_val = sizeHelper(root);
  return return_val;
}

//returns size of tree based on number of nodes
int BSTMap::sizeHelper(Node* root) const
{
  if(root == nullptr)
  {
    return 0;
  } 
  else
  {
    return sizeHelper(root->left) + 1 + sizeHelper(root->right);
  }
}

// true if item is in BST
bool BSTMap::contains(const key_type &key) const 
{ 
  return contains(root, key); 
}

//contains overload, recursively traverses tree searching for key_type &key
bool BSTMap::contains(Node* curr, const key_type &key) const 
{
  //cout << key << endl;
  if(curr == nullptr)
  {
    return false;
  }
  if(curr->data.first == key)
  {
    return true;
  }
  
  return(contains(curr->left, key) || contains(curr->right, key));
}

// If k matches the key returns a reference to its value
// If k does not match any key, inserts a new element
// with that key and returns a reference to its mapped value.
BSTMap::mapped_type &BSTMap::operator[](const key_type &k) 
{
  if(contains(k))
  {
    Node* theNode = bracketHelper(k, root);
    return theNode->data.second;
  }
  pair<string,uint64_t> newNode;
  newNode.first = k;
  newNode.second = 0;
  insert(newNode);
  Node* theNode = bracketHelper(k, root);
  return theNode->data.second;
}

//recursively adds new node to tree
BSTMap::Node* BSTMap::bracketHelper(const key_type &k, Node* curr)
{
  if(curr == nullptr)
  {
    return nullptr;
  }
  else if(k == curr->data.first)
  {
    return curr;
  }
  else if(k > curr->data.first)
  {
    return bracketHelper(k, curr->right);
  }
  else
  {
    return bracketHelper(k, curr->left);
  }
}

//retireves all words starting with key_type &k
vector<BSTMap::value_type> BSTMap::getAll(const key_type &k) const 
{
  vector<value_type> v;
  getAllHelper(v, root, k);
  return v;
}

//recursively traverses tree and adds to vector each word starting with key_type &k
void BSTMap::getAllHelper(vector<value_type>& vect, Node* curr, const key_type &k) const
{
  if(curr == nullptr)
  {
    return;
  }
  if(curr->data.first.rfind(k, 0) == 0)
  {
    vect.push_back(curr->data);
  }
  getAllHelper(vect, curr->left, k);
  getAllHelper(vect, curr->right, k);
  return;
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
//inorder overload
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
//preorder overload
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

//postorder overload
void BSTMap::postorder(Node* current, void visit(const value_type &item)) const{
    if(current == nullptr)
    {
        return;
    }
    postorder(current->left, visit);
    postorder(current->right, visit);
    value_type v = current->data;
    visit(v);
}

// balance the BST by saving all nodes to a vector inorder
// and then recreating the BST from the vector
void BSTMap::rebalance() 
{
  vector<Node*> save;
  storeNodes(root, save);
  int n = save.size();
  root = rebalanceHelper(save, 0, n-1);
}
//stores nodes in a vector
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
//rebalances tree
BSTMap::Node* BSTMap:: rebalanceHelper(vector<Node*> &save, int start, int end)
{
  if(start > end)
  {
    return nullptr;
  }
  int mid = (start + end)/2;
  Node* root = save[mid];
  root->left = rebalanceHelper(save, start, mid-1);
  root->right = rebalanceHelper(save, mid+1, end);
  return root;
}

// trees are equal if they have the same structure
// AND the same item values at all the nodes
bool BSTMap::operator==(const BSTMap &other) const 
{ 
  return isSameTree(root, other.root);
}

//recursively traverses both trees and compares them
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
