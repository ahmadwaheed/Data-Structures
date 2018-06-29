#ifndef INTCELL_H
#define INTCELL_H
using namespace std;

//A class for simulating an integer memory cell
class IntCell
{
 private:
   int storedValue;
 public:
   explicit IntCell(int initialValue);
   int read()const;
   void write(int x);
};
#endif
IntCell::IntCell(int initialValue)//:storedValue(initialValue)
{ storedValue = initialValue; }

int IntCell::read()const
{ return storedValue; }

void IntCell::write(int x)
{ storedValue = x; }
 
