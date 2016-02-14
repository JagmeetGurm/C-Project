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
		current = NULL;

	}
	//void move()
	void move(){
		node* nn;
	//	current = NULL;
		nn = new node;
		nn->state = initialState;
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
			//right
			if (current->state[2] != '0' && current->state[5] != '0' && current->state[8] != '0'){
				right(current->state);
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

		}
		printSequence();

	}

	void printSequence(){
		vector<string>seq;
		vector<char>dir;
		while (current != NULL){
			seq.push_back(current->state);
			dir.push_back(current->direction);
			current = current->parent;
		}
		for (int i = seq.size() - 1; i >= 0; i--){
			cout << seq[i]<<endl;
			cout << dir[i] << endl;
		}
	}
	void up(string u){
		string temp = u;
		string nextState;
		for (int i = 0; i < u.size(); i++){
			if (u[i] == '0'){
				if (i > 4){
					nextState = u.substr(0, i - 4) + '0' + u.substr(i - 2, 2) + u[i - 3] + u.substr(i + 1, (u.size() - 1 - i));
				}
				else {
					nextState =  '0' + u.substr(i - 2, 2) + u[i - 3] + u.substr(i + 1, (u.size() - 1 - i));
				}
			}
		}
		node* nn;
		nn = new node;
		nn->state = nextState;
		nn->direction = 'U';
		nn->parent = current;
		nn->levelDepth = current->levelDepth + 1;
		q.push(nn);
	}

	void down(string d){
		string temp = d;
		string nextState;
		for (int i = 0; i < d.size(); i++){
			if (d[i] == '0'){
				if (i < 5){
					nextState = d.substr(0, i - 1) + d[i + 3] + d.substr(i + 1, 2) + '0' + d.substr(i + 4, (d.size() - 1-i));
				}
				else{
					nextState = d.substr(0, i - 1) + d[i + 3] + d.substr(i + 1, 2) + '0' ;
				}
			}
		}
		node* nn;
		nn = new node;
		nn->state = nextState;
		nn->direction = 'D';
		nn->parent = current;
		nn->levelDepth = current->levelDepth + 1;
		q.push(nn);
	}
	void left(string l){
		string temp = l;
		string nextState;
		for (int i = 0; i < l.size(); i++){
			if (l[i] == '0'){
				if (i<8)
				nextState = l.substr(0, i -1) + '0' + l[i - 1] + l.substr(i + 1, (l.size() - 1 - i));
				else nextState = l.substr(0, i - 1) + '0' + l[i - 1] ;
			}
		}
		node* nn;
		nn = new node;
		nn->state = nextState;
		nn->direction = 'L';
		nn->parent = current;
		nn->levelDepth = current->levelDepth+1;
		q.push(nn);
	}
	
	void right(string r){
		string temp = r;
		string nextState;
		for (int i = 0; i < r.size(); i++){
			if (r[i] == '0'){
				if (i < 7)
				{
					nextState = r.substr(0, i - 1) + r[i + 1] + '0' + r.substr(i + 2, (r.size() - 1 - i));
				}
				else{
					nextState = r.substr(0, i - 1) + r[i + 1] + '0'; // +r.substr(i + 2, (r.size() - 1 - i));
				}
			}
		}
		node* nn;
		nn = new node;
		nextState = "123456780";
		nn->state = nextState;
		nn->direction = 'R';
		nn->parent = current;
		nn->levelDepth = current->levelDepth + 1;
		q.push(nn);
	}
private:
	string initialState, goalState;
	node* current;
	node* root;
	int count;

	queue<node*>q;
};
#endif


