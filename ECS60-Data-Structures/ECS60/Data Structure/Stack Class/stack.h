#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;

class Stack
{
 private:
   int *stackArray;
   int stackSize;
   int top;
 public:
   Stack(int size)
   {
    stackArray = new int[size];
    stackSize = size;
    top = -1; 
   }
   bool isEmpty();
   bool isFull();
   void push();
   void pop();
   void displayStack();
   void displayTopElement();
};
#endif
void Stack::push()
{
 int num;
 
 if(top >= stackSize)
  cout << "Stack OverFlow " << endl;
 else
 {
  cout << "Enter number: ";
  cin >> num;
  top++;
  stackArray[top] = num;
 }
}

void Stack::pop()
{
 if(top == -1)
 cout << "Stack Underflow" << endl;
 else
 {
  cout << "Number deleted from the stack = ";
  cout << stackArray[top];
  top--;
 }
}
