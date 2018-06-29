#include <fstream> 
#include <iomanip>
#include <iostream>
using namespace std;

struct Node
{
	int line;
	Node * next = NULL;
};
struct Element
{
	char *word = NULL;
	Node *head = NULL;
	Node *back = NULL;
	int count;
	Element * left;
	Element * right;
};
int toLower(char a)
{
	if (a < 91)
	{
		return a + 32;
	}
	else
	{
		return a;
	}
}

int compare(char * treestr, char * instr)
{
	int index = 0;
	for (; treestr[index] != '\0'; index++)
	{
		if (treestr[index] > instr[index])
		{
			return -1;
		}//the input is less than the treestr
		else if (treestr[index] < instr[index])
		{
			return 1;
		}//the input is greater than the treestr
	}
	if (instr[index] != '\0')
	{
		return 1;
	}//the words are the same but the input string is longer
	return 0;//the words are the same
}
void insertNode(Element *rootE, int lineN)
{
	Node * newNode = new Node;
	newNode->line = lineN;
	if(rootE->head == NULL)
	{
		rootE->head = newNode;
		rootE->back = newNode;
		
	}
	else
	{
		rootE->back->next = newNode;
		rootE->back = rootE->back->next;

	}
	
	
}
void printLN(Node * ln)
{
	Node * itr = ln;
	while(itr)
	{
		cout << itr->line;
		if (itr->next)
		{
			cout << ",";

		}
		itr = itr->next;
	}
}
void print(Element *thing)
{

	cout << setw(18) << left << thing->word << 
	thing->count	<< "   ";
	printLN(thing->head);
	cout << endl;

}
void inOrderPrint(Element* root)
{
	
	
	if (root)
	{
		inOrderPrint(root->left);
		print(root);
		inOrderPrint(root->right);
	}
}
int main(int argc, char ** argv)
{

	//Element testElement;
	//testElement.word = "stuff";
	//testElement.count = 5;
	//print(testElement);		
	ifstream inf(argv[1]);
	Element *root = NULL;
	//root = &testElement;
	char* l = new char[256];
	char* w = new char[32];
	int lineNumber = 1;
	for (inf.getline(l, 256); inf; inf.getline(l, 256))
	{

		
		
		int letter = 0;
		while (l[letter] != '\0')
		{
			while ( l[letter] != '\0'&& !isalpha(l[letter]))
			{
				letter++;

			}//goes until it finds the next isalpha character
			if (isalpha(l[letter]))
			{


				char * newWord = new char[40];
				int wordi = 0;

				while (isalpha(l[letter]))
				{
					newWord[wordi] = toLower(l[letter]);
					letter++;
					wordi++;
				}
				newWord[wordi] = '\0';
				//cout << newWord <<endl;
				Element * itr = NULL;
				if (root != NULL)
				{
					itr = root;
				}
				else
				{
					itr = NULL;
				}
				//cout << newWord <<endl;
				while (itr != NULL)
				{
					//cout << newWord <<endl;
					if (compare(itr->word, newWord) == -1)
					{
						if (itr->left)
						{
							itr = itr->left;
						}
						else
						{
							Element *newE = new Element;
							newE->word = newWord;
							insertNode(newE, lineNumber);
							newE->count = 1;
							newE->left = NULL;
							newE->right = NULL;
							itr->left = newE;
							itr = NULL;
						}

					}
					else if (compare(itr->word, newWord) == 1)
					{
						if (itr->right)
						{
							itr = itr->right;
						}
						else
						{
							Element *newE = new Element;
							newE->word = newWord;
							insertNode(newE, lineNumber);
							newE->count = 1;
							newE->left = NULL;
							newE->right = NULL;
							itr->right = newE;
							itr = NULL;
						}
					}
					else
					{
						itr->count++;
						insertNode(itr, lineNumber);
						itr = NULL;
					}
				}
				if(!root)
				{

					root = new Element;
					root->word = newWord;
					insertNode(root, lineNumber);
					root->count = 1;
					root->left = NULL;
					root->right = NULL;
				}

			}

		}


		lineNumber++;

	}
	inOrderPrint(root);



	return 0;

}
