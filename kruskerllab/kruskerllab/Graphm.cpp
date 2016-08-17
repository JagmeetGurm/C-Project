#include "stdafx.h"
#include "Graphm.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct Edge{
	int v1;
	int v2;
	int weight;
};
Graphm::Graphm(int numVert) // Constructor
{
	Init(numVert);
}
Graphm::~Graphm() { // Destructor
	delete[] mark; // Return dynamically allocated memory
	for (int i = 0; i<numVertex; i++)
		delete[] matrix[i];
	delete[] matrix;
}
void Graphm::Init(int n) { // Initialize the graph
	int i;
	numVertex = n;
	numEdge = 0;
	mark = new int[n]; // Initialize mark array
	for (i = 0; i<numVertex; i++)
		mark[i] = 0; //0 means unvisited
	matrix = (int**) new int*[numVertex]; // Make matrix
	for (i = 0; i<numVertex; i++)
			matrix[i] = new int[numVertex];
	
		edge = new int[e()];
	for (i = 0; i< numVertex; i++) // Initialize to 0 weights
	for (int j = 0; j < numVertex; j++)
	{
		matrix[i][j] = 0;
	//	cout << matrix[i][j] << " ";
	}
}
int Graphm::n() { return numVertex; } // Number of vertices
int Graphm::e() { return numEdge; } // Number of edges
// Return first neighbor of "v"
int Graphm :: first(int v) {
	for (int i = 0; i<numVertex; i++)
	if (matrix[v][i] != 0) return i;
	return numVertex; // Return n if none
}
// Return v’s next neighbor after w
int Graphm::next(int v, int w) {
	for (int i = w + 1; i<numVertex; i++)
	if (matrix[v][i] != 0)
		return i;
	return numVertex; // Return n if none
}



// Set edge (v1, v2) to "wt"
void Graphm::setEdge(int v1, int v2, int wt) {
	//	Assert(wt>0, "Illegal weight value");
	if (matrix[v1][v2] == 0) numEdge++;
	matrix[v1][v2] = wt;
}
void Graphm::delEdge(int v1, int v2) { // Delete edge (v1, v2)
	if (matrix[v1][v2] != 0) numEdge--;
	matrix[v1][v2] = 0;
}
bool Graphm::isEdge(int i, int j) // Is (i, j) an edge?
{
	return matrix[i][j] != 0;
}
int Graphm::weight(int v1, int v2) { return matrix[v1][v2]; }
int Graphm::getMark(int v) { return mark[v]; }
void Graphm::setMark(int v, int val) { mark[v] = val; }
	
//READ FORMAT: The First line contains the number of vertices and number of edges // numvert numedge
//after that each lines contains:
//v1 v2 weight //each line of the file
//so bascially the files after the first line contains lines with each line containing 2 vertices of an edge and the weight of the edge in the format:
//v1 v2 wt
void Graphm:: read_graph(string filename){
	int v1, v2, ed;
	vector<Edge> Edges;
	Edge temp;
	ifstream infile(filename);
	int nofvert=0, nofedges=0;
	 infile >> nofvert >> nofedges;	
	 while (infile >> v1 >> v2 >> ed)
	 {
		 if ((matrix[v1][v2] == matrix[v2][v1]) && v1 > v2)
		 {
			 matrix[v1][v2] = ed;
			 // cout <<v1<<" "<<v2<<" "<<ed << endl;

			 edge[v1*(v1 - 1) / 2 + v2] = ed;

			 temp.v1 = v1;
			 temp.v2 = v2;
			 temp.weight = ed;
			 Edges.push_back(temp);
				 
		 }

	 }
	 infile.close();
	 Graphm *newGraph = new Graphm(Edges.size());
	 for (int i = 0; i < Edges.size(); i++){
		 newGraph->setEdge(Edges[i].v1, Edges[i].v2, Edges[i].weight);
	// return NULL;
}  // returns NULL if there is any error reading the graph



//WRITE FORMAT: v1 v2 weight //each line of the file
//so bascially the files contains lines with each line containing 2 vertices of an edge and the weight of the edge in the format:
//v1 v2 wt
bool Graphm::write_graph(Graph *g, string filename){  //
	ofstream myf(filename);
	int i = 0;
	if (myf.is_open())
	{
		while (true)
		{
			for (i = 0; i < numVertex; i++) // Initialize to 0 weights
			{
				for (int j = 0; j < numVertex; j++)
				{
					if (matrix[i][j] != 0)
					{
						myf << i << " " << j << " " << matrix[i][j] << endl;
					}
				}
			}
			break;
		}
		return true;
	}
	else return false;
}  // returns true if write is successful, false otherwise
