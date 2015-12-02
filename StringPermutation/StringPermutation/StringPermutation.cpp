// StringPermutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;
//swap function to swap chars in a string
int numOfPermutations = 0;
int factorial(int n){
	if (n == 0|| n==1)
		return 1;
	else return n*(n - 1);

}
void swap(char& a, char& b){
	char temp=a;
	a = b;
	b = temp;
}
//permute function
void permute(string& s, int i, int n)
{
	
	if (i == n) cout << s;
	//if(k!=n)
		//cout<< ",";
	else{
		for ( int k = i; k <= n; k++){
			swap(s[i], s[k]);
			permute(s, i + 1, n);
			swap(s[i], s[k]);
		}
	}
}
int main(int argc, _TCHAR* argv[])
{
	vector<string> strings;
	string word;
	ifstream inputFile;
	inputFile.open("stringInput.txt");
	while (getline(inputFile, word)){
	//	cout << word << endl;
		//storing words in string vector
		strings.push_back(word);
	}
	//calling permute function
/*	for (int i = 0; i < strings.size(); i++){
		permute(strings[i], 0, strings[i].length()-1);
		cout << endl;
	}*/
	numOfPermutations = factorial(3);
	
	permute(strings[0], 0, 3 - 1);
	system("pause");
	return 0;
}

