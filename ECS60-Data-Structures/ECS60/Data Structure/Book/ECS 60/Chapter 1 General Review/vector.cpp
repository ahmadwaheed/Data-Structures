#include<iostream>
#include<vector>
using namespace std;

int main()
{
 vector<int> squares(100);
 
 for(int i=0;i<squares.size();i++)
 { squares[i] = i*i; }
 
 for(int j=0;j<squares.size();j++)
 { cout << j << " " << squares[j] << endl; }   
    
system("pause");
return 0;    
}
