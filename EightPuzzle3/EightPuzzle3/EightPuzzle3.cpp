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
	string initialState = "123456708"; //123405786";//
//	cout << "enter initial state: ";
//	cin >> initialState;
	//string initialState = "123405786";// 123456708";
	string finalState = "123456780";
	puzzle p(initialState, finalState);
	puzzle p2(initialState, finalState);

	p.move(); //implements using breadth first search
//	p2.move2(); // A * search
	system("pause");
	return 0;
}

