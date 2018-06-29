#include<iostream>
#include"progression.h"
using namespace std;

int main()
{
 Progression *prog;
 
 cout << "Arithmetic Progression with default increment\n";
 prog = new ArithProgression();
 prog->printProgression(10);
 cout << "Arithmetic Progression with increment 5\n";
 prog = new ArithProgression(5);
 prog->printProgression(10);
 
 cout << "Geometric Progression with default base\n";
 prog = new GeomProgression(1);
 prog->printProgression(10);
 cout << "Geometric Progression with base 3\n";
 prog = new GeomProgression(3);
 prog->printProgression(10);
 
 cout << "Fibonacci Progression with default start values\n";
 prog = new FibonacciProgression(1,1);
 prog->printProgression(10);
 cout << "Fibonacci Progression with start values 4 and 6\n";
 prog = new FibonacciProgression(4,6);
 prog->printProgression(10);
    
system("pause");
return 0;    
}
