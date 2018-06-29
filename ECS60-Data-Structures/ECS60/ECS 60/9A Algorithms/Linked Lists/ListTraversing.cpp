#include<iostream>
#include"ListTraversing.h"
using namespace std;

int main()
{
 NumberList list;
 
 list.add(11.1);
 list.add(22.2);
 list.add(33.3);
 list.add(44.4);
 list.add(1.1);
 list.add(26.7);
 list.display();
 list.remove(11.1); cout << endl;
 list.display();
 cout << endl;   
    
system("pause");
return 0;    
}
