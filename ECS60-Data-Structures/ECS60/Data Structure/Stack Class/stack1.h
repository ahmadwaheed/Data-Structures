#include<iostream>
#ifndef STACK1_H
#define STACK1_H
using namespace std;

class ListStack
{
 private:
   struct node
   {
    int num;
    node *next;
   } *top;
   
 public:
   ListStack()
   { top = NULL; }
   
   void push();
   void pop();
   void display();
};

void ListStack::push()
{
 node *newNode;
 newNode = new node;
 cout << "Enter a number to add on stack: ";
 cin >> newNode->num;
 newNode->next = top;
 top = newNode;
}

void ListStack::pop()
{
 node *temp;
 temp = top;
 
 if(top == NULL)
  cout << "Stack UnderFlow: " << endl;
 else
 {
  cout << "Deleted number from the stack = ";
  cout << top->num;
  top = top->next;
  delete temp;
 }
}
#endif
