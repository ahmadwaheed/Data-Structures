#include<iostream>
#include"DynamicStack.h"
using namespace std;

int main()
{
 DynStack stack;
 int value;
 
 cout << "Pushing 10." << endl;
 stack.push(10);
 cout << "Pushing 20." << endl;
 stack.push(20);
 cout << "Pushing 30." << endl;
 stack.push(30);
 cout << "Pushing 40." << endl;
 stack.push(40);
 cout << "Pushing 50." << endl;
 stack.push(50);
 cout << "Pushing 60." << endl;
 stack.push(60);
 cout << "Pushing 70." << endl;
 stack.push(70);
 cout << "Pushing 80." << endl;
 stack.push(80);
 cout << "Pushing 90." << endl;
 stack.push(90);
 cout << "Pushing 100." << endl;
 stack.push(100);
 
 cout << "\nPopping 10." << endl;
 stack.pop(value); 
 cout << "Popping 20." << endl;
 stack.pop(value); 
 cout << "Popping 30." << endl;
 stack.pop(value); 
 cout << "Popping 40." << endl;
 stack.pop(value); 
 cout << "Popping 50." << endl;
 stack.pop(value); 
 cout << "Popping 60." << endl;
 stack.pop(value); 
 cout << "Popping 70." << endl;
 stack.pop(value);
 cout << "Popping 80." << endl;
 stack.pop(value);
 cout << "Popping 90." << endl;
 stack.pop(value);
 cout << "Popping 100." << endl;
 stack.pop(value);
 cout << "Popping 100." << endl;
 stack.pop(value);
 
   
system("pause");
return 0;    
}
