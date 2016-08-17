#include "stdafx.h"
#include "ParPtrTree.h"

ParPtrTree::ParPtrTree(int size){
	array = new int[size];// Create node array
	weights = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = -1;  // Each node is its own root to start // Constructor
		weights[i] = 1;//each node is a tree at beginning with weight =1
	}
}
ParPtrTree::	~ParPtrTree() { 
	delete[] array; 
	delete[] weights;
} // Destructor
void ParPtrTree::UNION(int a, int b){

	int root1 = FIND(a);     // Find root of node a
	int root2 = FIND(b);     // Find root of node b
	if (differ(root1, root2))          // Merge with weighted union 
	if (weights[root2] >= weights[root1]) { //if two trees have same weight then smaller index is merged to larger index
		array[root1] = root2;
		weights[root2] += weights[root1];
	}
	else {
		array[root2] = root1;
		weights[root1] += weights[root2];
	}
} // Merge equivalences
bool ParPtrTree::differ(int root1, int root2){ return (root1!=root2) ; } // True if not in same tree

int ParPtrTree::FIND(int curr) const { // Find root
	if (array[curr] == -1) return curr; // At root
    array[curr] = FIND(array[curr]);
    return array[curr];
}
int ParPtrTree::give_root(int i)
{
	return(FIND(i));
}