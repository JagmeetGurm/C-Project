#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "node.h"
using namespace std;

class puzzle{

public:
	puzzle(string iState, string gState){
		initialState = iState;
		goalState = gState;
		//count = 0;


	}
	//void move()
	void move(){
		node* nn;
		nn = new node;
		nn->state = initialState;
		nn->parent = NULL;
		nn->levelDepth = 0;
		root = nn;
		q.push(nn);
		while (!q.empty()){
			current = q.pop();
			
			if (current->state == goalState){
				cout << "found at level or after moves: " << current->levelDepth<<endl;
				printSequence();
			}
			//left
			else if (current->state.(0) != '0' && current->state.(3) != '0' && current->state.(6) != '0'){
				string temp = current->state;
				current-
			}
		}

	}
	void printSequence(){
		vector<string>seq;
		vector<string>dir;
		while (current != NULL){
			seq.push_back(current->state);
			dir.push_back(current->direction);
			current = current->parent;
		}
		for (int i = seq.size() - 1; i >= 0; i++){
			cout << seq[i]<<endl;
			cout << dir[i] << endl;
		}
	}

private:
	string initialState, goalState;
	node* current;
	node* root;
	int count;

	queue<puzzle>q;
};


