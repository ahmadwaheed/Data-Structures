#include<iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
 BinaryTree tree;
 int value;
 
 tree.insert(54);tree.insert(76);
 tree.insert(33);tree.insert(63);
 tree.insert(23);tree.insert(11);
 tree.insert(67);tree.insert(99);
 tree.insert(21);tree.insert(67);
 tree.insert(29);tree.insert(13);
 tree.insert(89);tree.insert(443);
 tree.insert(88);tree.insert(456);
 tree.insert(86);tree.insert(71);
 tree.insert(83);tree.insert(87);
 tree.insert(81);tree.insert(988);
 tree.insert(80);tree.insert(243);
 tree.insert(56);tree.insert(1);
 tree.insert(77);tree.insert(776);
 tree.insert(12);tree.insert(999);
 tree.insert(20);tree.insert(8);
 tree.insert(90);tree.insert(654);
 
 tree.showInOrder(); cout << endl;
 tree.showPreOrder(); cout << endl;
 tree.showPostOrder(); cout << endl;
 //tree.remove(89);
 //tree.showInOrder();
 
 
 cout << "The minimum number in the tree is ";
 cout << tree.findMin();
 cout << endl;
 
 cout << "The maximum number in the tree is ";
 cout << tree.findMax();
 cout << endl;
 
// cout << "The height of the tree is ";
 //cout << tree.findHeight();
// cout << endl;
 
 cout << "Enter the number you want to find out: ";
 cin >> value;
 
 if(tree.search(value))
  cout << "The number exists in the tree." << endl;
 else
  cout << "The number does not exists in the tree." << endl;
 
    
system("pause");
return 0;    
}
