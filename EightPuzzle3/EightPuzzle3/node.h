#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

using namespace std;

class node{
public:


	string state;
	node* parent;
	string direction;
	int levelDepth;

};
#endif