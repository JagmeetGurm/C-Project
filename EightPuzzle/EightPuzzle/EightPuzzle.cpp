// EightPuzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
David Ruby:
8-Puzzle Code
w/ Strings
*/

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

const int MAXDIM = 3;
const int MAXDIR = 4;
const int MAXSEEN = 4000;

int LocBlank(string &board, int& row, int &col){
	int bpos = board.find("0");
	if (bpos == string::npos){
		return 0;
	}
	else if (bpos > MAXDIM*MAXDIM - 1){
		cout << "ERROR: LocBlank = " << bpos << endl;
		return 0;
	}
	row = bpos / MAXDIM;
	col = bpos % MAXDIM;
	return 1;
}

int Swap(string& board, int row1, int col1, int row2, int col2){
	int temp;
	temp = board.at(row1*MAXDIM + col1);
	board.at(row1*MAXDIM + col1) = board.at(row2*MAXDIM + col2);
	board.at(row2*MAXDIM + col2) = temp;
	return 1;
}

int AddToList(vector <int>& Seen, int value){
	for (int i = 0; i<MAXSEEN; ++i){
		if (Seen.at(i) == 0){
			//      cout << "Adding: "<< i << " = " << value << endl;
			Seen.at(i) = value;
			return 0;
		}
		else if (Seen.at(i) == value){
			return 1;
		}
	}
	return 1;
}

int Move(string& board, int dir){
	int row, col;
	LocBlank(board, row, col);
	if ((dir == 1 || dir == -3) && row > 0){
		Swap(board, row, col, row - 1, col);
	}
	else if ((dir == 2 || dir == -4) && col < MAXDIM - 1){
		Swap(board, row, col, row, col + 1);
	}
	else if ((dir == 3 || dir == -1) && row < MAXDIM - 1){
		Swap(board, row, col, row + 1, col);
	}
	else if ((dir == 4 || dir == -2) && col > 0){
		Swap(board, row, col, row, col - 1);
	}
	else {
		return -1;
	}
	return 0;
}

int ConvertToInt(string &board){
	int row, col;
	int out = 0;
	for (row = 0; row<MAXDIM; ++row){
		for (col = 0; col<MAXDIM; ++col){
			out = out * 10 + board.at(row*MAXDIM + col) - '0';
		}
	}
	cout << out << endl;
	return out;
	
}

int DfsAll(string &board, int current, int previous, vector <int>& Seen, int depth, int cut){
	int dir, res, next;
	//  cout << "DfsAll: " << board <<":" << current <<", " << previous << endl;
	if (AddToList(Seen, current) == 1){
		return 0;
	}
	else if (depth > cut){
		//     cout << "DfsAll cutoff: " << board <<":" << current <<", " << previous << endl;
		return 0;
	}
	for (dir = 1; dir <= MAXDIR; ++dir){
		if (Move(board, dir) == 0){
			next = ConvertToInt(board);
			if (next != previous){
				res = DfsAll(board, next, current, Seen, depth + 1, cut);
			}
			Move(board, -1 * dir);
		}
	}
	return 0;
}

int main(){
	string board = "123456780";
	int i;
	vector <int> Seen(MAXSEEN);
	clock_t start, end;
	double time;

	for (i = 0; i<MAXSEEN; ++i){
		Seen.at(i) = 0;
	}

	start = clock();
//	for (int i = 0; i < 9; i++){
	//	cout << "enter your number: ";
	//	cin >> board;
	//	cout<< endl;
		DfsAll(board, ConvertToInt(board), 0, Seen, 0, 200);

	//}
	cout << "return main" << endl;
	end = clock();

	for (i = 0; i< MAXSEEN; ++i){
		if (Seen.at(i) == 0){
			cout << "Seen = " << i << endl;
			break;
		}
	}
	time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Time required: " << time << endl;
	system("pause");
	return 0;
}
