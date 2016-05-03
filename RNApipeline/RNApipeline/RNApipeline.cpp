// RNApipeline.cpp : Defines the entry point for the console application.
//RNA sequence pipelining

/*This project is done by Jagmeet S. Gurm as an assignment- 7 of CSCI 291T- Bioinformatics
assigned by Dr. Park.
The program takes two input files- HG19-refseq-exon-annot-chr1-2016 and 
BTout-BED-75_Modified_Sorted and output two files-the exonCollapsed file and geneCount2
file. The program is written in C++ language and can be run in MS Visual Studio 
environment by first building(F7) and then executing(F5).
The program performs two of the 3 processes of RNA-Seq data analysis pipelining.
First, collapsed exon regions are prepared from HG19 chr1 uisng the collapsed function.
Then, the genome is mask-complemented by masking all non-exon regions with 'N'.
Secondly, a reads file is mapped onto the genome using Bowtie.
Then using the bowtie output file, the read is mapped on each exon from the 
original exon file. And finally, the exon-level read counting is converted
to gene level counting using the printGeneCount function.*/


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>




using namespace std;

/* Gene class represents the gene with all the attributes- srcID, 
destID, geneID, dummy, strand. The gene constructor is 
used to create a new gene_exon after reading from the file.
And the class contains the setter and the getter function.*/
class gene{
	

public:

	gene(int src, int dest, string id, int dummy, string strand){
		this->src = src;
		this->dest = dest;
		this->dummy = dummy;
		geneID = id;
		this->strand = strand;
		count = 0;

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
	
	string retStrand(){
		return strand;
	}
	int retDummy(){
		return dummy;
	}
	int count;
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
			//reset their values(collapsed ones)
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

void exonCount(vector<gene>& exon, vector<gene>& bowtie){
	for (int i = 0; i < exon.size(); i++){
		for (int j = 0; j < bowtie.size(); j++){
			if (exon[i].sourceID() <= bowtie[j].sourceID() && exon[i].destID() >= bowtie[j].destID())
				exon[i].count++;
			if (bowtie[j].destID() > exon[i].destID())
				j = bowtie.size();
		}
	}
}

void geneCount(vector<gene>& exon, vector<gene>& bowtie){
	for (int i = 0; i < exon.size()-1; i++){
		for (int j = 0; j < bowtie.size(); j++){
			if (exon[i].sourceID() <= bowtie[j].sourceID() && exon[i+1].sourceID()-1 >= bowtie[j].destID())
				exon[i].count++;
			if (bowtie[j].destID() > exon[i+1].sourceID())
				j = bowtie.size();
		}
	}
}
void print(vector<gene>& geneStorage){
	ofstream outExon;
	outExon.open("outExonCollapsed");
	for (int i = 0; i < geneStorage.size(); i++){
		outExon << "chr1 " << geneStorage[i].sourceID() << " " << geneStorage[i].destID() << " " << geneStorage[i].gID() << " "
			<< geneStorage[i].retDummy() << " " << geneStorage[i].retStrand() << "\n";
	}
	outExon.close();
}
void printGeneCount(vector<gene>& geneStorage){
	ofstream outGene;
	outGene.open("outGeneCount2");
	for (int i = 0; i < geneStorage.size(); i++){
		string temp = geneStorage[i].gID();
		int j = 0;
		while (temp[j] != 'e'){
			j++;

		}
		string t = temp.substr(0, --j);

		outGene << t << "  " << geneStorage[i].count << "\n";
	}
	outGene.close();
}
int main()
{
	
	
	ifstream inputFile, boutOutputFile;
	string line, line2;
	vector<gene>geneStorage;
	vector<gene>boutGene;
	vector<gene>modifiedGene;
	inputFile.open("HG19-refseq-exon-annot-chr1-2016");
//	inputFile.open("new 2");
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

	//reading the boutie output file


	boutOutputFile.open("BTout-BED-75_Modified_Sorted");
	//	inputFile.open("test");
	if (!boutOutputFile){
		cout << "sorry! can't open the file" << endl;

	}
	else{
		while (!boutOutputFile.eof()){
			getline(boutOutputFile, line);
			//check the file being read
			//	cout << line << endl;
			//parsing the string line
			std::istringstream buf(line);
			std::istream_iterator<std::string> beg(buf), end;

			std::vector<std::string> tokens(beg, end); // done!

			//lets create the genes;
			std::string::size_type sz;

			gene g(stoi(tokens[1]), stoi(tokens[2]), tokens[3], stoi(tokens[4]), tokens[5]);
			boutGene.push_back(g);
			//cout << boutGene.size() << endl;
		}
	}
	cout << "Im here again: " << endl;
//	collapsed(geneStorage, modifiedGene);
//	print(geneStorage);

//	exonCount(geneStorage, boutGene);
	geneCount(geneStorage, boutGene);
	//for (int i = 0; i < 200; i++){
	//	cout << geneStorage[i].gID()<<" "<<geneStorage[i].count << endl;
	//}
	
	cout << "done again: " << endl;
	printGeneCount(geneStorage);
	


	system("pause");
	return 0;
}

