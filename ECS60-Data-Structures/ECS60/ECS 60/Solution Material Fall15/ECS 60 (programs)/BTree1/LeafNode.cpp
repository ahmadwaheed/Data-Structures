#include <iostream>
#include "LeafNode.h"
#include "QueueAr.h"

using namespace std;


LeafNode::LeafNode(int LSize, InternalNode *p, BTreeNode *left, BTreeNode *right) : BTreeNode(LSize, p, left, right)
{
	values = new int[LSize];
}  // LeafNode()
void LeafNode::donateLeft(int value)
{
	//donates one to the left.
	getLeft()->insert(values[0]);
	int i = 0;
	for (; value>values[i + 1] && i< count -1; i++)
	{
		//shifts everyone to the left
		values[i] = values[i + 1];
	}
	values[i] = value;
	if (parent && parent != getLeft()->getParent())
	{
		getLeft()->getParent()->updateKeys();
	}
}
void LeafNode::donateRight(int value)
{
	if (value < values[count - 1]) {
		getRight()->insert(values[count - 1]);
		count--;
		insert(value);
	}
	else
	{
		rightSibling->insert(value);
	}
	if (parent && parent != getRight()->getParent())
	{
		getRight()->getParent()->updateKeys();
	}

}
LeafNode * LeafNode::getRight()
{
	return dynamic_cast<LeafNode*>(getRightSibling());
}
LeafNode * LeafNode::getLeft()
{
	return dynamic_cast<LeafNode*>(getLeftSibling());
}

int LeafNode::getMinimum()const
{
	if (count > 0)  // should always be the case
		return values[0];
	else
		return 0;

} // LeafNode::getMinimum()
  //hasRoom inserts without incrementing count
void LeafNode::hasRoom(int value)
{

	int i = count;

	if (count == 0)
		values[count] = value;
	else {
		while (value < values[i - 1] && i >0)
		{
			values[i] = values[i - 1];
			i--;
		}
		values[i] = value;
	}

}// hasRoom()
LeafNode* LeafNode::insert(int value)
{

	if (!isFull())
	{

		hasRoom(value);
		count++;
		return NULL;
	}
	else if (checkLeft())
	{
		donateLeft(value);
		return NULL;

	}
	else if (checkRight())
	{
		donateRight(value);
		return NULL;
	}
	else
	{
		return newbro(value);
		 
	}
}
bool LeafNode::isFull()
{
	return count == leafSize;
}
LeafNode* LeafNode::newbro(int value)
{
	LeafNode* newleaf = new LeafNode(leafSize, parent, this, rightSibling);
	if (rightSibling)
	{
		getRightSibling()->setLeftSibling(newleaf);
	}
	int minsize = (leafSize +  1) / 2 + (leafSize +1) %2;// L/2 + L%2
	int f = 0;//this flags whether or not new element has been inserted
	int dudeindex = 0;
	int k = 0;
	
	for (int i = 0; i+f < minsize; i++)
	{

		if(f == 0 && value > values[leafSize -1 -i])
		{
			newleaf->values[minsize - 1 - i] = value;
			f++;
		}
		newleaf->values[minsize -1 - (i + f)] = values[leafSize - 1 -i];

	}
	
	if (f == 0)
	{
		hasRoom(value);
	}

	newleaf->count = minsize;
	count = leafSize + 1 - minsize;
	rightSibling = newleaf;
	return newleaf;
}
void LeafNode::print(Queue <BTreeNode*> &queue)
{
	cout << "Leaf: ";
	for (int i = 0; i < count; i++)
		cout << values[i] << ' ';
	cout << endl;

} // LeafNode::print()

bool LeafNode::checkLeft()
{
	return(leftSibling && leftSibling->getCount() < leafSize);
}

bool LeafNode::checkRight() {
	return(rightSibling && rightSibling->getCount() < leafSize);
}
bool LeafNode::hasParent()
{
	return(parent != NULL);
}
InternalNode* LeafNode::getParent()
{
	return parent;
}
void LeafNode::donate(LeafNode * adopter) {}
