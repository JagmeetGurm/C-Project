// unionDatabase.cpp : Defines the entry point for the console application.
//
/*
This project is done by Jagmeet Singh Gurm as part of the CSCI 291 Bioinformatics assignment assigned by Dr. Park.
The program takes as input two databases and makes a database which is union of these two databases. The program is written in c++ language and can be run in MS Visual Studio by compiling(F7) and then executing(F5).

First, the MetaHIT.fa database is aligned against HMP.fa using NCBI BLASTn, and the output is MetaHIT-nr-HMP.fa file using the threshold value: BLASTn Evalue = 10^-5 and Alignment identity >= 95%.
Similarly, the HMP.fa is aligned against MetaHIT-nr-HMP.fa using NCBI BLASTn, and the output is HMP-nr-(MetaHIT-nr-HMP).fa file using the same threshold.
Finally, in this program 90% ≤ alignment_length/query_length ≤ 110%, threshold is used.

In the main function, first the MetaHIT-nr-HMP.fa file is read and the threshold value 90% ≤ alignment_length/query_length ≤ 110%,  is applied. The query name list is made of those queries which meet this threshold. Then the queries are erased from the main database which corresponds to the the queries in the list.
Similarly, the second HMP-nr-(MetaHIT-nr-HMP).fa file is read and same action is performed on it.

*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

/*

//function to union the two files, it receives two files as arguments as  unordered maps
//then writing the output to the output file. 
void unionFunc(unordered_map<string, string>&file1, unordered_map<string, string>&file2){
	vector<string>finallabels;
	for (auto& x : file2){
		file1[x.first] = x.second;
		for (int i = 0; i < x.second.size(); i++){
			string temp = "";
			if (x.second[i] == '>'){
				while (x.second[i] != 'L'){
					temp = temp + x.second[i];
					i++;
				}
			}
				finallabels.push_back(temp);
			
		}
	}

	ofstream myfile;
	
	myfile.open("unionFile3.fa", ios::out);

	for (int j = 0; j < finallabels.size(); j++){
		myfile << finallabels[j]<<endl;// << endl;
	}
	myfile.close();
	
}


//function to remove the found redundant query list from the original database
//the function receives tow inputs: the file and the list of query names to be removed
void reduceFile(unordered_map<string, string>& comb, vector<string>& label){
	cout << "now size: " << comb.size() << endl;
	for (auto it = comb.begin(); it != comb.end(); ){
		bool t = true;
		for (int i = 0; i < label.size(); i++){
			if (it->first == label[i]){
			//	cout << it->first << endl;
			it=	comb.erase(it);
				i = label.size();
				t = false;
			//	goto done;
			}
		}
		if(t)
			it++;
//	done:
		//it++;
//	done:;
	}
	

}

//this function reads the second file and returns the reduced file with
//redundants removed. 
unordered_map<string,string> readSecondFile(){
	ifstream inputFile2;
	
	inputFile2.open("HMP-nr-(MetaHIT-nr-HMP).fa", ios::in);

	vector<string>labels;
	vector<string>lines;
	unordered_map<string, string>nucl;

	if (!inputFile2){ //if not able to open file 
		cout << "cannot open file";

	}
	else{
		//int i = 0;
		string seq = "";
		string line;
		string key;
		
		//	unordered_map<string, string>dna;
		while (!inputFile2.eof())
		{

			getline(inputFile2, line);
			lines.push_back(line);

		}

		for (int i = 14; i <lines.size(); i++){
			//bool check = true;
			if (lines[i].substr(0, 6) == "Query="){
				key = lines[i];
				//	cout << key << endl;
				//cout << endl;
				//cout << endl;
			}
			else{
				string seq = "";
				while (i< lines.size() && lines[i].substr(0, 6) != "Query="){
					seq = seq + lines[i]; int queryLength = 1;
					if (lines[i].substr(0, 7) == "Length=" && lines[i - 2].substr(0, 6) == "Query="){
						string::size_type sz;

						queryLength = stoi(lines[i].substr(7), &sz);
						// cout << "queryLength: " << queryLength << endl << endl;
					}

					if ((lines[i].find("Identities =")) != string::npos){
						int j = 14; string temp = ""; string::size_type sz2;
						while (lines[i][j] != '/'){
							temp += lines[i][j];
							j++;
						}

						int alignLength = stoi(temp, &sz2);
						//		cout << alignLength + 10000<<endl<<endl;
						if ((90 / 100) <= alignLength / queryLength <= 110 / 100){
							if (labels.size() > 0){
								if (labels[labels.size() - 1] != key){
									labels.push_back(key);
								}
							}
							else{
								labels.push_back(key);
							}
							//	check = false;
							//	cout << "key: " << labels[0]<<endl<<endl;
						}
					}
					i++;
				}
				//cout << seq<<endl;
				nucl[key] = seq;
				i--;
				//		dna[ex] = seq;


			}


		}

	//	cout << "size: " << labels.size() << endl;

		//	medianSearch(dna, labels, 6);
	}
	return nucl;
}


int main()
{
	vector<string>labels;
	vector<string>lines;
	unordered_map<string, string>nucl;
	ifstream inputFile2;
	//vector<string> v;
	//reading a exon file line by line
	inputFile2.open("metaHIT-nr-HMP.fa", ios::in);

	if (!inputFile2){ //if not able to open file 
		cout << "cannot open file";

	}
	else{
		//int i = 0;
		string seq = "";
		string line;
		string key;
		
	//	unordered_map<string, string>dna;
		while (!inputFile2.eof())
		{

			getline(inputFile2, line);
			lines.push_back(line);

		}

		cout << "line size: " << lines.size() << endl;
		for (int i = 14; i <lines.size(); i++){
			//bool check = true;
			if (lines[i].substr(0, 6)  == "Query="){
			key = lines[i];
		
				//	cout << key << endl;
					//cout << endl;
					//cout << endl;
			}
			else{
				string seq = "";
				while (i<lines.size() &&  lines[i].substr(0, 6) != "Query="){
				//	cout << i << endl;
					seq = seq + lines[i]; int queryLength = 1;
					if (lines[i].substr(0, 7) == "Length=" && lines[i-2].substr(0,6)=="Query="){
						string:: size_type sz;

						 queryLength = stoi(lines[i].substr(7), &sz);
						// cout << "queryLength: " << queryLength << endl << endl;
					}

					if ((lines[i].find("Identities ="))!=string::npos){
						int j = 14; string temp = ""; string::size_type sz2;
						while (lines[i][j] != '/'){
							temp += lines[i][j];
							j++;
						}
						
							int alignLength = stoi(temp, &sz2); 
					//		cout << alignLength + 10000<<endl<<endl;
							if ((90 / 100) <= alignLength/queryLength <= 110 / 100){
								if (labels.size() > 0){
									if (labels[labels.size() - 1] != key){
										labels.push_back(key);
									}
								}
								else{
									labels.push_back(key);
								}
							//	check = false;
							//	cout << "key: " << labels[0]<<endl<<endl;
							}
					}
					i++;
				}
					//cout << seq<<endl;
					nucl[key] = seq;
				i--;
		//		dna[ex] = seq;

			
			}
		

		}

		cout << "size: " << labels.size() << endl;

	//	medianSearch(dna, labels, 6);
	}
	reduceFile(nucl, labels);
	unordered_map<string,string>temp=readSecondFile();
	reduceFile(temp, labels);
	unionFunc(nucl, temp);
	system("pause");
	return 0;
}

*/
int main(){
	string x = "> scaffold6960_1_MH0002> scaffold65444_2_MH0002> scaffold6144_2_MH0001> scaffold93_3_MH0001> scaffold1185_4_MH0002> scaffold3448_1_MH0003> scaffold22364_2_MH0002> scaffold93988_1_MH0002> scaffold82153_4_MH0002> scaffold15898_4_MH0002> scaffold80425_1_MH0002> scaffold7134_1_MH0001> scaffold33516_1_MH0002> scaffold4368_1_MH0003> scaffold6256_1_MH0003> scaffold1605_3_MH0003> scaffold80425_1_MH0002> scaffold1419_1_MH0003> scaffold91710_2_MH0002> scaffold1329_6_MH0003> scaffold6342_3_MH0003> scaffold84601_1_MH0002> scaffold1329_6_MH0003> scaffold19138_1_MH0002> scaffold7885_3_MH0001> scaffold19138_1_MH0002> scaffold6240_4_MH0003> scaffold20656_1_MH0001> scaffold49943_1_MH0002> scaffold28287_1_MH0002> scaffold1112_2_MH0003> scaffold15868_1_MH0002> scaffold1329_6_MH0003> C3761237_1_MH0002> scaffold86357_1_MH0002> scaffold4369_4_MH0003> scaffold2845_4_MH0003> scaffold1187_2_MH0001> scaffold13220_1_MH0001> scaffold20236_2_MH0001> scaffold10814_2_MH0001> scaffold13817_1_MH0001> scaffold7876_3_MH0001> scaffold6693_8_MH0001> scaffold631_1_MH0001> scaffold44328_2_MH0002> scaffold75811_1_MH0002> scaffold13817_1_MH0001> scaffold6144_2_MH0001> scaffold3230_1_MH0002> scaffold6693_8_MH0001> scaffold7876_3_MH0001> scaffold15010_2_MH0001> scaffold75811_1_MH0002> scaffold66315_3_MH0002> scaffold1695_17_MH0003> scaffold13817_1_MH0001> scaffold4826_4_MH0002> scaffold6693_8_MH0001> scaffold7876_3_MH0001> scaffold31841_7_MH0002> scaffold7876_3_MH0001> scaffold6693_8_MH0001> scaffold4147_3_MH0001> scaffold4147_3_MH0001> scaffold6693_8_MH0001> scaffold15241_2_MH0002> scaffold6693_8_MH0001> scaffold4147_3_MH0001> scaffold7876_3_MH0001> scaffold88783_1_MH0002> scaffold35519_1_MH0002> scaffold53779_1_MH0002> scaffold6693_8_MH0001> scaffold6693_8_MH0001> scaffold13817_1_MH0001> scaffold6693_8_MH0001> scaffold4147_3_MH0001> scaffold5205_1_MH0001> scaffold21348_1_MH0001> scaffold13817_1_MH0001> scaffold21875_1_MH0001> scaffold7876_3_MH0001> scaffold6693_8_MH0001> scaffold13817_1_MH0001> scaffold6693_8_MH0001> scaffold7876_3_MH0001> scaffold6693_8_MH0001> scaffold43428_2_MH0002> scaffold13817_1_MH0001> scaffold6693_8_MH0001> scaffold7876_3_MH0001> scaffold4147_3_MH0001> scaffold1153_4_MH0001> scaffold13817_1_MH0001> scaffold15010_2_MH0001> scaffold7876_3_MH0001> scaffold13817_1_MH0001> scaffold4147_3_MH0001> scaffold7876_3_MH0001> scaffold13817_1_MH0001> scaffold4147_3_MH0001> scaffold7876_3_MH0001> scaffold1153_4_MH0001> scaffold20580_1_MH0001> scaffold16172_1_MH0001> scaffold17388_1_MH0002> scaffold4826_4_MH0002> scaffold2014_3_MH0001> scaffold16311_4_MH0002> scaffold3351_2_MH0001> scaffold11483_1_MH0002> scaffold35519_1_MH0002> scaffold1419_1_MH0003> scaffold12570_2_MH0001> scaffold54731_1_MH0002> scaffold24968_1_MH0002> scaffold19977_1_MH0001> scaffold54731_1_MH0002> scaffold5716_1_MH0003> scaffold721_1_MH0002> scaffold3035_2_MH0001> scaffold1803_1_MH0002> scaffold1329_6_MH0003> scaffold86357_1_MH0002> scaffold11976_2_MH0001> scaffold35519_1_MH0002> scaffold12570_2_MH0001> scaffold1419_1_MH0003> scaffold13419_11_MH0001> scaffold19175_2_MH0001> scaffold13140_1_MH0001> scaffold9291_3_MH0001> scaffold3720_1_MH0001> scaffold4826_4_MH0002> C780876_1_MH0001> scaffold31841_7_MH0002> scaffold86357_1_MH0002> scaffold79051_1_MH0002> scaffold27085_2_MH0002> scaffold15386_1_MH0001> scaffold2845_4_MH0003> scaffold4601_2_MH0003> scaffold223_8_MH0002> scaffold6766_2_MH0003> scaffold1112_2_MH0003> scaffold2003_8_MH0003> scaffold7885_3_MH0001> scaffold7885_3_MH0001> scaffold63_3_MH0002> scaffold2845_4_MH0003> scaffold4369_4_MH0003> scaffold2845_4_MH0003> scaffold4722_2_MH0003> scaffold7885_3_MH0001> scaffold574_2_MH0003> scaffold92809_1_MH0002> scaffold12852_3_MH0001> scaffold13147_1_MH0002> scaffold17072_1_MH0002> scaffold3102_2_MH0003> scaffold39240_1_MH0002> scaffold875_1_MH0001> scaffold17222_1_MH0002> scaffold15551_1_MH0002> scaffold19977_2_MH0001> scaffold20647_1_MH0002> scaffold9024_1_MH0001> scaffold95080_1_MH0002> C3640841_1_MH0002> scaffold3713_1_MH0002> scaffold13140_1_MH0001> scaffold19977_1_MH0001> scaffold12356_1_MH0001> scaffold93067_1_MH0002> scaffold4090_1_MH0003> scaffold1189_2_MH0001> scaffold1053_3_MH0003> scaffold6470_1_MH0002> scaffold9942_2_MH0002> scaffold11176_3_MH0002> scaffold22012_1_MH0001> scaffold1419_1_MH0003> C795205_1_MH0001> C784808_1_MH0001> C3647863_1_MH0002> scaffold17953_1_MH0001> scaffold5716_1_MH0003> scaffold7876_3_MH0001> scaffold721_1_MH0002> scaffold1850_5_MH0003> C3760055_1_MH0002> scaffold78017_1_MH0002> scaffold36943_3_MH0002> scaffold22364_2_MH0002> scaffold2845_4_MH0003> scaffold85872_1_MH0002> scaffold30757_3_MH0002> scaffold1329_6_MH0003> scaffold93988_1_MH0002> scaffold15898_4_MH0002> scaffold1928_8_MH0001> scaffold3016_3_MH0002> scaffold2607_2_MH0003> scaffold17023_2_MH0002> scaffold1185_4_MH0002> scaffold1850_5_MH0003> scaffold2607_3_MH0003> scaffold70932_3_MH0002> scaffold5291_9_MH0003> scaffold6855_5_MH0003> scaffold15879_2_MH0001> scaffold93988_1_MH0002> scaffold8012_2_MH0002> scaffold86357_1_MH0002> scaffold17023_2_MH0002> scaffold30757_3_MH0002> scaffold1329_6_MH0003> scaffold11415_1_MH0002> scaffold729_5_MH0003> scaffold2845_4_MH0003> scaffold6708_2_MH0003> scaffold95003_1_MH0002> scaffold17023_2_MH0002> scaffold1850_5_MH0003> scaffold86357_1_MH0002> scaffold4601_2_MH0003> scaffold56939_1_MH0002> scaffold37335_1_MH0002> scaffold16582_1_MH0002> scaffold5185_1_MH0003> scaffold2845_4_MH0003> scaffold2241_1_MH0003> scaffold411_2_MH0003> scaffold1996_4_MH0002> scaffold4377_3_MH0003> scaffold7779_5_MH0002> scaffold1146_2_MH0003> scaffold48428_2_MH0002> scaffold4369_4_MH0003> scaffold86357_1_MH0002> scaffold2845_4_MH0003> scaffold4003_1_MH0003> scaffold334_1_MH0003> scaffold6687_1_MH0002> scaffold4763_1_MH0003> scaffold44432_1_MH0002> scaffold25891_1_MH0002> scaffold29022_1_MH0002> scaffold3984_2_MH0003> scaffold1595_3_MH0002> scaffold83654_2_MH0002> scaffold1370_1_MH0002> scaffold30757_3_MH0002> scaffold2845_4_MH0003> scaffold15386_1_MH0001> scaffold4369_4_MH0003> scaffold16466_1_MH0002> scaffold19138_1_MH0002> scaffold6342_3_MH0003> scaffold84601_1_MH0002> scaffold13969_1_MH0002> scaffold19930_2_MH0001> scaffold12825_2_MH0002> scaffold2372_1_MH0003> scaffold11976_2_MH0001> scaffold12570_2_MH0001> scaffold1419_1_MH0003> scaffold80425_1_MH0002> scaffold19138_1_MH0002> scaffold20656_1_MH0001> scaffold6587_2_MH0002> scaffold2270_1_MH0003> scaffold86168_2_MH0002> scaffold18956_6_MH0001> scaffold3035_2_MH0001> scaffold20580_1_MH0001> scaffold1189_2_MH0001> scaffold19930_2_MH0001> scaffold1419_1_MH0003> scaffold31841_7_MH0002> scaffold39760_2_MH0002> scaffold8008_1_MH0002> scaffold1419_1_MH0003> scaffold28237_1_MH0002> scaffold19138_1_MH0002> scaffold3765_3_MH0002> scaffold22060_1_MH0001> scaffold1419_1_MH0003> scaffold5205_1_MH0001> scaffold45102_1_MH0002> scaffold21875_1_MH0001> scaffold11483_1_MH0002> scaffold6948_1_MH0003> scaffold3779_2_MH0002> scaffold67739_2_MH0002> C787486_1_MH0001> scaffold25745_2_MH0002> scaffold93233_1_MH0002> scaffold20580_1_MH0001> scaffold21813_1_MH0001> scaffold7846_3_MH0001> C795205_1_MH0001> scaffold22180_2_MH0002> scaffold54731_1_MH0002> C776598_1_MH0001> scaffold19138_1_MH0002> scaffold1329_6_MH0003> scaffold6342_3_MH0003> scaffold84601_1_MH0002> scaffold2664_6_MH0003> scaffold12570_2_MH0001> scaffold326_1_MH0003> scaffold93125_1_MH0002> scaffold17337_12_MH0001> scaffold15320_1_MH0001> scaffold2617_2_MH0001> scaffold1053_3_MH0003> scaffold2068_8_MH0001> scaffold1419_1_MH0003> scaffold1879_12_MH0002> scaffold49553_1_MH0002> scaffold6342_3_MH0003> scaffold84601_1_MH0002> scaffold1497_6_MH0003> scaffold19138_1_MH0002> scaffold96_9_MH0001> C784808_1_MH0001> C775108_1_MH0001> scaffold7810_2_MH0001> scaffold20894_1_MH0001> scaffold10726_4_MH0001> scaffold7988_3_MH0001> scaffold9724_5_MH0001> scaffold5200_1_MH0001> scaffold20467_1_MH0001> scaffold13147_1_MH0002> scaffold12852_3_MH0001> scaffold48305_1_MH0002> scaffold20540_1_MH0001> scaffold1893_6_MH0001> scaffold17934_1_MH0001> scaffold12312_1_MH0001> scaffold19977_2_MH0001> C782910_1_MH0001> scaffold4604_1_MH0003> scaffold14347_2_MH0001> scaffold95080_1_MH0002> scaffold1189_5_MH0001> scaffold22370_1_MH0002> scaffold2070_20_MH0001> scaffold9203_1_MH0001> scaffold19977_1_MH0001> scaffold19263_1_MH0001> scaffold14420_1_MH0001> scaffold9942_2_MH0002> scaffold15259_1_MH0001> scaffold22012_1_MH0001> C795205_1_MH0001> scaffold1419_1_MH0003> scaffold13980_1_MH0002> scaffold14989_1_MH0002";
	ofstream myfile;

	myfile.open("unionFile8.fa", ios::out);
	int i = 0;
	//cout << "jim" << endl;
	for (i = 0; i<x.size(); i++){
		string temp = "";
		if (x[i] == '>'){
			while (i<x.size() && x[i + 1] != '>'){
				temp = temp + x[i];
				i++;
			}
			temp = temp + x[i];
			myfile << temp << endl;
		}
		
	}
	myfile.close();
	system("pause");
	return 0;
}