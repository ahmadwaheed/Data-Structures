#ifndef PROGRESSION_H
#define PROGRESSION_H
#include<iostream>
using namespace std;

class Progression
{
 protected:
   long first;
   long cur;
   virtual long firstValue();
   virtual long nextValue();
 public:
   Progression(long f = 0)
   {
    first = f;
    cur = f;
   }
   virtual ~Progression(){};
   void printProgression(int n);
}

class ArithProgression:public Progression
{
 protected:
   long inc;
   virtual long nextValue();
 public:
   ArithProgression(long i = 1)
   { 
    Progression(1);
    inc = i;
   }
};

class GeomProgression:public Progression
{
 protected:
   long base;
   virtual long nextValue();
 public:
   GeomProgression(long b)
   {
    Progression(1);
    base = b;
   }
};
 
class FibonacciProgression:public Progression
{
 protected:
   long second;
   long prev;
   virtual long firstValue();
   virtual long nextValue();
 public:
   FibonacciProgression(long g,long s)
   {
    Progression(1);
    second = s;
    prev = second - first;
    return cur;
   }
};                        
#endif
// Progression class
long Progression::firstValue()
{
 cur = first;
 return cur;
}

long Progression::nextValue()
{
 return ++cur;
} 

void Progression::printProgression(int n)
{
 cout << firstValue();
 for(int i=2;i<=n;i++)
  cout << " " << nextValue();
  cout << endl;
}  
 
//ArithProgression class
long ArithProgression::nextValue()
{
 cur += inc;
 return cur;
}

//GeomProgression class
long GeomProgression::nextValue()
{
 cur *= base;
 return cur;
}

//FibonacciProgression class
long FibonacciProgression::nextValue()
{
 long temp = prev;
 prev = cur;
 cur += temp;
 return cur;
}
