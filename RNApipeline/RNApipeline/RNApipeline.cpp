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
	void setGID(string a){
		geneID = a;
	}
	void setStrand(string b){
		strand = b;
	}

private:
	int src, dest, dummy;
	string geneID;
	string strand;

};

bool sortGene(gene& g1, gene& g2){
	return (g1.sourceID() < g2.sourceID());
	
}

void collapsed(vector<gene>& storage, vector<gene>& modified){
	int i, j;
	for (i = 0; i < storage.size() - 1; i++){

		if (storage[i].sourceID() == storage[i + 1].sourceID()){
			j = i + 1;
			while (j<storage.size() && storage[i].sourceID() == storage[j].sourceID()){
				j++;
			}
			j = j - 1;
			storage[j].setGID("x");
			storage[j].setStrand("+");
			modified.push_back(storage[j]);
			i = j;
		}
		else{
			modified.push_back(storage[i]);
		}
		
	}
}
int main()
{
	

	ifstream inputFile;
	string line;
	vector<gene>geneStorage;
	vector<gene>modifiedGene;
	inputFile.open("HG19-refseq-exon-annot-chr1-2016");
//	inputFile.open("test");
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
	cout << "done: " << endl;
	collapsed(geneStorage, modifiedGene);
	for (int i = 0; i < 200; i++){
		cout << modifiedGene[i].sourceID() << endl;
	}
	system("pause");
	return 0;
}

