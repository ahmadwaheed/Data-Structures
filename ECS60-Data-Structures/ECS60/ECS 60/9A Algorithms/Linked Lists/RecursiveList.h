#ifndef RECURSIVE_H
#define RECURSIVE_H
#include<iostream>
using namespace std;

class NumberList
{
 protected:
   struct ListNode
   {
    double data;
    ListNode *next;
    ListNode(double data,ListNode *next = NULL)
    {
     this->data = data;
     this->next = next;
    }
   };
    ListNode *head;
 public:
  NumberList() { head = NULL; }
  ~NumberList();
  void add(double value)
  { head = RecursiveAdd(head,value); }
  void remove(double value)
  { head = RecursiveRemove(head,value); }
  void displayList()
  { RecursiveDisplay(head); }
  int size()
  { return RecursiveSize(head); }
 private:
  //Recursive Implementation
  ListNode *RecursiveAdd(ListNode *aList,double value);
  ListNode *RecursiveRemove(ListNode *aList,double value);
  void RecursiveDisplay(ListNode *aList);
  int RecursiveSize(ListNode *aList);
};
#endif

/*=========================================
Returns the number of elements in the list
===========================================*/
int NumberList::RecursiveSize(ListNode *aList)
{
 if(aList == NULL)      
  return 0;
 else
  return 1 + RecursiveSize(aList->next);
}

/*=========================================
Prints all the elements in the list
===========================================*/
void NumberList::RecursiveDisplay(ListNode *aList)
{
 if(aList != NULL)
 {
  cout << aList->data << " ";
  RecursiveDisplay(aList->next);
 }
}

/*===========================================
Destructor releases the memory
=============================================*/
NumberList::~NumberList()
{
 ListNode *nodePtr = head;
 
 while(ptr != NULL)
 {
  ListNode *garbage = nodePtr;
  nodePtr = nodePtr->next;
  delete garbage;
 }
}

/*=============================================
This function add a member in the list
===============================================*/
NumberList::ListNode *NumberList::RecursiveAdd(ListNode *aList,double value)
{
 if(aList == NULL)
  return new ListNode(value);
 else
 {
  aList->next = RecursiveAdd(aList->next,value);
  return aList;
 }
}

/*==============================================
This function will delete the node
================================================*/
NumberList::ListNode *NumberList::RecursiveRemove(ListNode *aList,double value)
{
 if(aList == NULL)
  return NULL;
 if(aList->data == value)  // See if value is first on the list. If so, delete the value and return the tail.
 {
  ListNode *nodePtr = aList->next;
  delete aList;
  return nodePtr;
 }
 else // Value is not the first on the list. Return the list with the value removed from tail of list.
 {
  aList->next = RecursiveRemove(aList->next,value);
  return aList;
 }
}
