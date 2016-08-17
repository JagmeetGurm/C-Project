// Jagmet-CSCI-115-Lab1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

vector<graph*> adj_list; // one dimensional vector; each position in the vector stores a pointer to the head of a linked list


void graph::initialize_graph(int num_of_vertices, int num_of_edges)
{
	graph *g;
	
	int num = num_of_vertices;
	
	for (int i = 0; i < num; i++)
	{
		g = new graph;
		g->head = NULL;
		adj_list.push_back(g);
	
	
	}
	last = NULL;
	cout << endl << endl << endl;

}

void graph::insert_edge(int vertex1, int vertex2)
{
	graph *g, *temp;
	g = new graph;

	g->next = NULL;
	if (adj_list[vertex1]->head == NULL)
	{
		g->prev = NULL;
	//	g = adj_list[vertex2];
		adj_list[vertex1]->head = g;
		adj_list[vertex1]->next = g;
		last = g; //a graph type last pointer declared in graph.h
		adj_list[vertex1]->edge = vertex2;
		cout << vertex1 << "->" << adj_list[vertex1]->edge;
	}
	
	else{
		temp = last;
		temp->next = g;
		g->prev = temp;
		g->next = NULL;
		temp->edge = vertex2;

		last = g;
		
	}
	
	cout << endl << endl << endl;

}

void graph::delete_edge(int vertex1, int vertex2)
{
	graph *g;
	g = adj_list[vertex2];
	if (adj_list[vertex1]->next == g)
	{
		adj_list[vertex1]->next = g->next;
	}
	else
	{
		g->prev = g->next;
	}
	

	cout << endl << endl << endl;

}

void graph::list_all_edges(int num_of_vertices)
{
	
	graph *g;
	for (int i = 0; i < num_of_vertices; i++)
	{
		g = adj_list[i];
		if (g->head == NULL)
			continue;
		else
		{
			while (g->next != NULL)
			{

				cout << i << "->" << g->edge << endl;
				g = g->next;
			}
		}
		cout << endl << endl ;
	}cout << endl << endl << endl;
}

void graph::list_all_neighbors(int vertex1, int num_of_vertices)
{
	graph *g;
	//implement this function  
	g = adj_list[vertex1];
	while (g->next != NULL)
	{
		cout << vertex1 << "->" << g->edge;
		g = g->next;
	}
	cout << endl << endl << endl;
}

void graph::no_incoming_edges(int num_of_vertices)
{
	for (int i = 0; i < num_of_vertices; i++)
	{
		bool a = false;
		graph *g = adj_list[i];
		
			while (g->next != NULL)
			{
				if (g->edge == i)
					a = false;
				else
					a = true;
				g = g->next;
			}
			if (a == true)
				cout << i << endl;
		
		

	}

	//implement this function  

	cout << endl << endl << endl;
}


int main()
{
	int num_of_vertices, num_of_edges, vertex1, vertex2, function;
	graph graph_obj;


	while (1)
	{

		cout << "1 - initialize graph" << endl;
		cout << "2 - insert an edge to the graph" << endl;
		cout << "3 - delete an edge from the graph" << endl;
		cout << "4 - list all edges in the graph" << endl;
		cout << "5 - list all of the neighbors for a particular vertex" << endl;
		cout << "6 - list all of the vertices with no incoming edges" << endl << endl;

		cout << "Choose a function (1 - 6): ";
		cin >> function;
		cout << endl << endl;

		switch (function)
		{
		case 1:
			cout << "Enter the number of vertices in the graph: ";
			cin >> num_of_vertices;
			cout << endl << "Enter the number of edges in the graph: ";
			cin >> num_of_edges;
			cout << endl << endl;
			graph_obj.initialize_graph(num_of_vertices, num_of_edges);
			break;

		case 2:
			cout << "To enter an edge X -> Y (an edge from node X to node Y), use the following format: X Y (the names of the two vertices separated by a single space)" << endl;
			cout << "Enter the edge to insert into the graph: ";
			cin >> vertex1 >> vertex2;
			cout << endl << endl;
			graph_obj.insert_edge(vertex1, vertex2);
			break;

		case 3:
			cout << "To enter an edge X -> Y (an edge from node X to node Y), use the following format: X Y (the names of the two vertices separated by a single space)" << endl;
			cout << "Enter the edge to delete from the graph: ";
			cin >> vertex1 >> vertex2;
			cout << endl << endl;
			graph_obj.delete_edge(vertex1, vertex2);
			break;

		case 4:
			graph_obj.list_all_edges(num_of_vertices);
			break;

		case 5:
			cout << "Enter the vertex to list all of the neighbors for: ";
			cin >> vertex1;
			cout << endl << endl;
			graph_obj.list_all_neighbors(vertex1, num_of_vertices);
			break;

		case 6:
			graph_obj.no_incoming_edges(num_of_vertices);


		} //end switch



	}  //end while

	system("PAUSE");
	return 0;
}


