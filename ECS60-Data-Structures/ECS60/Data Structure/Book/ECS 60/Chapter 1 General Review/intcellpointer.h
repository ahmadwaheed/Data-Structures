#ifndef INTCELLPOINTER_H
#define INTCELLPOINTER_H
#include<iostream>
using namespace std;

class IntCell
{
 private:
   int *storedValue;
 public:
   explicit IntCell(int initialValue = 0)
   {
    storedValue = new int[initialValue];
   }
   
   ~IntCell()
   { delete storedValue; }
   
   //copy constructor
   IntCell(const IntCell &rhs)
   {
    storedValue = new int[*rhs.storedValue];
   }
   
   //move constructor
   IntCell(IntCell &rhs)
   {
    if(this != &rhs)
     *storedValue = rhs.storedValue;
    return *this;
   }
   
   //assignment operator
   IntCell &operator=(IntCell &rhs)
   {
    std::swap(storedValue,rhs.storedValue);
    return *this;
   }
   
   int read()const
   { return *storedValue; }
   
   void write(int x)
   { *storedValue = x; }
};
#endif
   
     
