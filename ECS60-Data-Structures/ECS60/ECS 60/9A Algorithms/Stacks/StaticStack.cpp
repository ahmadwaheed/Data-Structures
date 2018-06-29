//This is the implementation file for Stacks with the rule of FIRST IN LAST OUT (FILO)
#include<iostream>
#include"StaticStack.h"
using namespace std;

int main()
{
 Stack stack(200);
 int values[200];// = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
 int value;
 
 
 // Pushing values
 for(int i=0;i<202;i+=2)
 {
  cout << "Pushing " << i << endl;
  stack.push(i);
  //cout << values[i] << " ";
  //stack.push(values[i]);
 } cout << endl;
 
 while(!stack.isEmpty())
 {
  stack.pop(value);
  cout << value << " ";
 } cout << endl;
 
system("pause");
return 0;    
} 
