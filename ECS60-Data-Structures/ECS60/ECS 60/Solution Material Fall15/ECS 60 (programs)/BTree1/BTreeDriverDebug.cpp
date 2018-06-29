#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "BTree.h"

using namespace std;

int main(int argc, char *argv[])
{
	BTree tree(atoi(argv[2]), atoi(argv[3]));
	int value;
	char s[80];


	ifstream inf(argv[1]);
	while (inf >> value)
	{
		cout << "Inserting " << value << ". \n";
		tree.insert(value);
		tree.print();
		cout << endl;
		//tree.print2();
		fgets(s, 80, stdin);
	} // while
	tree.print();
	//tree.print2();
	return 0;
}  // main

