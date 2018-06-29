#ifndef LeafNodeH
#define LeafNodeH

#include "BTreeNode.h"
#include "InternalNode.h"
#include <iostream>
class LeafNode :public BTreeNode
{
	int *values;
public:
	LeafNode(int LSize, InternalNode *p, BTreeNode *left,
		BTreeNode *right);
	
	int getMinimum() const;
	void donateLeft(int value);
	void donateRight(int value);
	LeafNode * getRight();
	LeafNode * getLeft();
	LeafNode* insert(int value); // returns pointer to new Leaf if splits
								  // else NULL
	void print(Queue <BTreeNode*> &queue);
	LeafNode* split();
	bool checkLeft();
	bool checkRight();
	LeafNode* full(int value);
	LeafNode * newbro(int value);
	InternalNode * getParent();
	bool hasParent();
	bool isFull();
	void hasRoom(int value);
	void donate(LeafNode *);
	LeafNode* newBro(int value);
}; //LeafNode class

#endif
