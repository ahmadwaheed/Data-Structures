#include<iostream>
#include"StaticQueue.h"
using namespace std;

int main()
{
 IntQueue queue(101);
 int value;
 
 for(int i=0;i<101;i+=5)
 {
  cout << "Adding " << i << endl;
  queue.enqueue(i);
 }cout << endl;
 
 cout << "Dequeuing the Queue" << endl;
 while(!queue.isEmpty())
 {
  queue.dequeue(value); 
  cout << value << " ";
 }cout << endl;
                         
system("pause");
return 0;    
}
