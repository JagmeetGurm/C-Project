// kruskerllab.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include "Graph.h"
#include "Graphm.h"
#include <fstream>
#include "ParPtrTree.h"
#include "heap.cpp"
using namespace std;


int main()
{
	heap<int, int> h(new int[100], 99,100); //Heap implementation(instantiation)

	//Graph tests
	Graph *g=new Graphm(6) ;
//	ifstream infile("mygraph.txt");
/*	g->read_graph("mygraph.txt");
//test passed
	g->write_graph(g, "outgraph.txt");
//test passed
//	cout<<g->n()<<endl;
	cout << "is edge: " <<g->isEdge(3, 1) << endl;

	//ParPtrtree Tests
	ParPtrTree p(6);
	p.UNION(0, 1);
	//this is test of both union and find, the root of 0 should be 1
 cout<<"root of 0 is : "	<<p.give_root(0)<<endl;
 //Yes the root of 0 is 1.

	p.UNION(2, 3);
	p.UNION(1, 3);
	//again test of union and find
cout<<" The root of 1 is : "<<p.give_root(1); //will tell us the root of 1 which should be 3.
//yes the root of 1 is 3.

cout << endl;
*/

	string line;
	while (getline(cin, line))
	{
		if (line == "input n filename")
		{
			g->read_graph("filename");
		int m=	int("n");
			ParPtrTree *p[3];
		}
		else if (line == "output n filename")
		{
			g->write_graph(g,"filename");

		}
		else if (line == "info n")
		{
			cout << "graph in register 2 has 4 vertices " << endl;
		}
		else if (line == "kruskal n m")
		{
			if (1 == 1)
				cout << "connected";
			else cout << "not connected";
		}
		else
		{//
		}
	}
	
	return 0;
}

