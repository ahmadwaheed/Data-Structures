#include<iostream>
using namespace std;

class CirQueue
{
 private:
   int queue[5];
   int rear;
   int front;
   int maxSize;
   int counter;
 public:
   CirQueue();
   void enqueue();
   void dequeue();
   bool isEmpty();
   bool isFull();
   void display();
};

// constructor definition
CirQueue::CirQueue()
{
 front = 0;
 rear = -1;
 maxSize = 5;
 counter = 0;
}

// This program adds up a number in the queue
void CirQueue::enqueue()
{
 if(isFull())
  cout << "Queue is full.";
 else
 {
  rear = (rear + 1) % maxSize;
  cout << "Enter Data: ";
  cin >> queue[rear];
  counter++;
 }
}

//This proram deletes number from the queue
void CirQueue::dequeue()
{
 if(isEmpty())
  cout << "Queue is empty.";
 else
 {
  cout << "Element deleted = " << queue[front];
  front = (front + 1)% maxSize;
  counter--;
 }
}

void CirQueue::display()
{
 if(isEmpty())
  cout << "Queue is empty.";
  else
  {
   for(int i=0;i<counter;i++)
    cout << queue[(front + i) % maxSize] << endl;
  }
}

bool CirQueue::isEmpty()
{
 if(counter == 0)
  return true;
 else
  return false;
}

bool CirQueue::isFull()
{
 if(counter < maxSize)
  return false;
 else
  return true;
}

int main()
{
 CirQueue circle;
 
 for(int i=0;i<4;i++)
 circle.enqueue();
 //circle.dequeue();
 //circle.display();
 
system("pause");
return 0; 
}
