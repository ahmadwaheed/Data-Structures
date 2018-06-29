#include<iostream>
using namespace std;

struct Node
{
 int data;
 Node *next;
 Node *prev;
};
Node *head;

Node *GetNewNode(int x)
{
 Node *nodePtr = new Node();
 
 nodePtr->data = x;
 nodePtr->next = NULL;
 nodePtr->prev = NULL;
 return nodePtr;
}

void InsertAtHead(int x)
{
 Node *newNode = GetNewNode(x);
 if(head == NULL)
 {
  head = newNode;
  return;
 }
 head->prev = newNode;
 newNode->next = head;
 head = newNode;    
}

void Print()
{
 Node *nodePtr = head;
 while(nodePtr != NULL)
 {
  cout << nodePtr->data << " ";             
  nodePtr = nodePtr->next;
 } cout << endl;
}

void ReversePrint()
{
 Node *nodePtr = head;
 if(nodePtr == NULL)
  return;  // empty list, exit
   
 //Going to last node
 while(nodePtr->next != NULL)
 { nodePtr = nodePtr->next; }
 
 //Traversing the list using prev pointer
 cout << "Reverse: ";
 while(nodePtr != NULL)
 {
  cout << nodePtr->data << " ";
  nodePtr = nodePtr->prev;
 } cout << endl;
}

int main()
{
 head = NULL;
 InsertAtHead(2);
 InsertAtHead(4);
 InsertAtHead(6);
 InsertAtHead(8);
 InsertAtHead(10);
 Print();
 ReversePrint();
    
system("pause");
return 0;    
}
