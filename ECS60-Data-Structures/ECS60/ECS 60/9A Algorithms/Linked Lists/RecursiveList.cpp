#include<iostream>
#include"RecursiveList.h"
using namespace std;

int main()
{
 double number;
 NumberList list;
 
 list.add(243.3);
 list.add(654.4);
 list.add(433.5);
 list.add(654.4);
 cout << "The members in the list are: ";
 list.displayList();
 cout << endl;
 cout << "Enter the number to add: ";
 cin >> number;
 list.add(number);
 list.displayList();
 list.size();
 list.remove(243.3);
 cout << "\nUpdated list: ";
 list.displayList();
 cout << endl; 
 
system("pause");
return 0;    
}
