#include<iostream>
using namespace std;

class NumberList
{
 protected: 
   //Declare a class for the list node.
   struct ListNode
   {
    double value;
    ListNode *next;
    ListNode(double value1, ListNode *next1 = NULL)
    {
     value = value1;
     next = next1;
    }
   };
   ListNode *head;
 public:
   NumberList() { head = NULL; }
   ~NumberList();
   void add(double number);
   void remove(double number);
   void displayList();
};

/*==============================================
 add adds a new element to the end of the list 
================================================*/
void NumberList::add(double number)
{
 if(head == NULL)
 head = new ListNode(number);
 else
 {
  //The List is not empty. Use nodePtr to traverse the list
  ListNode *nodePtr = head;  // setting both pointers equal 
  while(nodePtr != NULL)     
   nodePtr = nodePtr->next;  // same as  head = head->next;
   
 //nodePtr->next is NUll so nodePtr points to the last node.
 //Create a new node and put it after the last node
 nodePtr->next = new ListNode(number);
 }
}

/*===================================================
display outputs a sequence of all values currently
stored in the list
=====================================================*/
void NumberList::displayList()
{
 ListNode *nodePtr = head;  //Start at head of list
 while(nodePtr)
 {
  //Print the value in the current node
  cout << nodePtr->value << " ";
  //Move on to next node
  nodePtr = nodePtr->next;
 }
}

/*====================================================
destructor deallocates the memory used by the list
======================================================*/
NumberList::~NumberList()
{
 ListNode *nodePtr = head;  // Starts at head of the list
 while(nodePtr != NULL)
 {
  //Garbage keep track of the node to be deleted
  ListNode *garbage = nodePtr;
  //Move on next node, if any
  nodePtr = nodePtr->next;
  //delete the garbage node
  delete garbage;
 }
} 
