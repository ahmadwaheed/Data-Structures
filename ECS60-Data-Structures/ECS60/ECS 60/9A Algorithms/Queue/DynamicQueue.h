#ifndef DYNAMICQUEUE_H
#define DYNSMICQUEUE_H
#include<iostream>
using namespace std;

class DynQueue
{
 private:
  class QueueNode 
  {
   friend class DynQueue;  // DynQueue is friend of this class
   int value;
   QueueNode *next;
   QueueNode(int value,QueueNode *next = NULL)
   {
    this->value = value;
    this->next = next;
   }
  };
  QueueNode *front;
  QueueNode *rear;
 public:
   DynQueue();
   ~DynQueue();
   void enqueue(int);
   void dequeue(int&);
   bool isEmpty();
};
#endif

DynQueue::DynQueue()
{
 front = NULL;
 rear = NULL;
}

DynQueue::~DynQueue()
{
 int value;
 
 while(!isEmpty())
  dequeue(value);
}
 
void DynQueue::enqueue(int num)
{
 if(isEmpty())
 {
  front = new QueueNode(num);
  rear = front;
 } 
 else
 {
  rear->next = new QueueNode(num);
  rear = rear->next;
 }
}

void DynQueue::dequeue(int &num)
{
 QueueNode *nodePtr;
 
 if(isEmpty())
 {
  cout << "Queue is empty." << endl;
 }
 else
 {
  num = front->value;
  nodePtr = front;
  front = front->next;
  delete nodePtr;
 }
} 

bool DynQueue::isEmpty()
{
 if(front == NULL)
  return true;
 else
  return false;
}
