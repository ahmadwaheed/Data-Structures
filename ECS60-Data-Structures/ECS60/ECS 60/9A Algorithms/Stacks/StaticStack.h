#ifndef STATICSTACK_H
#define STATICSTACK_H
#include<iostream>
using namespace std;

class Stack
{
 private:
   int *StackArray;
   int capacity;
   int top;
 public:
   Stack(int capacity);
   ~Stack() { delete[] StackArray; }
   void push(int value);
   void pop(int &value);
   bool isEmpty();
};
#endif

Stack::Stack(int capacity)
{
 this->capacity = capacity;
 StackArray = new int[capacity];
 top = 0;
}

void Stack::push(int value)
{
 if(top == capacity)
 cout << "The Stack is full." << endl;
 StackArray[top] = value;
 top++;
}

bool Stack::isEmpty()
{
 if(top == 0)
 return true;
 else
 return false;
}

void Stack::pop(int &value)
{
 if(isEmpty() == true) 
 cout << "The Stack is empty." << endl;
 top--;
 value = StackArray[top];
}
