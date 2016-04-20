/*This program is done by Jagmeet S. Gurm as a part of CSCI 291T-Bioinformatics assignment.
The program reads a query file and a DataBase file and implements the Smith-Waterman
algorithm with Affine gap Scoring and trace back operation. 
The program is created in C++ language and can be run in MS Visual Studio environment
by first compiling(F7) and then running(F5).

The program reads a query file and then a Database sequence file and stores all sequences
in a vector called DBSeqs. Then it calls the Smith-Waterman function on each dB sequence
with query sequence. The function returns a score which is stored in a int vector 
and from it a max score is chosen and then traced back till a 0 is encountered.
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define GAP_OPEN 11  //Gap open and extend penalties for blastp
#define GAP_EXTEND 1

using namespace std;

//function to initialize values. It accepts length of seq, no gap array and a 
//integer to intialize value.
void init_vect(int lena, int* nogap, int gap){
	for (int i = 0; i < lena; i++){
		nogap[i] = gap;
	}

}

//The function receives a seq from DB, a seq from query and a 
//score matrix. After populating the matrix it calculates the score 
// only two rows. And finally the highest score is returned.
int sw(string seqA, string seqB, int matrix[25][25]){
	int lenA = seqA.size();
	int* noGap = new int[lenA];
	int* bGap = new int[lenA];
	int gapOpen = GAP_OPEN;
	int gapExt = GAP_EXTEND, i, j;
	int lastNoGap, prevNoGap;
	int score = 0;
	init_vect(lenA, noGap, 0);
	init_vect(lenA, bGap, -gapOpen);
	int lenB = seqB.size();
	for (i = 0; i < lenB; ++i){
		int aGap;
		lastNoGap = prevNoGap = 0;
		aGap = -gapOpen;
		for (j = 0; j < lenA; j++){
			aGap = max((lastNoGap - gapOpen - gapExt), (aGap - gapExt));
			bGap[j] = max((noGap[j] - gapOpen - gapExt), (bGap[j] - gapExt));
			lastNoGap = max((prevNoGap + matrix[seqA[j]][seqB[i]]), 0);
			lastNoGap = max(lastNoGap, aGap);
			lastNoGap = max(lastNoGap, bGap[j]);
			prevNoGap = noGap[j];
			noGap[j] = lastNoGap;
			score = max(score, lastNoGap);
		}
	}
	return score;
}
int main()
{
	ifstream queryFile, dbFile;
	vector <string >DBSeqs ;
	string line, line2;
vector<int> score;
	//Reading the query file
	queryFile.open("EColi-query1.fa", ios::in);

	if (!queryFile)
		cout << "Cannot open file"<<endl;
	else{
		while (!queryFile.eof()){
			getline(queryFile, line);
			//cout << line << endl;
		}
	}
	//opening db file and reading it in a vector 
	dbFile.open("swissprot-100.fa", ios::in);
	if (!dbFile){
		cout << "cannot open file"<<endl;
	}
	else{
		while (!dbFile.eof()){
			getline(dbFile, line2);
			DBSeqs.push_back(line2);
		}
	}

	 int ScoreMatrix[25][25] = {
		{ 4, -1, -2, -2, 0, -1, -1, 0, -2, -1, -1, -1, -1, -2, -1, 1, 0, -3, -2, 0, -2, -1, -1, -1, -4 },
		{ -1, 5, 0, -2, -3, 1, 0, -2, 0, -3, -2, 2, -1, -3, -2, -1, -1, -3, -2, -3, -1, -2, 0, -1, -4 },
		{ -2, 0, 6, 1, -3, 0, 0, 0, 1, -3, -3, 0, -2, -3, -2, 1, 0, -4, -2, -3, 4, -3, 0, -1, -4 },
		{ -2, -2, 1, 6, -3, 0, 2, -1, -1, -3, -4, -1, -3, -3, -1, 0, -1, -4, -3, -3, 4, -3, 1, -1, -4 },
		{ 0, -3, -3, -3, 9, -3, -4, -3, -3, -1, -1, -3, -1, -2, -3, -1, -1, -2, -2, -1, -3, -1, -3, -1, -4 },
		{ -1, 1, 0, 0, -3, 5, 2, -2, 0, -3, -2, 1, 0, -3, -1, 0, -1, -2, -1, -2, 0, -2, 4, -1, -4 },
		{ -1, 0, 0, 2, -4, 2, 5, -2, 0, -3, -3, 1, -2, -3, -1, 0, -1, -3, -2, -2, 1, -3, 4, -1, -4 },
		{ 0, -2, 0, -1, -3, -2, -2, 6, -2, -4, -4, -2, -3, -3, -2, 0, -2, -2, -3, -3, -1, -4, -2, -1, -4 },
		{ -2, 0, 1, -1, -3, 0, 0, -2, 8, -3, -3, -1, -2, -1, -2, -1, -2, -2, 2, -3, 0, -3, 0, -1, -4 },
		{ -1, -3, -3, -3, -1, -3, -3, -4, -3, 4, 2, -3, 1, 0, -3, -2, -1, -3, -1, 3, -3, 3, -3, -1, -4 },
		{ -1, -2, -3, -4, -1, -2, -3, -4, -3, 2, 4, -2, 2, 0, -3, -2, -1, -2, -1, 1, -4, 3, -3, -1, -4 },
		{ -1, 2, 0, -1, -3, 1, 1, -2, -1, -3, -2, 5, -1, -3, -1, 0, -1, -3, -2, -2, 0, -3, 1, -1, -4 },
		{ -1, -1, -2, -3, -1, 0, -2, -3, -2, 1, 2, -1, 5, 0, -2, -1, -1, -1, -1, 1, -3, 2, -1, -1, -4 },
		{ -2, -3, -3, -3, -2, -3, -3, -3, -1, 0, 0, -3, 0, 6, -4, -2, -2, 1, 3, -1, -3, 0, -3, -1, -4 },
		{ -1, -2, -2, -1, -3, -1, -1, -2, -2, -3, -3, -1, -2, -4, 7, -1, -1, -4, -3, -2, -2, -3, -1, -1, -4 },
		{ 1, -1, 1, 0, -1, 0, 0, 0, -1, -2, -2, 0, -1, -2, -1, 4, 1, -3, -2, -2, 0, -2, 0, -1, -4 },
		{ 0, -1, 0, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -2, -1, 1, 5, -2, -2, 0, -1, -1, -1, -1, -4 },
		{ -3, -3, -4, -4, -2, -2, -3, -2, -2, -3, -2, -3, -1, 1, -4, -3, -2, 11, 2, -3, -4, -2, -2, -1, -4 },
		{ -2, -2, -2, -3, -2, -1, -2, -3, 2, -1, -1, -2, -1, 3, -3, -2, -2, 2, 7, -1, -3, -1, -2, -1, -4 },
		{ 0, -3, -3, -3, -1, -2, -2, -3, -3, 3, 1, -2, 1, -1, -2, -2, 0, -3, -1, 4, -3, 2, -2, -1, -4 },
		{ -2, -1, 4, 4, -3, 0, 1, -1, 0, -3, -4, 0, -3, -3, -2, 0, -1, -4, -3, -3, 4, -3, 0, -1, -4 },
		{ -1, -2, -3, -3, -1, -2, -3, -4, -3, 3, 3, -3, 2, 0, -3, -2, -1, -2, -1, 2, -3, 3, -3, -1, -4 },
		{ -1, 0, 0, 1, -3, 4, 4, -2, 0, -3, -3, 1, -1, -3, -1, 0, -1, -2, -2, -2, 0, -3, 4, -1, -4 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -4 },
		{ -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, 1 }
	};

	 string seq = "";
	
	 string ex;
	// vector<string>lines;
	 vector<string>labels;
	 unordered_map<string, string>dna;
	 for (int i = 0; i < DBSeqs.size(); i++){
		 if (DBSeqs[i][0] == '>'){
			 ex = DBSeqs[i];
			 //	cout << ex << endl;
		 }
		 else{
			 //storing label and seq in unordered map
			 string seq = "";
			 while (i < DBSeqs.size() && DBSeqs[i][0] != '>'){
				 seq = seq + DBSeqs[i];
				 i++;
			 }
			 //	cout << seq<<endl;
			 i--;
			 dna[ex] = seq;

			 labels.push_back(ex);
		 }

	 }
	 //
	 for (auto it = dna.begin(); it != dna.end(); ++it)
	 {
		 //calling the smith-waterman function
		 score.push_back( sw(line, it->second, ScoreMatrix));
	 }	
	 system("pause");
	return 0;
}

