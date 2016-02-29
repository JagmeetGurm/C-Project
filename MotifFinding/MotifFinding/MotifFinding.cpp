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
							comb.push_back(temp);
						}
					}
				}
			}
		}
	}
}
int comp(string v, string temp){
	int diff = 0;
	for (int i = 0; i < 6; i++){
		if (v[i] != temp[i]){
			diff++;
		}
	}
	return diff;
}
int hummingDistance(string& v, string& seq){
	int min=7;
	for (int i = 0; i < seq.length() - 6; i++){
		string temp = seq.substr(i, 6);
		int t = comp(v, temp);
		if (t< min){
			min=t;

	}
		return min;
}
int totalDistance(string& v, unordered_map<string, string>& dna, vector<string>& labels){
	int sum = 0;
	for (int i = 0; i < 617; i++){
		sum = sum + hummingDistance(v, dna[labels[i]]);
	}
}
void medianSearch(unordered_map<string, string>& dna, vector<string>& labels, int l){
	string bestWord = "AAAAAA";
	int bestDistance = 5000;
	vector<string>combinations;
	generateComb(combinations);
	for (int i = 0; i < 4096; i++){
		string v = combinations[i];
		if (totalDistance(v, dna, labels) < bestDistance){

		}
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

