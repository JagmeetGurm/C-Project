// RNApipeline.cpp : Defines the entry point for the console application.
//RNA sequence pipelining



#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>




using namespace std;

class gene{
	

public:
	gene(int src, int dest, string id, int dummy, string strand){
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
	string strand;

};

bool sortGene(gene& g1, gene& g2){
	return (g1.sourceID() < g2.sourceID());
	//sort(g.begin(), g.end());
/*	int min;
	for (int i = 0; i < g.size() - 1; i++){
		int min = i;
		for (int j = i + 1; j < g.size(); j++){
			if (g[min].sourceID() > g[j].sourceID()){
				min = j;
			}
		}
	
		gene temp = g[min];
		g[min] = g[i];
		g[i] = temp;
	}
*/	
}
int main()
{
	

	ifstream inputFile;
	string line;
	vector<gene>geneStorage;
	inputFile.open("HG19-refseq-exon-annot-chr1-2016");
	if (!inputFile){
		cout << "sorry! can't open the file" << endl;

	}
	else{
		while (!inputFile.eof()){
			getline(inputFile, line);
			//check the file being read
		//	cout << line << endl;
			//parsing the string line
			std::istringstream buf(line);
			std::istream_iterator<std::string> beg(buf), end;

			std::vector<std::string> tokens(beg, end); // done!
		
//lets create the genes;
			std::string::size_type sz;
			
			gene g(stoi(tokens[1]), stoi(tokens[2]), tokens[3], stoi(tokens[4]), tokens[5]);
			geneStorage.push_back(g);
		
		}
	}
	cout << "Im here: " << endl;
	sort(geneStorage.begin(), geneStorage.end(), sortGene);
	for (int i = 0; i < 200; i++){
		cout << geneStorage[i].sourceID() << endl;
	}
	system("pause");
	return 0;
}

