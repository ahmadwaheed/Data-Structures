// This program completes all the functions of Binary Tree and Binary Search Tree.
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
using namespace std;

class BinaryTree
{
 private:
   class TreeNode
   {
    friend class BinaryTree;  // This class is friend of TreeNode class
    int value;
    TreeNode *right; 
    TreeNode *left;
    TreeNode(int value,TreeNode *right = NULL,TreeNode *left = NULL)
    {
     this->value = value;
     this->right = right;
     this->left = left;
    }
   };
    TreeNode *root;
    
    void insertRecursion(TreeNode *&,int);
    void removeRecursion(TreeNode *&,int);
    void destroySubTree(TreeNode *);
    void makeDeletion(TreeNode *&);
    void InOrder(TreeNode *);
    void PreOrder(TreeNode *);
    void PostOrder(TreeNode *);
    int FindMinRecursive(TreeNode *);
    int FindMaxRecursive(TreeNode *);
    bool IsSubTreeGreater(TreeNode *,int);
    bool IsSubTreeLesser(TreeNode *,int); 
    bool IsBinarySearchTree(TreeNode *,int,int);
   // int FindHeightRecursive(TreeNode *);
    //int max(TreeNode *,TreeNode *);
 public:
   BinaryTree()
    { root = NULL; }
   ~BinaryTree()
    { destroySubTree(root); }
   void insert(int num)
    { insertRecursion(root,num); }
   void remove(int num)
    { removeRecursion(root,num); }
   void showInOrder()
    { InOrder(root); }
   void showPreOrder()
    { PreOrder(root); }
   void showPostOrder()
    { PostOrder(root); } 
   bool search(int);
  // bool IsBinarySearchTree(TreeNode *,int,int);
   int findMin()
    { FindMinRecursive(root); }
   int findMax()
    { FindMaxRecursive(root); }
   bool SearchTree(TreeNode *root)
    { IsBinarySearchTree(root); }
  // int findHeight()
   // { FindHeightRecursive(root); } 
};  
#endif

void BinaryTree::insertRecursion(TreeNode *&tree,int num)
{
 if(!tree)  // If there is no tree.
 {
  tree = new TreeNode(num);
  return;
 }
 if(tree->value == num)  // if the value is equal number already in the tree
 return;
 
 if(num < tree->value)  // If the tree is not empty: insert the node into right or left side
  insertRecursion(tree->left,num);
 else
  insertRecursion(tree->right,num);
}

void BinaryTree::removeRecursion(TreeNode *&tree,int num)
{
 if(tree == NULL)
  return;
 if(num < tree->value)
  removeRecursion(tree->left,num);
 else if (num > tree->value)
  removeRecursion(tree->right,num);
 else
  makeDeletion(tree);
}

/*================================================================
this function takes a reference to a tree whose root is to be 
deleted. If the tree has a single child, the tree is replaced by
the single child after the removal of its root node. if the tree
has two children the left subtree of the deleted node is attached 
at an appropriate point in the right subtree, and then the right
subtree replaces the original tree. 
==================================================================*/
void BinaryTree::makeDeletion(TreeNode *&tree)
{
 TreeNode *nodeToDelete = tree;  // used to hold the node that will be deleted
 TreeNode *attachPoint;  //Used to locate the point where the left subtree is attahed
 
 if(tree->right == NULL)// Replace tree with its left subtree.
  { tree = tree->left; } 
 else if(tree->left == NULL) // Replace tree with its right subtree.
  { tree = tree->right; } 
 else //The node has two child
 {
  attachPoint = tree->right; // Move to the right subtree
  while(attachPoint->left != NULL) //Locate smallest node in the right subtree by moving as far to the left as possible.
   attachPoint = attachPoint->left; 
   attachPoint->left = tree->left;  //Attach the left subtree of the original tree as the left subtree of the smallest node in right subtree
   tree = tree->right;
 }
 delete nodeToDelete;
}

bool BinaryTree::search(int num)
{
 TreeNode *tree = root;
 
 while(tree)
 {
  if(tree->value == num)
   return true;
  else if(num < tree->value)
   tree = tree->left;
  else
   tree = tree->right;
 }
 return false;
}

void BinaryTree::destroySubTree(TreeNode *tree)
{
 if(!tree)
  return;
 destroySubTree(tree->left);
 destroySubTree(tree->right);
 delete tree;
}

void BinaryTree::InOrder(TreeNode *tree)
{
 if(tree)
 {
  InOrder(tree->left);
  cout << tree->value << " ";
  InOrder(tree->right);
 }
}

void BinaryTree::PreOrder(TreeNode *tree)
{
 if(tree)
 {
  cout << tree->value << " ";
  PreOrder(tree->left);
  PreOrder(tree->right);
 }
}

void BinaryTree::PostOrder(TreeNode *tree)
{
 if(tree)
 {
  PreOrder(tree->left);
  PreOrder(tree->right);
  cout << tree->value << " ";
 }
}
int BinaryTree::FindMinRecursive(TreeNode *tree)
{
 if(tree == NULL)
  return -1;
  
 else if(tree->left == NULL)
  { return tree->value; }
  return FindMinRecursive(tree->left);  // Search in left tree
}

int BinaryTree::FindMaxRecursive(TreeNode *tree)
{
 if(tree == NULL)
  return -1;
 else if(tree->right == NULL)
 { return tree->value; }
 return FindMaxRecursive(tree->right);
}

/*int BinaryTree::FindHeightRecursive(TreeNode *tree)
{
 if(tree == NULL)
  return -1;
  return max(FindHeightRecursive(root->left),FindHeightRecursive(root->right))+ 1;
}

int BinaryTree::max(TreeNode *left,TreeNode *right)
{
 if(left > right)
  return TreeNode->left;
 else
  return TreeNode->right;
} */

bool BinaryTree::IsBinarySearchTree(TreeNode *tree,int min,int max)
{
 if(tree == NULL)
  return true;
 if(IsSubTreeLesser(tree->left,tree->value)
 && IsSubTreeGreater(tree->right,tree->value)
 && IsBinarySearchTree(tree->left)
 && IsBinarySearchTree(tree->right))
  return true;
 else
  return false;
}

bool BinaryTree::IsSubTreeLesser(TreeNode *tree,int data)
{
 if(tree == NULL)
  return true;
 if(tree->value <= data && 
 IsSubTreeLesser(tree->left,data) &&
 IsSubTreeLesser(tree->right,data))
  return true;
 else
  return false;
}

bool BinaryTree::IsSubTreeGreater(TreeNode *tree,int data)
{
 if(tree == NULL)
  return true;
 if(tree->value >= data &&
 IsSubTreeGreater(tree->left,data) &&
 IsSubTreeGreater(tree->right,data))
  return true;
 else
  return false;
}
 
