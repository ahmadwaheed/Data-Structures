#include<iostream>
#include<list>
using namespace std;

int main()
{
 list<string> myList;
 list<string>::iterator iter;
 
 myList.push_back("Ahmad");
 myList.push_back("Waheed");
 myList.push_back("Salimi");
 
 for(iter = myList.begin();iter != myList.end();iter++)
  cout << *iter << " ";
  cout << endl;
  
 myList.reverse();
 
 for(iter = myList.begin();iter != myList.end();iter++)
  cout << *iter << " ";
  cout << endl;    
    
system("pause");
return 0;    
} 
