// EightPuzzle3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;


class puzzle{
public:

	void move(string iState, string gState){
		state[iState] = '0';
	//	p(iState, "0");
		q.push(state);
		goalState = gState;
		while (!q.empty()){

			if (q.pop(). == goalState){

			}
		}







	}
private:

	queue<map<string, string>>q;
	map<string, string>state;
	map<string, string>direction;
	map<string, int>depthLevel;
	string goalState;
	pair<string, string>p;

};

int main()
{
	string initialState = "123456708";
	string finalState = "123456780";
	puzzle p;
	
	p.move(initialState, finalState);



	return 0;
}

