#ifndef BTREE_H
#define BTREE_H

#include "BTreeNode.h"
#include "LeafNode.h"

class BTree
{
	BTreeNode *root;
	//LeafNode *leaf;
	int internalSize;
	int leafSize;
public:
	BTree(int ISize, int LSize);
	void insert(int value);
	void print();
}; // BTree class
#endif

#pragma once
