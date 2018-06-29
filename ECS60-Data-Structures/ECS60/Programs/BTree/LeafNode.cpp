#include <iostream>
#include <climits>
#include "InternalNode.h"

using namespace std;

InternalNode::InternalNode(int ISize, int LSize,
  InternalNode *p, BTreeNode *left, BTreeNode *right) :
  BTreeNode(LSize, p, left, right), internalSize(ISize)
{
  keys = new int[internalSize]; // keys[i] is the minimum of children[i]
  children = new BTreeNode* [ISize];
} // InternalNode::InternalNode()


BTreeNode* InternalNode::addPtr(BTreeNode *ptr, int pos)
{ // called when original was full, pos is where the node belongs.
  if(pos == internalSize)
    return ptr;

  BTreeNode *last = children[count - 1];

  for(int i = count - 2; i >= pos; i--)
  {
    children[i + 1] = children[i];
    keys[i + 1] = keys[i];
  } // shift things to right to make room for ptr, i can be -1!

  children[pos] = ptr;  // i will end up being the position that it is inserted
  keys[pos] = ptr->getMinimum();
  ptr->setParent(this);
  return last;
} // InternalNode:: addPtr()


void InternalNode::addToLeft(BTreeNode *last)
{
  ((InternalNode*)leftSibling)->insert(children[0]);

  for(int i = 0; i < count - 1; i++)
  {
    children[i] = children[i + 1];
    keys[i] = keys[i + 1];
  }

  children[count - 1] = last;
  keys[count - 1] = last->getMinimum();
  last->setParent(this);
  if(parent)
    parent->resetMinimum(this);
} // InternalNode::ToLeft()


void InternalNode::addToRight(BTreeNode *ptr, BTreeNode *last)
{
  ((InternalNode*) rightSibling)->insert(last);
  if(ptr == children[0] && parent)
    parent->resetMinimum(this);
} // InternalNode::addToRight()



void InternalNode::addToThis(BTreeNode *ptr, int pos)
{  // pos is where the ptr should go, guaranteed count < internalSize at start
  int i;

  for(i = count - 1; i >= pos; i--)
  {
      children[i + 1] = children[i];
      keys[i + 1] = keys[i];
  } // shift to the right to make room at pos

  children[pos] = ptr;
  keys[pos] = ptr->getMinimum();
  count++;
  ptr->setParent(this);

  if(pos == 0 && parent)
    parent->resetMinimum(this);
} // InternalNode::addToThis()



int InternalNode::getMaximum() const
{
  if(count > 0) // should always be the case
    return children[count - 1]->getMaximum();
  else
    return INT_MAX;
}  // getMaximum();


int InternalNode::getMinimum()const
{
  if(count > 0)   // should always be the case
    return children[0]->getMinimum();
  else
    return 0;
} // InternalNode::getMinimum()


InternalNode* InternalNode::insert(int value)
{  // count must always be >= 2 for an internal node
  int pos; // will be where value belongs

  for(pos = count - 1; pos > 0 && keys[pos] > value; pos--);

  BTreeNode *last, *ptr = children[pos]->insert(value);
  if(!ptr)  // child had room.
    return NULL;

  if(count < internalSize)
  {
    addToThis(ptr, pos + 1);
    return NULL;
  } // if room for value

  last = addPtr(ptr, pos + 1);

  if(leftSibling && leftSibling->getCount() < internalSize)
  {
    addToLeft(last);
    return NULL;
  }
  else // left sibling full or non-existent
    if(rightSibling && rightSibling->getCount() < internalSize)
    {
      addToRight(ptr, last);
      return NULL;
    }
    else // both siblings full or non-existent
      return split(last);
} // InternalNode::insert()


void InternalNode::insert(BTreeNode *oldRoot, BTreeNode *node2)
{ // Node must be the root, and node1
  children[0] = oldRoot;
  children[1] = node2;
  keys[0] = oldRoot->getMinimum();
  keys[1] = node2->getMinimum();
  count = 2;
  children[0]->setLeftSibling(NULL);
  children[0]->setRightSibling(children[1]);
  children[1]->setLeftSibling(children[0]);
  children[1]->setRightSibling(NULL);
  oldRoot->setParent(this);
  node2->setParent(this);
} // InternalNode::insert()


void InternalNode::insert(BTreeNode *newNode)
{ // called by sibling so either at beginning or end
  int pos;

  if(newNode->getMinimum() <= keys[0]) // from left sibling
    pos = 0;
  else // from right sibling
    pos = count;

  addToThis(newNode, pos);
} // InternalNode::insert(BTreeNode *newNode)


void InternalNode::print(Queue <BTreeNode*> &queue)
{
  int i;

  cout << "Internal: ";
  for (i = 0; i < count; i++)
    cout << keys[i] << ' ';
  cout << endl;

  for(i = 0; i < count; i++)
    queue.enqueue(children[i]);

} // InternalNode::print()


BTreeNode* InternalNode::remove(int value)
{  // to be written by students
	
	int pos ;
	//find which key to go down to delete the value
	for (pos = count-1 ; pos > 0 && keys[pos] > value ; pos--);
	children[pos]->remove(value) ;//go down that child of internal node and call its remove function
	for (int i = 0 ; i < count ; i++)//after the value had been removed update all the keys in this internal node so that each key holds the minimum of its child.
		keys[i] = children[i]->getMinimum();	

	bool oneLessKey = false ;//check if one of the keys is 0, if it is, move all keys over by one so that the zero is gone. 
	int indexOfNoKey ;	
	for (int i = 0 ; i<count; i++)
		if (keys[i] == 0) 
			{ 
				oneLessKey = true ;
				indexOfNoKey = i ;
			} 
	if (oneLessKey==true)
	{ 
		for (int i = indexOfNoKey; i < count-1 ; ++i)
			children[i] = children[i+1] ;
		count--;
	}
	
	//update keys again
	for (int i = 0 ; i < count ; i++)
		keys[i] = children[i]->getMinimum();
		
	if (!leftSibling && !rightSibling && count == 1)//If this Internal Node has no leftsibling and no rightsibling then it is the root. If this node is the root and it only has 1 child, return the pointer to the child to BTree so that BTree can make the child the new root.
		return children[0] ;
	
	int minimumM ;//minimum keys and children each internal node should have.
	if(internalSize%2 == 0)
		minimumM = internalSize/2 ; 
	else
		minimumM = (internalSize/2) + 1;

	if (count < minimumM)//if this node has less than the minimum
	{
		if (leftSibling)
		{
			//borrow from left or merge with left
		}
		else if(rightSibling)
		{
			InternalNode* right = (InternalNode*)rightSibling	;		

			if(rightSibling->getCount() > minimumM)
			{//borrow from right
				keys[count] = right->keys[0] ;
				children[count++] = right->children[0] ;
				for (int i = 1 ; i < right->count; ++i)	
				{		
					right->keys[i-1] = right->keys[i] ;
					right->children[i-1] = right->children[i] ;
			
				}
				
				right->count-- ;
			}
			else
			{//merge with right
				for (int i = 0 ; i < right->getCount() ; ++i)
				{
					keys[count] = right->keys[i] ;
					children[count++] = right->children[i] ;
					right->keys[i] = 0 ;  
				}
				right->count = 0 ;
			}
		}
		


	}
	//update rightSibling
 	if (leftSibling && leftSibling->getCount() == 0)
		leftSibling = leftSibling->getLeftSibling() ;
	if (rightSibling && rightSibling->getCount() == 0)
		rightSibling = rightSibling->getRightSibling() ;
	return this; // filler for stub
} // InternalNode::remove(int value)


void InternalNode::resetMinimum(const BTreeNode* child)
{
  for(int i = 0; i < count; i++)
    if(children[i] == child)
    {
      keys[i] = children[i]->getMinimum();
      if(i == 0 && parent)
        parent->resetMinimum(this);
      break;
    }
} // InternalNode::resetMinimum()


InternalNode* InternalNode::split(BTreeNode *last)
{
  InternalNode *newptr = new InternalNode(internalSize, leafSize,
    parent, this, rightSibling);


  if(rightSibling)
    rightSibling->setLeftSibling(newptr);

  rightSibling = newptr;

  for(int i = (internalSize + 1) / 2; i < internalSize; i++)
  {
    newptr->children[newptr->count] = children[i];
    newptr->keys[newptr->count++] = keys[i];
    children[i]->setParent(newptr);
  }

  newptr->children[newptr->count] = last;
  newptr->keys[newptr->count++] = last->getMinimum();
  last->setParent(newptr);
  count = (internalSize + 1) / 2;
  return newptr;
} // split()

