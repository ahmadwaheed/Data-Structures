#include<iostream>
using namespace std;

class Square
{
 private:
   double side;
 public:
   explicit Square(double s = 0.0)
   { side = s; }
   
   double getSide()
   { return side; }
   
   double getArea()
   { return side * side; }
   
   double getPerimeter()
   { side * 4; }
   
   void print(ostream &out = cout)const
   { out << "(square " << getSide() << ")"; }
   
   bool operator<(const Square &rhs) const
   { return getSide() < rhs.getSide(); }
};

ostream &operator<<(ostream &out,const Square &rhs)
{
 rhs.print(out);
 return out;
}
template<class Comparable>
const Comparable &findMax(const vector<Comparable> &a)
{
 int maxIndex = 0;
 
 for(int i=0;i<a.size();i++)
  if(a[maxIndex] < a[i])
  maxIndex = i;
 return a[maxIndex];
}

int main()
{
 vector<Square> v = {Square{3.0},Square{2.0},Square{2.5}};
 
 cout << "Largest square: " << findMax(v) << endl;
       
system("pause");
return 0;    
}
