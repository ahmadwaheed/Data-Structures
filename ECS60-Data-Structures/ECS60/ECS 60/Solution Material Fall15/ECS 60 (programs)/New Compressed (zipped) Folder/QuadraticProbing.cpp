#include "QuadraticProbing.h"
//method for printing
/*
void QuadraticHashTable ::print()
{
cout << array[267775].element;
}*/

/**
* Internal method to test if a positive number is prime.
* Not an efficient algorithm.
*/

bool QuadraticHashTable::isPrime(int n) const
{
	if (n == 2 || n == 3)
		return true;

	if (n == 1 || n % 2 == 0)
		return false;

	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;

	return true;
}

/**
* Internal method to return a prime number at least as large as n.
* Assumes n > 0.
*/

int QuadraticHashTable::nextPrime(int n) const
{
	if (n % 2 == 0)
		n++;

	for (; !isPrime(n); n += 2)
		;

	return n;
}

/**
* Construct the hash table.
*/

QuadraticHashTable::QuadraticHashTable(char * notFound, int size)

{
	for (int i = 0; i < size; i++)
	{
		array[i] = NULL;
	}
}

/**
* Insert item x into the hash table. If the item is
* already present, then do nothing.
*/

void QuadraticHashTable::insert(char * x)
{
	// Insert x as active
	int currentPos = findPos(x);
	//if (isActive(currentPos))
	//return;
	//array[currentPos] = HashEntry(x, ACTIVE);
	array[currentPos] = x;
	// Rehash; see Section 5.5
	/*if (++currentSize > array.size() / 2)
	{
	rehash();
	cout << array.size();
	}*/


}

/**
* Method that performs quadratic probing resolution.
* Return the position where the search for x terminates.
*/

int QuadraticHashTable::findPos(char * x) const
{
	/* 1*/      int collisionNum = 0;
	/* 2*/      int currentPos = hash(x, 300997);

	/* 3*/      while (array[currentPos] &&
		strcmp(x, array[currentPos]))
	{
		//cout << x << endl;
		//cout << array[currentPos].element << endl;
		/* 4*/          currentPos += 2 * ++collisionNum - 1;  // Compute ith probe
		/* 5*/          if (currentPos >= 300997)
			/* 6*/              currentPos -= 300997;
	}

	/* 7*/      return currentPos;
}


/**
* Remove item x from the hash table.
*/
/*
void QuadraticHashTable ::remove(const HashedObj & x)
{
int currentPos = findPos(x);
if (isActive(currentPos))
array[currentPos].info = DELETED;
}*/

/**
* Find item x in the hash table.
* Return the matching item, or ITEM_NOT_FOUND, if not found.
*/

bool QuadraticHashTable::find(char * x) const
{
	int currentPos = findPos(x);
	return isActive(currentPos);
}
/**
* Make the hash table logically empty.
*/
/*
void QuadraticHashTable ::makeEmpty()
{
currentSize = 0;
for (int i = 0; i < array.size(); i++)
array[i] = NULL;
}*/


/**
* Return true if currentPos exists and is active.
*/

bool QuadraticHashTable::isActive(int currentPos) const
{
	return array[currentPos] != NULL;
}

/**
* A hash routine for string objects.
*/

int QuadraticHashTable::hash(const char * key, int tableSize) const
{
	int hashVal = 0;

	for (int i = 0; key[i]; i++)
	{
		hashVal = 37 * hashVal + key[i];
		hashVal %= tableSize;

	}
	return hashVal;
}


/**
* A hash routine for ints.
*/

int QuadraticHashTable::hash(int key, int tableSize) const
{
	return key % tableSize;
}
