// TypeAhead.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>



using namespace std;
int arr[100], m=1;
//hard code text in program
string text = "Mary had a little lamb its fleece was white as snow And everywhere that Mary went the lamb was sure to go It followed her to school one day which was against the rule It made the children laugh and play to see a lamb at school And so the teacher turned it out but still it lingered near And waited patiently about till Mary did appear Why does the lamb love Mary so the eager children cry Why Mary loves the lamb you know the teacher did reply" ;
string* myString=new string[text.length()];
//map<string, int>freq;
int size;
//string* v2 = new string[100];
vector<string>v2;
/*
void ngram(int len, string test){
	vector<string>v;
	
	for (int i = 0; i < size-len+1; i++){
		if (len == 2){
			if (myString[i] + myString[i + 1] == test+myString[i+1]){
			freq[myString[i]+myString[i+1]]++;
				v.push_back(myString[i + 1]);
			}
			
		}
		if (len == 3){
			if (myString[i] + myString[i + 1] + myString[i + 2] == test + myString[i + 2]){
				freq[myString[i] + myString[i + 1] + myString[i + 2]]++;
				v.push_back(myString[i + 2]);
			}
		}
			if (len == 4){
				if ((myString[i] + myString[i + 1] + myString[i + 2]+myString[i+3]) == (test + myString[i + 3])){
					freq[myString[i] + myString[i + 1] + myString[i + 2]+myString[i+3]]++;
					v.push_back(myString[i + 3]);
				//	cout << "hello";
				}
		}
	}
	v2 = v;
}
*/
bool wayToSort(pair<int,string>m1, pair<int, string>m2){
	return (m1.first>m2.first);
		
}
int main(int argc, char* argv[])
{
	//myString.push_back(text[0]);
	ifstream infile;
//infile.open(argv[1]);
infile.open("testFile.txt");
	string check;
	/*for (int i = 0, j = 0; i < text.length(); i++, j++){
		string s = "";
		while (text[i] != ' '){
			s = s + text[i];
			i++;
		}
		myString[j] = s;
		freq[myString[j]] = 0;
		size = j + 1;
	}
	*/
	while (getline(infile, check)){
		//cout << check << endl;
		map<string, int>freq;
		for (int i = 0, j = 0; i < text.length(); i++, j++){
			string s = "";
			while (text[i] != ' ' && text[i]!='\0'){
				if ((text[i] == ',') || (text[i] == ';') || (text[i] == '.') || (text[i] == '?') || (text[i] == '"'))
				{
					goto done;
				}
				s = s + text[i];
				done:
				i++;
			}
			myString[j] = s;
			freq[myString[j]] = 0;
			size = j + 1;
		}
		string myLine = "";// = check[0];
		int num = (check[0]) - '0';
		//	cout << num<<endl;
		for (int i = 2; i < check.length(); i++){
			if (check[i] == ' ')
				continue;
			myLine += check[i];

		}
		//	cout << myLine << endl;

		/*	for (int i = 0, j=0; i < text.length(); i++, j++){
				string s="";
				while (text[i] != ' '){
				s = s+text[i];
				i++;
				}

				myString[j] = s;
				freq[myString[j]] = 0;
				size = j+1;
				//cout << myString[j] << " ";

				}
				*/
		//		map<string, int>freq;
		//	ngram(num, myLine);
		vector<string>v;

		for (int i = 0; i < size - num + 1; i++){
			if (num == 2){
				if (myString[i] + myString[i + 1] == myLine + myString[i + 1]){
					freq[myString[i] + myString[i + 1]]++;
					v.push_back(myString[i + 1]);
				}

			}
			if (num == 3){
				if (myString[i] + myString[i + 1] + myString[i + 2] == myLine + myString[i + 2]){
					freq[myString[i] + myString[i + 1] + myString[i + 2]]++;
					v.push_back(myString[i + 2]);
				}
			}
			if (num == 4){
				if ((myString[i] + myString[i + 1] + myString[i + 2] + myString[i + 3]) == (myLine + myString[i + 3])){
					freq[myString[i] + myString[i + 1] + myString[i + 2] + myString[i + 3]]++;
					v.push_back(myString[i + 3]);
					//	cout << "hello";
				}
			}
		}
		//cout << freq["theteacher"];
		int max = 0;
		int total = 0;
		int k = 0;
		int l = 0;
		pair<int, string>p;
		vector<std::pair<int, string>> items;
		//map<string, int>freq;
		for (std::map<string, int>::iterator it = freq.begin(); it != freq.end(); ++it)
		{

			if (it->second > 0)
			{
				p.first = it->second;
				p.second = it->first;
				items.push_back(p);
				//	cout << items[k].second << ": " << items[k].first;
				//	std::cout << it->first << " => " << it->second << '\n';
				total += it->second;
				k++;
			}
			l++;
		}
		//	map<string, int>freq;
		//	cout << "item size:" << items.size();
		int line = items.size();
		arr[0] = 0;
		arr[m] = items.size();
		std::sort(items.begin(), items.end(), wayToSort);
		int mySize = 0;
		for (vector<pair<int, string>>::iterator it = items.begin(); it != items.end(); ++it){
			//for (int j = arr[m-1]; j < items.size(); j++){
			for (int i = 0; i < size - num + 1; i++){
				//if (it->second.find(v2[i]))
				//	cout << v2[i]<<",";

				if (num == 2){
					if (myString[i] + myString[i + 1] == it->second)
					{
						cout << myString[i + 1] << ",";
						i = size;
					}
				}

				if (num == 3){
					if (myString[i] + myString[i + 1] + myString[i + 2] == it->second)
					{
						cout << myString[i + 2] << ",";
						i = size;
					}
				}
				if (num == 4){
					if ((myString[i] + myString[i + 1] + myString[i + 2] + myString[i + 3]) == it->second)
					{
						cout << myString[i + 3] << ",";
						i = size;
					}

				}
			}
			//	cout << it->second << ",";
			cout.precision(3);
			//	cout << "t=" << total << endl;
			//total = total-arr[m-1];
			mySize++;
			cout << fixed << (double)(it->first) / (total);
			if (mySize < items.size())
				cout << ";";
			m++;
		}
		//cout << ";";
		cout << endl;
	}
		system("pause");
	
	return 0;
}

