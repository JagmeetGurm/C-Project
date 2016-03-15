// unionDatabase.cpp : Defines the entry point for the console application.
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
	inputFile2.open("metaHIT-nr-HMP.fa", ios::in);

	if (!inputFile2){ //if not able to open file 
		cout << "cannot open file";

	}
	else{
		//int i = 0;
		string seq = "";
		string line;
		string key;
		vector<string>lines;
		vector<string>labels;
	//	unordered_map<string, string>dna;
		while (!inputFile2.eof())
		{

			getline(inputFile2, line);
			lines.push_back(line);

		}

		for (int i = 0; i < 20; i++){
			if (lines[i].substr(0, 7)  == "Length="){
			key = lines[i];
					cout << key << endl;
			}
			else{
				string seq = "";
				while (i < 20 && lines[i].substr(0, 7) != "Length="){
					seq = seq + lines[i];
					i++;
				}
					cout << seq<<endl;
				i--;
		//		dna[ex] = seq;

			
			}

		}



	//	medianSearch(dna, labels, 6);
	}
	system("pause");
	return 0;
}

