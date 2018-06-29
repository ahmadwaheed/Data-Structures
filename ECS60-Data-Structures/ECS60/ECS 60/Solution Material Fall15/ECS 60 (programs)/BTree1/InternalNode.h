#ifndef InternalNodeH
#define InternalNodeH

#include "BTreeNode.h"

class InternalNode :public BTreeNode
{
	int internalSize;
	BTreeNode **children;
	int *keys;
public:
	InternalNode(int ISize, int LSize, InternalNode *p, BTreeNode *left,
		BTreeNode *right, BTreeNode* firstChild, BTreeNode* secondChild);
	InternalNode(int ISize, int LSize, InternalNode *p,
		BTreeNode *left, BTreeNode *right);
	void broInsert(BTreeNode *newNode);
	bool checkLeft();
	bool checkRight();
	void incCount();
	void donateLeft(BTreeNode* value);
	void donateRight(BTreeNode* value);
	InternalNode * newbro(BTreeNode* child);
	InternalNode * getLeft();
	InternalNode * getRight();
	void hasRoom(BTreeNode *newchild);
	bool hasParent();
	int search(int value);
	InternalNode * getParent();
	int getMinimum()const;
	int getMinimum();
	InternalNode* insert(int value); // returns pointer to new InternalNode
	bool isFull();
	// if it splits else NULL

	void insert(BTreeNode *oldRoot, BTreeNode *node2); // if root splits use this
	InternalNode * insert(BTreeNode *newNode); // from a sibling
	void print(Queue <BTreeNode*> &queue);
	void updateKeys();
}; // InternalNode class

#endif
