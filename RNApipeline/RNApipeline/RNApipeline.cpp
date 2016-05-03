// RNApipeline.cpp : Defines the entry point for the console application.
//RNA sequence pipelining

/*This project is done by Jagmeet S. Gurm as an assignment- 7 of CSCI 291T- Bioinformatics
assigned by Dr. Park.
The program takes two input files- HG19-refseq-exon-annot-chr1-2016 and 
BTout-BED-ModifiedSorted and output two files-the exonCollapsed file and geneCount2
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
//gene constructor
	gene(int src, int dest, string id, int dummy, string strand){
		this->src = src;
		this->dest = dest;
		this->dummy = dummy;
		geneID = id;
		this->strand = strand;
		count = 0;
	}
	//returns the source id fo the gene_exon
	int sourceID(){
		return src;
	}
	//returns the destination id of the gene_exon
	int destID(){
		return dest;
	}
	//returns the gene_exon id
	string gID(){
		return geneID;
	}
	//sets the gene id
	void setGID(string a){
		geneID = a;
	}
	//sets the strand value
	void setStrand(string b){
		strand = b;
	}
	//returns the strand value
	string retStrand(){
		return strand;
	}
	//returns the dummy value
	int retDummy(){
		return dummy;
	}
	//to keep count of the read mapped
	int count;
private:
	//private members of the class gene
	int src, dest, dummy; 
	string geneID;
	string strand;

};

//function helping in the sorting fo the gene of the exon_gene file
bool sortGene(gene& g1, gene& g2){
	return (g1.sourceID() < g2.sourceID());
	
}
/*This function collapses the exon annotation . It basically performs the 
1st step of RNA-seq data analysis pipelining. The function recieves 
the vector of genes-the gene_exon file and the bowtie file representing 
the vector genes.
The overlapping exons are collapsed and the each exon's name 
and strand is replaced by 'x' and '+' respectively.*/
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

/*this function does the read mapping of the bowtie output file onto 
the gene_exon file. It receives a exon_gene file in the form of vector gene
and another input bowtie file in the form of vector gene*/
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

/*This function does the read mapping of the bowtie output file onto
the gene file with "N"s.. It receives a exon_gene file in the form of vector gene
and another input bowtie file in the form of vector gene and does
the mapping while considering 'N's region covered along with exons.*/
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

/*this function prints the collapsed exon to the 
output file "outExonCollapsed. It receives the exon_gene file 
in the form of a vector gene and prints out to the file.*/
void print(vector<gene>& geneStorage){
	ofstream outExon;
	outExon.open("outExonCollapsed");
	for (int i = 0; i < geneStorage.size(); i++){
		outExon << "chr1 " << geneStorage[i].sourceID() << " " << geneStorage[i].destID() << " " << geneStorage[i].gID() << " "
			<< geneStorage[i].retDummy() << " " << geneStorage[i].retStrand() << "\n";
	}
	outExon.close();
}

/*this function prints the gene count to the
output file "outGeneCount2". It receives the exon_gene file
in the form of a vector gene and prints out to the file the geneID and
the count for each gene by considering the N region to the gene.*/
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

	//reading the exon file
	inputFile.open("HG19-refseq-exon-annot-chr1-2016");
//	inputFile.open("new 2");
	if (!inputFile){
		cout << "sorry! can't open the file" << endl;

	}
	else{
		while (!inputFile.eof()){
			getline(inputFile, line);
			
			//parsing the string line
			std::istringstream buf(line);
			std::istream_iterator<std::string> beg(buf), end;

			std::vector<std::string> tokens(beg, end); // done!
		
//lets create the genes;
		
			
			gene g(stoi(tokens[1]), stoi(tokens[2]), tokens[3], stoi(tokens[4]), tokens[5]);
			geneStorage.push_back(g);
		
		}
	}
	
	sort(geneStorage.begin(), geneStorage.end(), sortGene);
	

	//reading the boutie output file
	boutOutputFile.open("BTout-BED-ModifiedSorted");
	//	inputFile.open("test");
	if (!boutOutputFile){
		cout << "sorry! can't open the file" << endl;

	}
	else{
		while (!boutOutputFile.eof()){
			getline(boutOutputFile, line);
			
			//parsing the string line
			std::istringstream buf(line);
			std::istream_iterator<std::string> beg(buf), end;

			std::vector<std::string> tokens(beg, end); // done!

			//lets create the genes;
			

			gene g(stoi(tokens[1]), stoi(tokens[2]), tokens[3], stoi(tokens[4]), tokens[5]);
			boutGene.push_back(g);
			
		}
	}
	//calling the exon collapsed function
	collapsed(geneStorage, modifiedGene);
	//calling the print exon_file collapsed function to file
	print(geneStorage);
	//calling the function to count the exon read mapping
	exonCount(geneStorage, boutGene);
	//calling the function to count the gene read mapping
	geneCount(geneStorage, boutGene);
	//printing to the output file the gene read mapping		
	printGeneCount(geneStorage);
	
	system("pause");
	return 0;
}

