// EightPuzzle3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include "node.h"
#include "puzzle.h"
using namespace std;




int main()
{
	string initialState = "123405786";// 123456708";
	string finalState = "123456780";
	puzzle p(initialState, finalState);

	p.move(); //implements using breadth first search

	system("pause");
	return 0;
}

