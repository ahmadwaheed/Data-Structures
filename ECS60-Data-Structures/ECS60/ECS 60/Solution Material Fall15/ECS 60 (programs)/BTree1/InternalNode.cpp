#include <iostream>
#include "InternalNode.h"
#include "LeafNode.h"

using namespace std;

InternalNode::InternalNode(int ISize, int LSize,
	InternalNode *p, BTreeNode *left, BTreeNode *right) :
	BTreeNode(LSize, p, left, right), internalSize(ISize)
{
	keys = new int[internalSize]; // keys[i] is the minimum of children[i]
	children = new BTreeNode*[ISize];
} // InternalNode::InternalNode()
InternalNode::InternalNode(int ISize, int LSize,
	InternalNode *p, BTreeNode *left, BTreeNode *right,BTreeNode *firstChild,BTreeNode *secondChild) :
	BTreeNode(LSize, p, left, right), internalSize(ISize)
{
	keys = new int[internalSize]; // keys[i] is the minimum of children[i]
	children = new BTreeNode*[ISize];
	count = 2;
	children[0] = firstChild;
	children[1] = secondChild;
	updateKeys();

} // InternalNode::InternalNode()

void InternalNode::donateLeft(BTreeNode* value)
{

	//donates one to the left.
	BTreeNode* iter = children[0];
	int k = getLeft()->count;
	getLeft()->children[getLeft()->count] = iter;
	getLeft()->incCount();
	
	iter->setParent(getLeft());
	getLeft()->updateKeys();

	iter = iter->getRightSibling();
	for (int i = 0; i < count; i++)
	{
	children[i] = iter;
	iter->setParent(this);
	iter = iter->getRightSibling();
	}
	updateKeys();
	//this makes the leftmost things last child things first child.
	/*getLeft()->insert(children[0]);
	int i = 0;
	for (; value < children[i + 1] && i< count -1; i++)
	{
		//shifts everyone to the left
		children[i] = children[i + 1];
	}
	children[i] = value;
	if (parent && parent != getLeft()->getParent())
	{
		getLeft()->getParent()->updateKeys();
	}*/
}
void InternalNode::donateRight(BTreeNode* value)
{
	
	//donates one to the right.
	if (value->getMinimum() < children[count - 1]->getMinimum()) {
		getRight()->hasRoom(children[count - 1]);
		count--;
		hasRoom(value);
	}
	else
	{
		getRight()->hasRoom(value);
	}
	if (parent && parent != getRight()->getParent())
	{
		getRight()->getParent()->updateKeys();
	}
}
bool InternalNode::checkLeft()
{
	return (getLeftSibling() && leftSibling->getCount()<internalSize);
}
bool InternalNode::checkRight()
{
	return (getRightSibling() && rightSibling->getCount()<internalSize);
}
void InternalNode::incCount()
{
	LeafNode * paul = new LeafNode(NULL,NULL,NULL,NULL);
	count++;
}
int InternalNode::getMinimum()const
{
	if (count > 0)   // should always be the case
		return children[0]->getMinimum();
	else
		return 0;
} // InternalNode::getMinimum()

InternalNode* InternalNode::getParent()
{
	return parent;
}
bool InternalNode::hasParent()
{
	return(parent != NULL);
}
InternalNode* InternalNode::getLeft()
{
	return dynamic_cast < InternalNode*> (getLeftSibling());
}
InternalNode* InternalNode::getRight()
{
	return dynamic_cast < InternalNode*> (getRightSibling());
}
void InternalNode::hasRoom(BTreeNode* newchild)
{
	BTreeNode * iter;
	if (newchild->getMinimum() < children[0]->getMinimum())
	{
		iter = newchild;
	}
	else
	{
		iter = children[0];
	}
	count++;
	for (int i = 0; i < count; i++)
	{
		children[i] = iter;
		if (iter->getRightSibling())
			iter = iter->getRightSibling();
	}
	newchild->setParent(this);
	updateKeys();
	
}
InternalNode* InternalNode::insert(int value)
{

	int index = search(value);
	BTreeNode* paul = children[index]->insert(value);
	//paul is a internalNode or Paul is a internal Node
	//if paul exists, a new node has been created
	if (paul)
	{
		if (!isFull())
		{

			hasRoom(paul);
			updateKeys();
			return NULL;
		}
		else if (checkLeft())
		{

			donateLeft(paul);
			return NULL;
		}
		else if (checkRight())
		{
			donateRight(paul);
			return NULL;
		}
		else
		{
			return newbro(paul);

		}
	}
	updateKeys();
	return NULL;

}

// students must write this // to avoid warnings for now.
// InternalNode::insert()
int InternalNode::search(int value)
{
	if (value < children[0]->getMinimum())
		return 0;
	for (int i = 0; i<count - 1; i++)
	{
		
		if (value > children[i]->getMinimum() && value <children[i + 1]->getMinimum())
		{
			return i;
		}


	}
	return count - 1;


}//search())
void InternalNode::insert(BTreeNode *oldRoot, BTreeNode *node2)
{

	// Node must be the root, and node1
	// students must write this
} // InternalNode::insert()
bool InternalNode::isFull()
{
	return count == internalSize;
}
int InternalNode::getMinimum()
{
	if (children[0])
		return children[0]->getMinimum();
	else
		return -1;
}
void InternalNode::updateKeys()
{
	for (int i = 0; i <count; i++)
	{
		keys[i] = children[i]->getMinimum();
	}
}
InternalNode* InternalNode::newbro(BTreeNode * child)
{
	InternalNode* newinternal = new InternalNode(internalSize,internalSize, parent, this, rightSibling);
	if (newinternal->rightSibling)
	{
		newinternal->rightSibling->setLeftSibling(newinternal);
	}
	int minsize = (internalSize + 1) / 2 + (internalSize + 1) % 2;// L/2 + L%2
	BTreeNode * iter = children[0];
	int dudeindex = 0;
	for (; dudeindex < internalSize + 1 - minsize; dudeindex++ )
	{
		children[dudeindex] = iter;
		iter->setParent(this);
		iter = iter->getRightSibling();
	}
	for (int i = 0; i < minsize; i++)
	{
		newinternal->children[i] = iter;
		iter->setParent(newinternal);
		if(iter->getRightSibling())
			iter = iter->getRightSibling();
	}



	newinternal->count = minsize;
	count = internalSize + 1 - minsize;
	updateKeys();
	newinternal->updateKeys();
	setRightSibling(newinternal);
	return newinternal;
}

void InternalNode::print(Queue <BTreeNode*> &queue)
{
	int i;

	cout << "Internal: ";
	for (i = 0; i < count; i++)
		cout << keys[i] << ' ';
	cout << endl;

	for (i = 0; i < count; i++)
		queue.enqueue(children[i]);

} // InternalNode::print()


