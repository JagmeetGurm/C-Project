// TraceBack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;


int main()
{
	ifstream queryFile;
	string line;
	queryFile.open("EColi-query1.fa", ios::in);
	if (!queryFile)
		cout << "Cannot open file";
	else{
		while (!queryFile.eof()){
			getline(queryFile, line);
			cout << line << endl;
		}
	}
	system("pause");
	return 0;
}

