#ifndef CLASSTRAVERSE_H
#define CLASSTRAVERSE_H
using namespace std;

class LinkedList
{
 protected:
   struct ListNode
   {
    double number;
    string name;
    ListNode *next;
    ListNode(double number,string name,ListNode *next = NULL)
    {
     this->number = number;
     this->name = name;
     this->next = next;
    }
   };
   ListNode *head;
 public:
   LinkedList() 
   { head = NULL; }
   ~LinkedList();
   void add(double num,string name);
   void remove(double num,string name);
   void display();
};

#endif

/*=================================================
add adds a value in the list 
===================================================*/
void LinkedList::add(double number,string name)
{
 if(head == NULL)
  head = new ListNode(number,name);
 else
 {
  ListNode *nodePtr = head;
  while(nodePtr->next != NULL)
   nodePtr = nodePtr->next;
   nodePtr->next = new ListNode(number,name);
 } 
}

/*================================================
This function displays the list
==================================================*/
void LinkedList::display()
{
 ListNode *nodePtr = head;
 
 while(nodePtr)
 {
  cout << nodePtr->number << " " << (*nodePtr).name << endl;  // Same pointers
  nodePtr = nodePtr->next;
 }
}

/*================================================
Destructor deallocates the memory used by the list
==================================================*/
LinkedList::~LinkedList()
{
 ListNode *nodePtr = head;
 
 while(nodePtr != NULL)
 {
  ListNode *junk = nodePtr;
  nodePtr = nodePtr->next;
  delete junk;
 }
}

/*==================================================
Remove deletes the entry from the list
====================================================*/
void LinkedList::remove(double numValue,string nameValue)
{
 ListNode *nodePtr,*previousNodePtr;
 
 if(!head)
  return;
 
 if(head->number == numValue && head->name == nameValue)
 {
  nodePtr = head;
  head = head->next;
  delete nodePtr;
 }
 else
 {
  nodePtr = head;
  while(nodePtr != NULL && head->number != numValue && head->name != nameValue)
  {
   previousNodePtr = nodePtr;
   nodePtr = nodePtr->next;
  }
  if(nodePtr)
  {
   previousNodePtr->next = nodePtr->next;
   delete nodePtr;
  }
 }
}
  
