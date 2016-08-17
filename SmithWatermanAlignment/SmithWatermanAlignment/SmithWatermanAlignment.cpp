// SmithWatermanAlignment.cpp : Defines the entry point for the console application.
//
/*

This program is done by Jagmeet S. Gurm as fullfillment of assignment of
CSCI 291T Bioinformatics.
This program reads two files-the database genome file char1.fa and the query exon file of 10 sequences.
First, genome file is read into a string. Then the second sequence exon file
is read and parsed to form exones where each exon has an id and sequence. These exons are then pushed to a vector of exons.
For exons there is a class which has members- seq and ex which represents
sequence and exon id respectively. Then the SmithWaterman algorithm
is called for each exon and the genome is passed along with
exon sequence.

The SmithWaterman Algorithm does local sequence alignment
for determining similar regions between two strings or nucleotide or protein sequences.
The Smith–Waterman algorithm doesn’t look at total sequence instead it compares segments
of all possible lengths and optimizes the similarity measure.
It is a dynamic programming algorithm where negative scores to set to zero.  It two chars match +2 is added, 
if they differ -1 to score, if any insertion or deletion performed then also -1 to score. Then the final
score is optimal score. And the final indices are the optimal indices of the both compared sequences and queries.



*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


/*
This class basically represents exons and used to create exon objects. It has seq and ex members
which represents the sequence and the ids and other details about exon respectively. */

class exon{
public:
	exon(string e, string s){
		ex = e; 
		seq = s;
	}
	string returnEX(){
		return ex;
	}
	string returnSeq(){
		return seq;
	}

	string ex, seq;
};


/*
// This alignment function takes two inputs the database genome in the form fo string
//and a query sequence of exon. Then a 2-d matrix is created whose row size of 
//genome and column size of 2 with limmiting opimal space for this assignment.
Then the first row and first col are initialized with 0 value.Then the scoring 
methodology is applied to fill the matrix.If two chars of genome database mathc with 
query then a + 2 is done to the score else - 1 for mismatch and - 1 for insertion and 
deletion.The max score out fo the left, up and diagnol cell’s value is then chosen to 
fill the current cell.Then the score fo the last cell is chosen as the optimal Score.
The optimal Score cell’s indices become the optimal indexes.Only first two cols are 
considered for this approach and this program.
*/
void smithWaterman(string& genome, string seqExon){
	cout << "here: "<< genome.size() << endl;
	int opti=0, optj=0;
	int optimumScore=0;
	int**  Vtable = new int*[seqExon.size() + 1]; //only 2 cols
	for (int i = 0; i < seqExon.size() + 1; i++){
		Vtable[i] = new int[2];
		
	}
	double maxVal = 0;
	for (int i = 0; i < seqExon.size(); i++){
		Vtable[i][0] = 0; //
		Vtable[0][i] = 0;
	} //, for all 0 <= i <= pattern_size; //init 1st col, 0
	for (int j = 1; j < genome.size(); j++)// ~ref_size) //for each ref_seq char
	{
		for (int i = 0; i < seqExon.size(); i++) // pattern_size) //for each col of Vtable
     {  if (i==0)
           Vtable[i][1] = 0; //init val 0 for [0][1]; 1st row of 2nd col
	 else
	 {
		 if (genome[j] == seqExon[i])
			 maxVal = maxVal + 2;
		 else maxVal -= 1;
		 if (Vtable[i - 1][j] > maxVal && Vtable[i-1][j]>0)
			 maxVal = Vtable[i - 1][j]; 
		 else if (Vtable[i][j - 1]>maxVal && Vtable[i - 1][j]>0)
			 maxVal = Vtable[i][j - 1];
		 else if (Vtable[i - 1][j - 1]>maxVal && Vtable[i - 1][j]>0)
			 maxVal = Vtable[i - 1][j - 1];// from 4 choices(0, left, upper, diagonal);
		 else maxVal = 0;
		 Vtable[i][1] = maxVal;
	 }
	//	optimumScore = optimumScore + similarityScore(genome[j], seqExon[i]);
		//if (optimumScore < 0)optimumScore = 0;
        if(Vtable[i][1] >= optimumScore)
            optimumScore=optimumScore+ Vtable[i][1];
        //   update optimum_index_i and optimum_index_j;
		opti = i;
		}//loop i
		for (int k = 0; k < seqExon.size();k++) // ~pattern_size)
        Vtable[k][0] = Vtable[k][1]; //move 2nd col to 1st col
		
		optj = j;
	}//loop j

	cout << "display: " << maxVal << endl;
	cout << " optimum_index" << opti <<"  "<< optj;

}
int main()
{
	string genome, content;

	ifstream inputFile("chr1.fa\\chr1.fa", ios::in); //reading input file
	//	ifstream inputFile("chr1.txt");
	//std::ifstream ifs("myfile.txt");

	if (!inputFile)
		cout << "sorry couldn't open file";
	else{
		string	content((std::istreambuf_iterator<char>(inputFile)),
			(std::istreambuf_iterator<char>()));
		int geneSize = content.size();
		//	cout << geneSize;




		//	cout << content.size() << endl;

		//string line;

		ifstream inputFile2;
		//vector<string> v;
		//reading a exon file line by line
		inputFile2.open("Prog2-input-NM_032291-10exon-seqs.fa", ios::in);

		if (!inputFile2){ //if not able to open file 
			cout << "cannot open file";

		}
		else{ 
			//int i = 0;
			string seq = "";
			string line;
			string ex;
			vector<string>lines;
			vector<exon>exons;
			while (!inputFile2.eof())
			{

				getline(inputFile2, line);
				lines.push_back(line);

			}

			for (int i = 0; i < lines.size(); i++){
				if (lines[i][0] == '>'){
					ex = lines[i];
					//	cout << ex << endl;
				}
				else{
					string seq = "";
					while (i < lines.size() && lines[i][0] != '>'){
						seq = seq + lines[i];
						i++;
					}
					//	cout << seq<<endl;
					i--;
					exon e(ex, seq);
					exons.push_back(e);
				}

			}
//	iterating over entire vector of exon sequence queries and calling smithWaterman algorithm
			for (int i = 1; i < exons.size(); i++){
				cout << exons[i].returnEX() << endl;
				smithWaterman(content, exons[i].returnSeq());

			}
		}
	}

	system("pause");
	return 0;
}

