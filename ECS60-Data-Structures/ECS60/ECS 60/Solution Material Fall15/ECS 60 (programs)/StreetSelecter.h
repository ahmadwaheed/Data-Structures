
#ifndef StreetSelecterH
#define StreetSelecterH
#include "RunCity.h"
class edge
{
public:
	edge();
	int length;
	int timespicked;
	bool known;

	Trip trip;
};
class Intersection
{
	
public:
	bool exists;
	int coordinates[2];
	int roads[4];
	int numEdges;
	int distance;
	int *dijkstratable;
	int heapLocation;
	Intersection();
	bool known;
};
class Vertex
{
public:
	short coordinates[2];
	Vertex();
	void insert(int edgeIndex,int length);
	int count;
	int adj[4];
	int edges[4];
	int pv;
	int distance;
	bool known;

};
class StreetSelecter
{	
public:
	int points[23000];
	int numPoints;
	edge edgeArray[30000];
	int hash(short coordinates[2]);
	void insert(Block x);
	int numEdges;
	int getMin();
	Vertex adjList[23000];
	int algor(int x);
	void printPath(int x);
  StreetSelecter(Block *blocks, int blockCount, int citySize, int numTrips);
  void select(Trip *trips, int numTrips, Trip widenedBlocks[100], int &numWidened); 
    // fills widenedBlocks and sets numWidened to the number of entries
}; // StreetSelecter class
#endif

