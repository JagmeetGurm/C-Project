// EightPuzzle3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include "puzzle.h"
using namespace std;




int main()
{
	string initialState = "123456708";
	string finalState = "123456780";
	puzzle p(initialState, finalState);

	p.move();


	return 0;
}

