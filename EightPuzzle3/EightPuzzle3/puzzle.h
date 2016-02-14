#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <vector>
#include <string>
#include "node.h"
using namespace std;

class puzzle{

public:
	puzzle(string iState, string gState){
		initialState = iState;
		goalState = gState;
		count = 0;

	}

private:
	string initialState, goalState;
	node* current;
	node* root;
	int count;
};


