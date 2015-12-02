// StringPermutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;
//swap function to swap chars in a string
int numOfPermutations = 0;
int times = 0;
vector<string>order;
int factorial(int n){
	if (n == 0|| n==1)
		return 1;
	else return n*factorial (n - 1);

}
void swap(char& a, char& b){
	char temp=a;
	a = b;
	b = temp;
}
//permute function
//reference:http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/



void permute(string& s, int i, int n)
{
	
	if (i == n){ 
	//	cout << s<<endl;
		order.push_back(s);
	//	times++;
	//if (times < numOfPermutations)
	
		// cout << ",";
	}
	else{
		for ( int k = i; k <= n; k++){
			swap(s[i], s[k]);
			permute(s, i + 1, n);
			swap(s[i], s[k]);
		}
	}
}
void print(vector<string>&vs){
	for (int i = 0; i<vs.size(); i++){
		cout << vs[i];
		times++;
		if (times < numOfPermutations)

			cout << ",";
	}
}
int main(int argc, char* argv[])
{
	vector<string> strings;
	string word;
	ifstream inputFile;
	inputFile.open("stringInput2.txt");
	while (getline(inputFile, word)){
	//	cout << word << endl;
		//storing words in string vector
		strings.push_back(word);
	}
	//calling permute function
	for (int i = 0; i < strings.size(); i++){
		//numOfPermutations = factorial(strings[i].length());
		permute(strings[i], 0, strings[i].length()-1);
		numOfPermutations = factorial(strings[i].length());
	std::sort(order.begin(), order.end());
		print(order);
		vector<string> temp;
		order = temp;
		cout << endl;
		times = 0;
		
	}
	
	
	//permute(strings[0], 0, 3 - 1);
	system("pause");
	return 0;
}

