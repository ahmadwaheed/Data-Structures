#include<iostream>
#include"stack.h"
using namespace std;

int main()
{
 Stack stack(5);
 int choice;
 
 do
 {
  cout << "=====MENU=====" << endl;
  cout << "1) PUSH " << endl;
  cout << "2) POP  " << endl;
  cout << "3) DISPLAY " << endl;
  cout << "4) Enter Choice: " << endl;
  cin >> choice;
  
  switch(choice)
  {
   case 1: stack.push();
   break;
   case 2: stack.pop();
   break;
   //case 3: stack.displayStack();
  // break;
  }
 }while(choice != 4);

system("pause");
return 0;    
}
