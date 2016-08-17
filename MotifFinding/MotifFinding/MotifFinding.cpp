// MotifFinding.cpp : Defines the entry point for the console application.
//
/*
This program is done by Jagmeet S.Gurm as fullfillment of assignment of
CSCI 291T Bioinformatics.
The program reads a fasta file and then finds the best 5 motifs by first finding the median strings 
and then finally the motifs.It is written in C++ language and can be run in MS Visual Studio
by compiling(F7) and then executing(F5).
The program takes a fasta file as an input then extracts the pair of label and sequence and saves 
them in unordered map <string, string>dna.The labels of the dna sequences are stored in a vector called labels.

The output is the best 5 median strings with their total distance, the consensus string with the 
consensus score and the position of the motifs in the sequence.

For this the median search string algorithm is used in which each possible comparison for a 6-mer is 
compared to each sequence for strings of length 6 and the one which has minimum total distance is selected 
as a median string. The total distance function makes use of the hamming function which compares two strings 
and uses the compare function which checks the difference between the two strings.  The 5 strings which have 
the least total distance are selected and printed.

*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

/*

generateComb simply generates all the possible combinations for the 6-lmer. 
It receives a vector and populates it with all the combinations possible. */
void generateComb(vector<string>& comb){
//	char	t[4] = { 'A', 'C', 'G', 'T' };
	string t = "ACGT";
	
	for (int a = 0; a < 4; a++){
		for (int b = 0; b < 4; b++){
			for (int c = 0; c < 4; c++){
				for (int d = 0; d < 4; d++){
					for (int e = 0; e < 4; e++){
						for (int f = 0; f < 4; f++){
							string temp = "";
							 temp =temp+t[a]+ t[b] + t[c] + t[d] + t[e] + t[f];
						//	 cout << temp << endl;
							 std::string::size_type sz;
							 int tem = std::stoi(temp, &sz);
							comb.push_back(temp);
						}
					}
				}
			}
		}
	}
}

/*

Comp function takes 2 strings- the string from enumeration and the current
string from the sequence which is being compared. The value returned is the no of chars that are not same. */
int comp(string v, string temp){
	int diff = 0;
	for (int i = 0; i < 6; i++){
		if (v[i] != temp[i]){
			diff++;
		}
	}
	return diff;
}
/*

Humming Distance takes two inputs- the string from the enumeration and the 
sequence currently being compared. The string which matches the most from the sequence,
its distance that is the numbers of chars that do not match is returned to the TotalDistance function. */
int hummingDistance(string& v, string& seq){
	int min=7;
	for (int i = 0; i < seq.length() - 6; i++){
		string temp = seq.substr(i, 6);
		int t = comp(v, temp);
		if (t < min){
			min = t;

		}
	}
		return min;
}

/*

TotalDistance takes 3 inputs- string from the enumeration, the unordered map of labels and sequences, and the vector of labels. 
It returns the least distance for the string from that sequence. */
int totalDistance(string& v, unordered_map<string, string>& dna, vector<string>& labels){
	int sum = 0;
	for (int i = 0; i < 617; i++){
		sum = sum + hummingDistance(v, dna[labels[i]]);
	}

	return sum;
}

/*

The median Search is  function that compares all possible string combinations 
from AA..A to TT..T with the 6-mer strings of the 617 sequences and the one with the lowest
total distance are kept in the vector. It takes dna which is unordered map of labels and sequences,
a vector of labels and the length of l-mer. The output is  the five median/motif strings.



*/
void medianSearch(unordered_map<string, string>& dna, vector<string>& labels, int l){
	string bestWord = "AAAAAA";
	int bestDistance = 5000;
	vector<string>combinations;
	vector<string>bestW;
	vector<int>bestD;
	generateComb(combinations);
//	int v = combinations[0];
	int i = 1;
	while (i > 0){
		if (i < l){
			string prefix;
			int t;
			if (i < 10){
				t = i / 100000;
			}
			if (i < 100){
				t = i / 10000;
			}
			if (i < 1000){
				t = i / 1000;
			}
			if (i < 10000){
				t = i / 100;
			}
			if (i < 100000){
				t = i / 10;
			}
			if (i < 1000000){
				t = i / 1;
			}


				string t2 = std::to_string(t);
				for (int j = 0; j < t2.length(); j++){
					if (t2[j] == '1'){
						t2[j] = 'A';

					}
					if (t2[j] == '2'){
						t2[j] = 'C';

					}
					if (t2[j] == '3'){
						t2[j] = 'G';

					}
					if (t2[j] == '4'){
						t2[j] = 'T';

					}
				}

				prefix = t2;
				int dist = totalDistance(prefix, dna, labels);
				


			
		}
	}
	for (int i = 400; i < 2800; i++){
		string v = combinations[i];
		int dist = totalDistance(v, dna, labels);
		if ( dist< bestDistance){
			bestDistance = dist;
			bestWord = v;
			bestW.push_back(bestWord);
			bestD.push_back(bestDistance);

		}
	}
	for (int i = bestW.size()-1; i >bestW.size()-6; i--){
		cout <<"median string: "<< bestW[i] <<" (tot_dist= "<<bestD[i]<< endl;
	}


}
int main()
{

	ifstream inputFile2;
	//vector<string> v;
	//reading a exon file line by line
	inputFile2.open("HMP-617.fa", ios::in);

	if (!inputFile2){ //if not able to open file 
		cout << "cannot open file";

	}
	else{
		//int i = 0;
		string seq = "";
		string line;
		string ex;
		vector<string>lines;
		vector<string>labels;
		unordered_map<string, string>dna;
		while (!inputFile2.eof())
		{

			getline(inputFile2, line);
			lines.push_back(line);

		}

		for (int i = 0; i < lines.size(); i++){
			if (lines[i][0] == '>'){
				ex = lines[i];
				//	cout << ex << endl;
			}
			else{
				string seq = "";
				while (i < lines.size() && lines[i][0] != '>'){
					seq = seq + lines[i];
					i++;
				}
				//	cout << seq<<endl;
				i--;
				dna[ex] = seq;

				labels.push_back(ex);
			}

		}

		

		medianSearch(dna, labels, 6);
	}
		system("pause");
	return 0;
}

