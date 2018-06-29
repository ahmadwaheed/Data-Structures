#include<iostream>
#include"DynamicQueue.h"
using namespace std;

int main()
{
 DynQueue queue;
 int value;
 
 for(int i=0;i<500;i+=5)
 { 
  cout << "Adding " << i << " in queue." << endl; 
  queue.enqueue(i);
 }
 
 cout << "Dequeing the values from enqueue." << endl;
 while(!queue.isEmpty())
 {
  queue.dequeue(value);
  cout << value << " " << endl;
 }   
    
system("pause");
return 0;    
} 
