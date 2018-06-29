#include<iostream>
#include"intcell.h"
using namespace std;

int main()
{
 IntCell cell(45);
 
 //cell.write(45);
 cout << "Cell Contents: " << cell.read() << endl; 
    
system("pause");
return 0;    
}
