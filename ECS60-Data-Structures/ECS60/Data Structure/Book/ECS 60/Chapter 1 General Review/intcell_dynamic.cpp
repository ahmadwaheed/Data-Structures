#include<iostream>
#include"intcell.h"
using namespace std;

int main()
{
 IntCell *cell;
 
 cell = new IntCell();
 
 cell->write(90);
 cout << "Cell Contents: " << cell->read();   
 
 delete cell;
    
system("pause");
return 0;    
}
