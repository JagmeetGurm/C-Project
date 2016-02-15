#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "node.h"
#include <stdlib.h>     /* abs */
using namespace std;

class puzzle{


	//public functions
public:
	//constructor to set initial and goal state
	puzzle(string iState, string gState){
		initialState = iState;
		goalState = gState;
		//count = 0;
		current = NULL;

	}
	//void move()
	//move function generates all the possible moves
	//a queue is used to perform breadth first search 
	void move(){
		node* nn;
	//	current = NULL;
		nn = new node;
		nn->state = initialState;
		nn->direction = ' ';
		nn->parent = NULL;
		nn->levelDepth = 0;
		root = nn;
		current = nn;
		q.push(nn);
		while (!q.empty()){
			current= q.front();
			q.pop();
			
			if (current->state == goalState){
				cout << "found at level or after moves: " << current->levelDepth<<endl;
				printSequence();
				break;
			}
			
			//left
			 if (current->state[0] != '0' && current->state[3] != '0' && current->state[6] != '0'){
				//string temp = current->state;
				left(current->state);
			}
			 //up
			 if (current->state[0] != '0' && current->state[1] != '0' && current->state[2] != '0'){
				up(current->state);
			}
			 
			 //down
			 if (current->state[6] != '0' && current->state[7] != '0' && current->state[8] != '0'){
				 down(current->state);
			 }
			 //right
			 if (current->state[2] != '0' && current->state[5] != '0' && current->state[8] != '0'){
				 right(current->state);
			 }

		}
	//	printSequence();

	}
	//A* search algorithm
	void move2(){
		node* nn;
		//	current = NULL;
		nn = new node;
		nn->state = initialState;
		nn->direction = ' ';
		nn->parent = NULL;
		nn->levelDepth = 0;
		nn->currentCost = 0;
		nn->totalCost = nn->currentCost + h(initialState, goalState);
		root = nn;
		current = nn;
		q.push(nn);
		while (!q.empty()){
			current = q.front();
		//	q.pop();

			if (current->state == goalState){
				cout << "found at level or after moves: " << current->levelDepth << endl;
				printSequence();
				break;
			}

			//left
			if (current->state[0] != '0' && current->state[3] != '0' && current->state[6] != '0'){
				//string temp = current->state;
				left(current->state);
			}
			//up
			if (current->state[0] != '0' && current->state[1] != '0' && current->state[2] != '0'){
				up(current->state);
			}

			//down
			if (current->state[6] != '0' && current->state[7] != '0' && current->state[8] != '0'){
				down(current->state);
			}
			//right
			if (current->state[2] != '0' && current->state[5] != '0' && current->state[8] != '0'){
				right(current->state);
			}

		}
		//	printSequence();
	}

	//heurisitic function
	int h(string cState, string nState){
		char arr1[3][3], arr2[3][3];
		//converting to array
		int k = 0, cost=0;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				arr1[i][j] = cState[k];
				arr2[i][j] = nState[k];
				k++;
			}
		}
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 3; l++){
						if (arr1[i][j] == arr2[k][l])
							cost = cost + abs(i - k) + abs(j - l);

					}
				}
			}
		}
		return cost;
	}

	//print function to print the sequence in which match is found
	void printSequence(){
		vector<string>seq;
		vector<char>dir;
		while (current != NULL){
			seq.push_back(current->state);
			dir.push_back(current->direction);
			current = current->parent;
		}
		for (int i = seq.size() - 1; i >= 0; i--){
			cout << dir[i] << endl; 
			cout << seq[i] << endl;
			
		}
	}
	//up direction
	void up(string u){
		string temp = u;
		string nextState;
		for (int i = 0; i < u.size(); i++){
			if (u[i] == '0'){

				if (i == 8)
					nextState = u.substr(0, i - 3) + '0' + u.substr(i - 2, 2) + u[i - 3]; // +u.substr(i + 1, (u.size() - 1 - i));
				if (i > 3 ){
					nextState = u.substr(0, i - 3) + '0' + u.substr(i - 2, 2) + u[i - 3] + u.substr(i + 1, (u.size()-1 - i));
				}
				else {
					nextState =  '0' + u.substr(i - 2, 2) + u[i - 3] + u.substr(i + 1, (u.size() -1 - i));
				}
			}
		}
		node* nn;
		nn = new node;
		nn->state = nextState;
		nn->direction = 'U';
		nn->parent = current;
		nn->currentCost = nn->parent->currentCost + h(nn->parent->state, nn->state);
		nn->totalCost = nn->currentCost + h(nn->state, goalState);
		nn->levelDepth = current->levelDepth + 1;
		if (nn->totalCost>nn->parent->totalCost)
		q.push(nn);
		else{
			node* temp = q.front();
			q.pop();
			q.push(nn);
			q.push(temp);
		}
	}
	//donw direction
	void down(string d){
		string temp = d;
		string nextState;
		for (int i = 0; i < d.size(); i++){
			if (d[i] == '0'){
				if (i==0)
					nextState =d[i + 3] + d.substr(i + 1, 2) + '0' + d.substr(i + 4, (d.size() - 1 - i));
				if (i < 5){
					nextState = d.substr(0, i) + d[i + 3] + d.substr(i + 1, 2) + '0' + d.substr(i + 4);//, (d.size() - 1-i-3));
				}
				else{
					nextState = d.substr(0, i ) + d[i + 3] + d.substr(i + 1, 2) + '0' ;
				}
			}
		}
		node* nn;
		nn = new node;
		nn->state = nextState;
		nn->direction = 'D';
		nn->parent = current;
		nn->levelDepth = current->levelDepth + 1;
		//q.push(nn);
		nn->currentCost = nn->parent->currentCost + h(nn->parent->state, nn->state);
		nn->totalCost = nn->currentCost + h(nn->state, goalState);
		nn->levelDepth = current->levelDepth + 1;
		if (nn->totalCost>nn->parent->totalCost)
			q.push(nn);
		else{
			node* temp = q.front();
			q.pop();
			q.push(nn);
			q.push(temp);
		}
	}
	//left direction
	void left(string l){
		string temp = l;
		string nextState;
		for (int i = 0; i < l.size(); i++){
			if (l[i] == '0'){
		/*		if (i == 1){
					nextState = "0"+ l[i+1] + l.substr(i + 1, (l.size() - 1 - i));
				}
				if (i<8)
				nextState = l.substr(0, i -2) + '0' + l[i - 1] + l.substr(i + 1, (l.size() - 1 - i));
				else nextState = l.substr(0, i - 2) + '0' + l[i - 1] ;
				*/
				if (i==1)
					nextState = "0" + l[i + 1] + l.substr(i + 1, (l.size() - 1 - i));
				if (i<8)
				 nextState = l.substr(0, i - 1) + "0" + l[i - 1] + l.substr(i+1, l.size()- 1-i); 
				else nextState = l.substr(0, i - 1) + '0' + l[i - 1];
			}
		}
		node* nn;
		nn = new node;
		nn->state = nextState;
		nn->direction = 'L';
		nn->parent = current;
		nn->levelDepth = current->levelDepth+1;
		//q.push(nn);

		nn->currentCost = nn->parent->currentCost + h(nn->parent->state, nn->state);
		nn->totalCost = nn->currentCost + h(nn->state, goalState);
		nn->levelDepth = current->levelDepth + 1;
		if (nn->totalCost>nn->parent->totalCost)
			q.push(nn);
		else{
			node* temp = q.front();
			q.pop();
			q.push(nn);
			q.push(temp);
		}
	}
	//right direction
	void right(string r){
		string temp = r;
		string nextState;
		for (int i = 0; i < r.size(); i++){
			if (r[i] == '0'){
				if (i==0)
					nextState = r.substr(1, 1) + '0' + r.substr(i + 2, (r.size() - 1 - i));
				if (i < 7)
				{
					nextState = r.substr(0, i) + r[i + 1] + '0' + r.substr(i + 2, (r.size() - 1 - i));
				}
				else{
					nextState = r.substr(0, i ) + r[i + 1] + '0'; // +r.substr(i + 2, (r.size() - 1 - i));
				}
			}
		}
		node* nn;
		nn = new node;
	//	nextState = "123456780";
		nn->state = nextState;
		nn->direction = 'R';
		nn->parent = current;
		nn->levelDepth = current->levelDepth + 1;
		//q.push(nn);
		nn->currentCost = nn->parent->currentCost + h(nn->parent->state, nn->state);
		nn->totalCost = nn->currentCost + h(nn->state, goalState);
		nn->levelDepth = current->levelDepth + 1;
		if (nn->totalCost>nn->parent->totalCost)
			q.push(nn);
		else{
			node* temp = q.front();
			q.pop();
			q.push(nn);
			q.push(temp);
		}
	}
private:
	//private members
	string initialState, goalState;
	node* current;
	node* root;
	int count;

	queue<node*>q;
};
#endif


