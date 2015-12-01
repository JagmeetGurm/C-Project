// StringPermutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;


int main(int argc, _TCHAR* argv[])
{
	vector<string> strings;
	string word;
	ifstream inputFile;
	inputFile.open("stringInput.txt");
	while (getline(inputFile, word)){
	//	cout << word << endl;
		//storing words in string vector
		strings.push_back(word);
	}
	//calling permute function
	system("pause");
	return 0;
}

