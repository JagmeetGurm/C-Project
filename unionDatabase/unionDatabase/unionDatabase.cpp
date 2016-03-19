// unionDatabase.cpp : Defines the entry point for the console application.
//
/*
This project is done by Jagmeet Singh Gurm as part of the CSCI 291 Bioinformatics assignment assigned by Dr. Park.
The program takes as input two databases and makes a database which is union of these two databases. The program is written in c++ language and can be run in MS Visual Studio by compiling(F7) and then executing(F5).

First, the MetaHIT.fa database is aligned against HMP.fa using NCBI BLASTn, and the output is MetaHIT-nr-HMP.fa file using the threshold value: BLASTn Evalue = 10^-5 and Alignment identity >= 95%.
Similarly, the HMP.fa is aligned against MetaHIT-nr-HMP.fa using NCBI BLASTn, and the output is HMP-nr-(MetaHIT-nr-HMP).fa file using the same threshold.
Finally, in this program 90% ≤ alignment_length/query_length ≤ 110%, threshold is used.

In the main function, first the MetaHIT-nr-HMP.fa file is read and the threshold value 90% ≤ alignment_length/query_length ≤ 110%,  is applied. The query name list is made of those queries which meet this threshold. Then the queries are erased from the main database which corresponds to the the queries in the list.
Similarly, the second HMP-nr-(MetaHIT-nr-HMP).fa file is read and same action is performed on it.

*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;



//function to union the two files, it receives two files as arguments as  unordered maps
//then writing the output to the output file. 
void unionFunc(unordered_map<string, string>&file1, unordered_map<string, string>&file2){
	for (auto& x : file2){
		file1[x.first] = x.second;
	}

	ofstream myfile;
	myfile.open("unionFile.fa", ios::out);
	for (auto & x : file2){
		myfile << x.first << x.second;
	}
	myfile.close();
}


//function to remove the found redundant query list from the original database
//the function receives tow inputs: the file and the list of query names to be removed
void reduceFile(unordered_map<string, string>& comb, vector<string>& label){
	for (auto& x : comb){
		for (int i = 0; i < label.size(); i++){
			if (x.first == label[i]){
				comb.erase(label[i]);
			}
		}
	}

}

//this function reads the second file and returns the reduced file with
//redundants removed. 
unordered_map<string,string> readSecondFile(){
	ifstream inputFile2;
	
	inputFile2.open("	HMP-nr-(MetaHIT-nr-HMP).fa", ios::in);

	vector<string>labels;
	vector<string>lines;
	unordered_map<string, string>nucl;

	if (!inputFile2){ //if not able to open file 
		cout << "cannot open file";

	}
	else{
		//int i = 0;
		string seq = "";
		string line;
		string key;
		
		//	unordered_map<string, string>dna;
		while (!inputFile2.eof())
		{

			getline(inputFile2, line);
			lines.push_back(line);

		}

		for (int i = 14; i <lines.size(); i++){
			//bool check = true;
			if (lines[i].substr(0, 6) == "Query="){
				key = lines[i];
				//	cout << key << endl;
				//cout << endl;
				//cout << endl;
			}
			else{
				string seq = "";
				while (lines[i].substr(0, 6) != "Query="){
					seq = seq + lines[i]; int queryLength = 1;
					if (lines[i].substr(0, 7) == "Length=" && lines[i - 2].substr(0, 6) == "Query="){
						string::size_type sz;

						queryLength = stoi(lines[i].substr(7), &sz);
						// cout << "queryLength: " << queryLength << endl << endl;
					}

					if ((lines[i].find("Identities =")) != string::npos){
						int j = 14; string temp = ""; string::size_type sz2;
						while (lines[i][j] != '/'){
							temp += lines[i][j];
							j++;
						}

						int alignLength = stoi(temp, &sz2);
						//		cout << alignLength + 10000<<endl<<endl;
						if ((90 / 100) <= alignLength / queryLength <= 110 / 100){
							if (labels.size() > 0){
								if (labels[labels.size() - 1] != key){
									labels.push_back(key);
								}
							}
							else{
								labels.push_back(key);
							}
							//	check = false;
							//	cout << "key: " << labels[0]<<endl<<endl;
						}
					}
					i++;
				}
				//cout << seq<<endl;
				nucl[key] = seq;
				i--;
				//		dna[ex] = seq;


			}


		}

	//	cout << "size: " << labels.size() << endl;

		//	medianSearch(dna, labels, 6);
	}
	return nucl;
}


int main()
{
	vector<string>labels;
	vector<string>lines;
	unordered_map<string, string>nucl;
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
		
	//	unordered_map<string, string>dna;
		while (!inputFile2.eof())
		{

			getline(inputFile2, line);
			lines.push_back(line);

		}

		cout << "line size: " << lines.size() << endl;
		for (int i = 14; i <lines.size(); i++){
			//bool check = true;
			if (lines[i].substr(0, 6)  == "Query="){
			key = lines[i];
		
				//	cout << key << endl;
					//cout << endl;
					//cout << endl;
			}
			else{
				string seq = "";
				while (i<lines.size() &&  lines[i].substr(0, 6) != "Query="){
					cout << i << endl;
					seq = seq + lines[i]; int queryLength = 1;
					if (lines[i].substr(0, 7) == "Length=" && lines[i-2].substr(0,6)=="Query="){
						string:: size_type sz;

						 queryLength = stoi(lines[i].substr(7), &sz);
						// cout << "queryLength: " << queryLength << endl << endl;
					}

					if ((lines[i].find("Identities ="))!=string::npos){
						int j = 14; string temp = ""; string::size_type sz2;
						while (lines[i][j] != '/'){
							temp += lines[i][j];
							j++;
						}
						
							int alignLength = stoi(temp, &sz2); 
					//		cout << alignLength + 10000<<endl<<endl;
							if ((90 / 100) <= alignLength/queryLength <= 110 / 100){
								if (labels.size() > 0){
									if (labels[labels.size() - 1] != key){
										labels.push_back(key);
									}
								}
								else{
									labels.push_back(key);
								}
							//	check = false;
							//	cout << "key: " << labels[0]<<endl<<endl;
							}
					}
					i++;
				}
					//cout << seq<<endl;
					nucl[key] = seq;
				i--;
		//		dna[ex] = seq;

			
			}
		

		}

	//	cout << "size: " << labels.size() << endl;

	//	medianSearch(dna, labels, 6);
	}
//	reduceFile(nucl, labels);
//	unordered_map<string,string>temp=readSecondFile();
	//reduceFile(temp, labels);
	//unionFunc(nucl, temp);
	system("pause");
	return 0;
}

