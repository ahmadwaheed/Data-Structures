#include <iostream>

#include "StreetSelecter.h"
using namespace std;
//Heap functions
edge::edge()
{
}
Intersection::Intersection()
{
	coordinates[0] = 0;
	coordinates[0] = 0;
	for (int i = 0; i < 4; i++)
	{
		roads[i] = 0;
	}
	known = 0;
	numEdges = 0;
	exists = false;

}
StreetSelecter::StreetSelecter(Block *blocks, int blockCount, int citySize,
  int numTrips)
{
	numPoints = 0;
	numEdges = 0;
	for (int i = 0; i < blockCount; i++)
	{
		Block c = blocks[i];
		insert(c);
	}


	
	
} // StreetSelecter()

void StreetSelecter::select(Trip *trips, int numTrips, Trip widenedBlocks[100], int &numWidened)
{
	int j = algor(algor(hash(trips[0].startCoordinates)));
	int start = adjList[j].distance;
	int end = 0;
	if (adjList[j].distance > 100)
	{
		start -= (adjList[j].distance - 100) / 2;
		end = (adjList[j].distance - 100)/2;
	}
	//cout << start - end;
	int v1 = j;
	int v2;
	int n = 0;
	for (Vertex v = adjList[j]; v.distance > end; v = adjList[v.pv])
	{
		v2 = v.pv;
		if (v.distance < start)
		{
			widenedBlocks[n].startCoordinates[0] = v1 / 150;
			widenedBlocks[n].startCoordinates[1] = v1 % 150;
			widenedBlocks[n].endCoordinates[0] = v2 / 150;
			widenedBlocks[n].endCoordinates[1] = v2 % 150;
			n++;
		}
		v1 = v2;
	}
	numWidened = n-1;
} // select()
/*void StreetSelecter::heapify()
{
	
	for(int i = 0;i < numEdges ;i++)
	{
		edgeArray[i].timespicked*= edgeArray[i].length;
	}	
	
	for(int k = (numEdges-1)/2;k >=0;k--)
	{
		percDown(k);
	}
	printlength();
}
void StreetSelecter::percDown(int hole)
{
	int left,right;
	int child;
	edge p = edgeArray[hole];
	int z = 0;
	for(; hole * 2 < numEdges && z ==0; hole = child)
	{
		left = hole * 2+1;
		right = hole *2+2;
		child = left;
		if( left != numEdges && edgeArray[left].timespicked < edgeArray[right].timespicked)
			child = right;
		if(edgeArray[child].timespicked > p.timespicked)
			edgeArray[hole] = edgeArray[child];
		else
			z = 1;	
	}
	edgeArray[hole] = p;

}
int StreetSelecter::deleteMax()
{
	edge temp = edgeArray[0];
	edgeArray[0] = edgeArray[numEdges-1];
	edgeArray[numEdges-1] = temp;
	numEdges--;
	//cout << stuff[numEdges-1].timespicked;
	//cout << stuff[numEdges - 1].length;
	percDown(0);
	return numEdges;
}
void StreetSelecter::printlength()
{

	for (int i = 0; i < numEdges; i++)
	{
		cout << edgeArray[i].length << endl;
		cout << edgeArray[i].timespicked << endl;
	}

}*/

int StreetSelecter::hash(short coordinates[2])
{
	return coordinates[0] * 150 + coordinates[1];
}

void StreetSelecter::insert(Block x)
{
	int p1 = hash(x.startCoordinates);
	int p2 = hash(x.endCoordinates);
	int z = x.length;
	if (adjList[p1].count == 0)
	{
		points[numPoints] = p1;
		numPoints++;
		
	}
	if (adjList[p2].count == 0)
	{
		points[numPoints] = p2;
		numPoints++;
	}
	adjList[p2].insert(p1,z);
	adjList[p1].insert(p2,z);
}
Vertex::Vertex()
{
	count = 0;
	distance = 0;
	known = false;
	
}
void Vertex::insert(int edgeIndex,int length)
{
	edges[count] = length;
	adj[count] = edgeIndex;
	count++; 
}

int StreetSelecter::algor(int x)
{
	int start = x;
	for (int i = 0; i < 23000;i++)
	{
		adjList[i].distance = -1;
		adjList[i].known = 0;
		adjList[i].pv = 0;
	}
	//printLength();
	int z;
	Vertex &s = adjList[start];
	//cout << adjList[start].distance << endl;
	s.distance = 0;
	//cout << adjList[start].distance << endl;
	//dijkstraHeap.insert(s);
	int j = 0;
	int result;
	while ( j < numPoints)
	{
		j++;
		result = getMin();
		z = adjList[result].distance;
		Vertex &v = adjList[result];
		v.known = true;
		for (int i = 0; i < v.count; i++){
			Vertex &w = adjList[v.adj[i]];
			
			if (w.distance == -1 || w.distance > v.distance + v.edges[i])
			{
				w.distance = v.distance + v.edges[i];
				w.pv = result;
			}
			int p = 0;
			
		}
	}
	return result;
}


int StreetSelecter::getMin()
{
	
	int minIndex = 0;
	int minDist = 26000;
	for (int i = 0; i < 23000; i++)
	{
		
		if (adjList[i].known == false && adjList[i].distance != -1 && adjList[i].distance < minDist)
		{
			minDist = adjList[i].distance;
			minIndex = i;
		}
	}
	
	return minIndex;
}
void StreetSelecter::printPath(int x)
{
	for (Vertex v = adjList[x]; v.distance != 0; v = adjList[v.pv])
	{
		cout << v.pv << endl;
	}
}
