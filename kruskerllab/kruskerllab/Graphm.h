// Implementation for the adjacency matrix representation
#ifndef GRAPHM_H
#define GRAPHM_H
#include "Graph.h"
class Graphm : public Graph {
	private:
	int numVertex, numEdge; // Store number of vertices, edges
	int **matrix; // Pointer to adjacency matrix
	int *mark; // Pointer to mark array
	int *edge;
public:
	Graphm(int numVertex); // Constructor
	
	~Graphm(); 
	void Init(int n);  // Initialize the graph
		
	int n();  // Number of vertices
	int e(); // Number of edges
		// Return first neighbor of "v"
		int first(int v); 
	// Return v’s next neighbor after w
	int next(int v, int w); 
	


		// Set edge (v1, v2) to "wt"
	void setEdge(int v1, int v2, int wt);
	void delEdge(int v1, int v2); 
	bool isEdge(int i, int j); // Is (i, j) an edge?
		
	int weight(int v1, int v2); 
	int getMark(int v); 
	void setMark(int v, int val); 

	void read_graph(string filename);  // returns NULL if there is any error reading the graph
	bool write_graph(Graph *g, string filename);  // returns true if write is successful, false otherwise


	};
#endif