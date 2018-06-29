#include<iostream>
using namespace std;

struct Node
{
 int data;  // To store data
 Node *next; // To store the pointer of the next node
};

void Print();
void Insert(int,int);
void Delete(int);
void Reverse(Node *);

Node *head;  // First node of the list (Make it global)

int main()
{
 int n;
 head = NULL; 
 Insert(2,1);  // List:(2,1)
 Insert(4,2);  // List:(4,2)
 Insert(6,3);  // List(6,3)
 Insert(8,4);  // List:(10,5)
 Insert(12,5); // List:(8,4)
 Insert(15,6);
 Print();
 //head = Reverse(head);
 Print();
 
 cout << "Enter a position in order to delete it: ";
 cin >> n;
 Delete(n);
 Print();
 
system("pause");
return 0;
}

void Insert(int FuncData,int n)
{
 Node *temp = new Node;  // Dynamically allocate the memory
 temp->data = FuncData;  // setting the data 
 temp->next = NULL;  // setting the head next equal to NULL
 
 if(n == 1)   //If the index is equal to 1
 {
  temp->next = head;  // Next node is equal to the head node
  head = temp;  // Now head is the temp one
  return;
 }
 Node *tempp = head;
 for(int i=0;i<n-2;i++)
 { tempp = tempp->next; }
 
 temp->next = tempp->next;
 tempp->next = temp;
}
 
void Delete(int n)
{
 Node *temp = head;
 if(n == 1) 
 {
  head = temp->next;
  delete temp;
  return; 
 } 
 for(int i=0;i<n-2;i++)
  temp = temp->next;
  
 Node *tempp = temp->next;
 temp->next = tempp->next;
 delete tempp;
}

/*
Node *Reverse(Node *head)
{
 Node *current,*prev,*next;
 current = next;
 Prev = NULL;
 
 while(current != NULL)
 { 
  next = current->next;
  current->next = prev;
  prev = current;
  current = next;
 }
 head = prev;
}
*/  
  
void Print()
{
 Node *temp = head;
 
 while(temp != NULL)
 {
  cout << temp->data << " ";
  temp = temp->next;
 }
 cout << endl;
}
