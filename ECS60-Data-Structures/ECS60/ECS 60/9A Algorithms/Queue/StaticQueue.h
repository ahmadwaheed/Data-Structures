#ifndef STATICQUEUE_H
#define STATICQUEUE_H
#include<iostream>
using namespace std;

class IntQueue
{
 private:
   int *queueArray;
   int size;
   int front;
   int rear;
   int numItems;
 public:
   IntQueue(int);
   ~IntQueue() { delete [] queueArray; }
   void enqueue(int);
   void dequeue(int&);
   bool isEmpty();
   bool isFull();
   void clear();
};
#endif

IntQueue::IntQueue(int s)
{
 queueArray = new int[s];
 size = s;
 front = -1;
 rear = -1;
 numItems = 0;
}

void IntQueue::enqueue(int num)
{
 if(isFull())
 { cout << "The queue is full. "; }
 else
 {
  rear = (rear + 1) % size; // Calculates the new rear position.
  queueArray[rear] = num;  // Insert new item.
  numItems++;
 }
}

void IntQueue::dequeue(int &num)
{
 if(isEmpty())
 { cout << "The queue is empty. "; }
 else
 {
  front = (front + 1) % size; //Move front
  num = queueArray[front];  //Retrieve the front item
  numItems--;  // Update item count.
 }
}

void IntQueue::clear()
{
 front = -1;
 rear = -1;
 numItems = 0;
}

bool IntQueue::isEmpty()
{
 if(numItems > 0)
 return false;
 else
 return true;
}

bool IntQueue::isFull()
{
 if(numItems < size)
 return false;
 else
 return true;
}

  

  
 
