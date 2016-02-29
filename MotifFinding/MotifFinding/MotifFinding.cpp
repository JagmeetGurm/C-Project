// MotifFinding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

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
	}
		system("pause");
	return 0;
}

