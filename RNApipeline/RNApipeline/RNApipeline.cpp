// RNApipeline.cpp : Defines the entry point for the console application.
//RNA sequence pipelining



#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

class gene{
public:
	gene(int src, int dest, int dummy, string id, char strand){
		this->src = src;
		this->dest = dest;
		this->dummy = dummy;
		geneID = id;
		this->strand = strand;


	}
	int sourceID(){
		return src;
	}
	int destID(){
		return dest;
	}
	string gID(){
		return geneID;
	}

private:
	int src, dest, dummy;
	string geneID;
	char strand;

};
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
//

		}
	}

	return 0;
}

