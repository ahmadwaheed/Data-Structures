#include <iostream>
#include "BTree.h"
#include "BTreeNode.h"
#include "LeafNode.h"
#include "InternalNode.h"
using namespace std;

BTree::BTree(int ISize, int LSize) :internalSize(ISize), leafSize(LSize)
{
	root = new LeafNode(LSize, NULL, NULL, NULL);
	//leaf = root;	
} // BTree::BTree()

void BTree::insert(const int value)
{
	InternalNode * newRoot;
	BTreeNode * newchild = NULL;
	newchild = root->insert(value);

	if (newchild !=NULL)
	{	
		newRoot = new InternalNode(internalSize, leafSize, NULL, NULL, NULL,newchild->getLeftSibling(),newchild);
		newchild->setParent(newRoot);
		newchild->getLeftSibling()->setRightSibling(newchild);
		newchild->getLeftSibling()->setParent(newRoot);
		root = newRoot;
	}	
	// students must write this
} // BTree::insert()

void BTree::print()
{
	BTreeNode *BTreeNodePtr;
	Queue<BTreeNode*> queue(1000);

	queue.enqueue(root);
	while (!queue.isEmpty())
	{
	 BTreeNodePtr = queue.dequeue();
	 BTreeNodePtr->print(queue);
	} // while
} // BTree::print()
