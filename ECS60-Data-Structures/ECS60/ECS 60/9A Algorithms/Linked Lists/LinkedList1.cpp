//This program illustrates the creation of linked list
#include<iostream>
using namespace std;

struct ListNode1
{
 double value;
 ListNode1 *next1;
};

struct ListNode2
{
 string name;
 ListNode2 *next2;
};

int main()
{
 ListNode1 *head1;
 
 //Create first node with 12.5
 head1 = new ListNode1;  //Allocate new node
 head1->value = 10.1;
 head1->next1 = NULL;
 
 //Create second node
 ListNode1 *second1;
 
 second1 = new ListNode1;
 second1->value = 20.2;
 second1->next1 = NULL;  //second node is end of list
 head1->next1 = second1;  // First node points to second
 
//=== This part belongs to Strings =====================//

 cout << "First Value:  " << head1->value << endl;
 cout << "Second Value: " << head1->next1->value << endl;
 cout << "Second Value: " << second1->value << endl;
 
 ListNode2 *head2;  
 ListNode2 *second2;
 ListNode2 *third2;
 ListNode2 *fourth2;

 head2 = new ListNode2; 
 head2->name = "Ahmad";
 head2->next2 = NULL;

 second2 = new ListNode2;
 second2->name = "Waheed";
 second2->next2 = NULL;
 head2->next2 = second2;

 third2 = new ListNode2;
 third2->name = "Salimi";
 third2->next2 = NULL;
 second2->next2 = third2;

 fourth2 = new ListNode2;
 fourth2->name = "Muhammad";
 fourth2->next2 = NULL;

 cout << endl;
 cout << "Fourth String: " << fourth2->name << endl;
 cout << "First String:  " << head2->name << endl;
 cout << "Second String: " << head2->next2->name << endl;
 cout << "Third String:  " << second2->next2->name << endl;
 cout << endl;
  
system("pause");
return 0;    
}
