#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

using namespace std;

class node{
public:


	string state;
	node* parent;
	char direction;
	int levelDepth;

};
#endif