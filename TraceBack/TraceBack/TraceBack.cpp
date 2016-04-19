/*This program is done by Jagmeet S. Gurm as a part of CSCI 291T-Bioinformatics assignment.
The program reads a query file and a DataBase file and implements the Smith-Waterman
algorithm with trace back operation. 
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;


int main()
{
	ifstream queryFile, dbFile;

	string line, line2;
	//queryFile.open("EColi-query1.fa", ios::in);
	if (!queryFile)
		cout << "Cannot open file"<<endl;
	else{
		while (!queryFile.eof()){
			getline(queryFile, line);
			cout << line << endl;
		}
	}
	//opening db file
	dbFile.open("swissprot-100.fa", ios::in);
	if (!dbFile){
		cout << "cannot open file"<<endl;
	}
	else{
		while (!dbFile.eof()){
			getline(dbFile, line2);
			cout << line2 << endl;
		}
	}
	system("pause");
	return 0;
}

