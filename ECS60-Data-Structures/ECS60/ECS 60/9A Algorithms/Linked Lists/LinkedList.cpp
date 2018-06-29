#include<iostream>
using namespace std;

struct LinkedList
{
 double number;
 LinkedList *next;
};
 
 
int main()
{
 LinkedList *first;
 LinkedList *second;
 LinkedList *third;
 
 first = new LinkedList;
 first->number = 111.1;
 first->next = NULL;
 
 second = new LinkedList;
 second->number = 222.2;
 second->next = NULL;
 first->next = second;
 
 third = new LinkedList;
 third->number = 333.3;
 third->next = NULL;
 second->next = third;
 
 cout << "First:  " << first->number << endl;
 cout << "Second: " << second->number << " " << first->next->number << endl; 
 cout << "Third:  " << third->number << " " << second->next->number << endl;
 
system("pause");
return 0;    
}
