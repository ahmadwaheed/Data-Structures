#include<iostream>
using namespace std;

struct Node
{
 int data;
 Node *next;
};

Node *Insert(Node *head,int data)
{
 Node *nodePtr = new Node();
 nodePtr->data = data;
 nodePtr->next = NULL;
 if(head == NULL) 
  head = nodePtr;
 else
  {
   Node *nodePtr1 = head;
   while(nodePtr1->next != NULL)
    nodePtr1 = nodePtr1->next;
    nodePtr1->next = nodePtr;
  }
  return head;
}

void Print(Node *p)
{
 if(p == NULL)
  return;
 Print(p->next); // Recursive Call
 cout << p->data << " ";  // First print the value in the node
}

int main()
{
 Node *head = NULL;
 
 head = Insert(head,1);
 head = Insert(head,2);
 head = Insert(head,3);
 head = Insert(head,4);
 head = Insert(head,5); 
 Print(head);
 cout << endl;
  
system("pause");
return 0;    
}
