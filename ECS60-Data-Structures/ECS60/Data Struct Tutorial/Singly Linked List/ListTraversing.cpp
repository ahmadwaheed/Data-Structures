// This program will insert, delete, traverse and reverse nodes.
#include<iostream>
using namespace std;

struct Node
{
 int data;
 Node *next;
};
Node *head;

void Insert(int number,int index)
{
 // Dynamically allocating the memory
 Node *nodePtr = new Node();
 
 //Assigning the values to the data and Index
 nodePtr->data = number;
 nodePtr->next = NULL;
 
 //Covering the case in which the index is just one and we have to make that index as a head node
 if(index == 1)
 {
  nodePtr->next = head; //making the next node equal to head node
  head = nodePtr;  // next pointer is the head node now
  return;
 }
 else
 {
  Node *nodePtr1 = head;  // making a new node equal to head node
  
  for(int i=0;i<index-2;i++)
  { nodePtr1 = nodePtr1->next; }  // now, traversing the node to the next node
  nodePtr->next = nodePtr1->next;
  nodePtr1->next = nodePtr;
 }
}
 
void Delete(int n)
{
 Node *nodePtr = head;
 
 if(n == 1)
 {
  head = nodePtr->next; // head now points to second node.
  delete nodePtr;
  return;
 }
 // A case in which there is a Node before the Node we want to delete
 for(int i=0;i<(n-2);i++)
  nodePtr = nodePtr->next; // for all the nodes up to N nodePtr moves to next node
 Node *nodePtr1 = nodePtr->next;  // first node (nodePtr) pointing to next node, is equal to second node 
 nodePtr->next = nodePtr1->next;  // now, first node pointing to next is equal to second node pointing to next
 delete nodePtr1; // delete second node
}
 
void Print()
{
 Node *nodePtr = head;
 
 while(nodePtr != NULL)
 {
  cout << nodePtr->data << " ";             
  nodePtr = nodePtr->next;
 }
 cout << endl;
}
 
int main()
{
 int n;
 head = NULL;
 Insert(10,1);
 Insert(20,2);
 Insert(30,3);
 Insert(40,4);
 Insert(50,5);
 Insert(60,6);
 Insert(70,7);
 Insert(80,8);
 Insert(90,9);
 Insert(100,10);
 Print();   
 
 cout << "Enter the number you want to delete: ";
 cin >> n;
 Delete(n);
 Print();
 cout << endl;
system("pause");
return 0;    
}
