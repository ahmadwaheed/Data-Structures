#include<iostream>
#include"ClassTraverse.h"
using namespace std;

int main()
{
 LinkedList list;
 list.add(236.5,"Muhammad");
 list.add(58.48,"Ahmad");
 list.add(234.66,"Waheed");
 list.add(44.33,"Salimi");
 list.display();
 cout << endl;
 list.remove(236.5,"Muhammad");
 list.remove(58.48,"Ahmad");
 list.remove(44.33,"Salimi");
 list.display();
    
system("pause");
return 0;    
}
