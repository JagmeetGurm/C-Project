// MotifFinding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

void generateComb(vector<string>& comb){
	char	t[4] = { 'A', 'C', 'G', 'T' };
//	string t = "ACGT";
	string temp;
	for (int a = 0; a < 6; a++){
		for (int b = 0; b < 6; b++){
			for (int c = 0; c < 6; c++){
				for (int d = 0; d < 6; d++){
					for (int e = 0; e < 6; e++){
						for (int f = 0; f < 6; f++){
							 temp =t[a]+ t[b] + t[c] + t[d] + t[e] + t[f];
							comb.push_back(temp);
						}
					}
				}
			}
		}
	}
}
void medianSearch(unordered_map<string, string>& dna, vector<string>& labels, int l){
	string bestWord = "AAAAAA";
	int bestDistance = 5000;
	vector<string>combinations;
	generateComb(combinations);

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

		cout << "label: " << labels[2] << endl;
		cout << "seq: " << dna[labels[2]] << endl;

		medianSearch(dna, labels, 6);
	}
		system("pause");
	return 0;
}

