#ifndef RECURSIVELIST1_H
#define RECURSIVELIST1_H
#include<iostream>
using namespace std;

class NameList
{
 protected:
   struct ListNode
   {
    string name;
    ListNode *next;
    ListNode(string name,ListNode *next = NULL)
    {
     this->name = name;
     this->next = next;
    }
   };
   ListNode *head;
 public:
   NameList() { head = NULL; }
   ~NameList();
   void add(string name)
   { head = RecursiveAdd(head,name); }
   void remove(string name)
   { head = RecursiveRemove(head,name); }
   void display()
   { RecursiveDisplay(head); }
   int size()
   { RecursiveSize(head); }
 private:
   ListNode *RecursiveAdd(ListNode *aList,string name);
   ListNode *RecursiveRemove(ListNode *aList,string name);
   void RecursiveDisplay(ListNode *aList);
   int RecursiveSize(ListNode *aList);
};
#endif

NameList::~NameList()
{
 ListNode *nodePtr = head;
 
 while(nodePtr != NULL)
 {
  ListNode *garbage = nodePtr;
  nodePtr = nodePtr->next;
  delete garbage;
 }
}

NameList::ListNode *NameList::RecursiveAdd(ListNode *aList,string name)
{
 if(aList == NULL)
  return new ListNode(name);
 else
  aList->next = RecursiveAdd(aList->next,name);
  return aList;
}

NameList::ListNode *NameList::RecursiveRemove(ListNode *aList,string name)
{
 if(aList == NULL)
  return NULL;
 if(aList->name == name)
 {
  ListNode *nodePtr = aList->next;
  delete nodePtr;
  return aList;
 }
 else
 {
  aList->next = RecursiveRemove(aList->next,name);
  return aList;
 }
}

void NameList::RecursiveDisplay(ListNode *aList)
{
 if(aList != NULL){
  cout << aList->name << " ";
  RecursiveDisplay(aList->next);
 }
}
