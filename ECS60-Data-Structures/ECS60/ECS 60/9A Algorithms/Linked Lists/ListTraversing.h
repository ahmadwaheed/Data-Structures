#ifndef LISTTRAVERSING_H
#define LISTTRAVERSING_H
#include<iostream>
using namespace std;

class NumberList
{
 protected:
   struct ListNode
   {
    double value;
    ListNode *next;
    ListNode(double value,ListNode *next = NULL)
    {
     this->value = value;
     this->next = next;
    }
   };
   ListNode *head;
 public:
   NumberList() { head = NULL; }
   ~NumberList();
   void add(double number);
   void remove(double number);
   void display(); 
};

/*=============================================
add function adds a new element to the end
of the list
===============================================*/
void NumberList::add(double number)
{
 if(head == NULL)              //If the list is empty, allocate memory for the list
  head = new ListNode(number);    
 else
 {    
  ListNode *nodePtr = head;      //The list is not empty. Use nodePtr to traverse the list 
  while(nodePtr->next != NULL)   
   nodePtr = nodePtr->next;      // using nodePtr to traversing to next element
   nodePtr->next = new ListNode(number);  // nodePtr->next is NULL so nodePtr points to the last node. Create a new node and put it after the last node
 }
}

/*==================================================
It displays the sequence of all elements in the list
====================================================*/
void NumberList::display()
{
 ListNode *nodePtr = head;  // start at the head of the list
 
 while(nodePtr)
 {
  cout << nodePtr->value << " ";  //Prints the value
  nodePtr = nodePtr->next;    // Moves and prints next value in the list 
 }
}

/*===================================================
Destructor deallocates the memory used by the list
=====================================================*/
NumberList::~NumberList()
{
 ListNode *nodePtr = head;  // start at head of list
 while(nodePtr != NULL)
 {
  ListNode *garbage = nodePtr;  // garbage keeps track of the node to be deleted
  nodePtr = nodePtr->next;
  delete garbage;
 }
}

class SortedNumberList: public NumberList
{
 public:
   void add(double number);
};

/*=====================================================
Adds a number to the sorted list.
This function overrides add in NumberList
=======================================================*/
void SortedNumberList::add(double number)
{
 ListNode *nodePtr, *previousNodePtr;
 
 if(head == NULL || head->value >= number)
 {
  head = new ListNode(number,head); // A new node goes at the beginning of the list
 }
 else
 {
  previousNodePtr = head;
  nodePtr = head->next;
  
  while(nodePtr != NULL && nodePtr->value < number) // Find the insertion point
  {
   previousNodePtr = nodePtr;
   nodePtr = nodePtr->next;
  }
  previousNodePtr->next = new ListNode(number,nodePtr); // Indert new node before nodePtr
 }
}

/*=====================================================
Removes a number from a list. The function does not 
assume that the list is sorted
=======================================================*/
void NumberList::remove(double number)
{
 ListNode *nodePtr,*previousNodePtr;
 
 if(!head)  // If the list is empty do nothing
 return;
 
 if(head->value == number) // Determine if the first node is the one to delete
 {
  nodePtr = head;     // Sets the pointer of head equal to node pointer
  head = head->next;  // head moves to next pointer node
  delete nodePtr;     // delete the selected pointer
 }
 else
 { 
  nodePtr = head;  //Initialize nodePtr to the head of the list
  while(nodePtr != NULL && nodePtr->value != number)  //Skip nodes whose value member is not number
  {
   previousNodePtr = nodePtr;
   nodePtr = nodePtr->next;
  }
  if(nodePtr)  // Link the previous node to node after nodePtr, then delete nodePtr 
  {
   previousNodePtr->next = nodePtr->next;
   delete nodePtr;
  }
 }
}
#endif
 
