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
		unordered_map<string, string>nucl;
	//	unordered_map<string, string>dna;
		while (!inputFile2.eof())
		{

			getline(inputFile2, line);
			lines.push_back(line);

		}

		for (int i = 14; i < 100; i++){
			if (lines[i].substr(0, 6)  == "Query="){
			key = lines[i];
					cout << key << endl;
					cout << endl;
					cout << endl;
			}
			else{
				string seq = "";
				while (lines[i].substr(0, 6) != "Query="){
					seq = seq + lines[i];
					if (lines[i].substr(0, 7) == "Length"){
						string:: size_type sz;

						int queryLength = stoi(lines[i].substr(7), &sz);
					}
					if (lines[i].substr(1, 12) == "Identities ="){
						int j = 0; string temp = ""; string::size_type sz2;
						while (lines[i][j] != '/'){
							temp += lines[i][j];
							j++;
						}
						
							int alignLength = stoi(temp, &sz2);
							if ((90 / 100) <= alignLength)
					}
					i++;
				}
					cout << seq<<endl;
					nucl[key] = seq;
				i--;
		//		dna[ex] = seq;

			
			}

		}



	//	medianSearch(dna, labels, 6);
	}
	system("pause");
	return 0;
}

