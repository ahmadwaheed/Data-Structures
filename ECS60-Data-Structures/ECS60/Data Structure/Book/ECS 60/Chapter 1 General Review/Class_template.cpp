//A class for simulting a memory cell
#include<iostream>
using namespace std;

template<class object>
class MemoryCell
{
 private:
   object storedValue;
 public:
   explicit MemoryCell(const object &initialValue = object{})
   { storedValue = initialValue; }
   
   const object &read() const
   { return storedValue; }
   
   void write(const object &x)
   { storedValue = x; }
};

int main()
{
 MemoryCell<int> m1;
 MemoryCell<string> m2{"Hello"};
 
 m1.write(37);
 m2.write(m2.read()+ " world!");
 cout << m1.write() << " " << m2.write() << endl;   
    
system("pause");
return 0;    
}
