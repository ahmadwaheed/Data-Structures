#include<iostream>
#include"stack1.h"
using namespace std;

int main()
{
 ListStack LS;
 int choice;
 
 do
 {
  cout << "=======MENU=======" << endl;
  cout << "1) Push " << endl;
  cout << "2) Pop  " << endl;
  cout << "3) Show " << endl;
  cout << "4) EXIT " << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  
  switch(choice)
  {
   case 1: LS.push();
   break;
   case 2: LS.pop();
   break;
   //case 3: LS.display();
   //break;
  }
 }while(choice != 4);
 
system("pause");
return 0;    
}
