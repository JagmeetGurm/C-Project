// RNApipeline.cpp : Defines the entry point for the console application.
//RNA sequence pipelining



#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

int main()
{
	ifstream inputFile;
	string line;
	inputFile.open("HG19-refseq-exon-annot-chr1-2016");
	if (!inputFile){
		cout << "sorry! can't open the file" << endl;

	}
	else{
		while (!inputFile.eof()){
			getline(inputFile, line);
			//check the file being read
			cout << line << endl;


		}
	}

	return 0;
}

