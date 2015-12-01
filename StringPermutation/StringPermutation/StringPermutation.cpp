// StringPermutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


int main(int argc, _TCHAR* argv[])
{
	string word;
	ifstream inputFile;
	inputFile.open("stringInput.txt");
	while (getline(inputFile, word)){
		cout << word << endl;
	}
	system("pause");
	return 0;
}

