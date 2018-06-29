//This program uses template and compare two strings
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class object,class comparator>
const object &findMax(const vector<object> &arr,comparator cmp)
{
 int maxIndex = 0;
 
 for(int i=1;i<arr.size();++i)
  if(cmp.isLessThan(arr[maxIndex],arr[i]))
   maxIndex = i;
   
 return arr[maxIndex];
}
class CaseInsensitiveCompare
{
 public:
   bool isLessThan(const string &lhs,const string &rhs)const
   { return strcasecmp(lhs.c_str(),rhs.c_str())< 0; }
}; 
 
int main()
{
 vector<string> arr = {"ZEBRA","alligator","crocodile"};
 
 cout << findMax(arr,CaseInsensitiveCompare{}) << endl; 
    
system("pause");    
return 0;    
}
