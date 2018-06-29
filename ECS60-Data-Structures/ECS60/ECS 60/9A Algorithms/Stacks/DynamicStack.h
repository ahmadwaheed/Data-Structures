#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H
#include<iostream>
using namespace std;

class DynStack
{
 private:
   class StackNode
   {
    friend class DynStack;
    int value;
    StackNode *next;
    StackNode(int value,StackNode *next = NULL)
    {
     this->value = value;
     this->next = next;
    }
   };
   StackNode *top;
 public:
   DynStack() { top = NULL; }
   void push(int);
   void pop(int &);
   bool isEmpty();
};
#endif

void DynStack::push(int value)
{
 top = new StackNode(value,top);
}

void DynStack::pop(int &num)
{
 StackNode *nodePtr;
 
 if(isEmpty())
 { cout << "The Stack is empty."; }
 else
 {
  num = top->value;
  nodePtr = top;
  top = top->next;
  delete nodePtr;
 }
}

bool DynStack::isEmpty()
{
 if(top == NULL)
 return true;
 else
 return false;
}

