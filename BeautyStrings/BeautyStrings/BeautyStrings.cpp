// BeautyStrings.cpp : Defines the entry point for the console application.
//
//Beauty Strings Project to calculate the maximum baeauty of the string. 
//Each character will be assigned a beauty value between 1 and 26 (including) 
//and the sum of the chars will be the beauty of the string


//Methodology 
//1. First we need to accept filename as an argument.
//program will read file if successful else will quit the file

//2. Then, We need a way to calculate each strings maximum beauty
//This can be done by assigning the letter with maximum repitition, the maximum value
//the next max, the next max value and so on.
// For this, we will read the file line by line and then will assign max beauty to each line
//Now we need to find a way to first calculate frequency of each char and then assign it a max value



#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



int main()
{
	char letter[26]; //array to store unique letters
	int frequency[26]; //array to store frequency for each letter
	string input;
	ifstream inputFile;
	vector<string> v;
	//reading a file line by line
	inputFile.open("beautyStrings.txt");

	if (!inputFile){ //if not able to open file 
		cout << "cannot open file";

	}
	else{
	//	getline(inputFile, input, '$');
		while (!inputFile.eof())
		{
			getline(inputFile, input);// , '$');

			cout << input << endl;
			v.push_back(input);
		}
	}
	cout << v.size()<<endl;

	for (int i = 0; i < v.size(); i++){
		string s = v[i];
		
		for (int k = 0; k < s.length(); k++){
			if (('a' <= s[k] <= 'z') || ('A'<=s[k] <='Z'))
			{
				for (int j = 0; j < 26; j++){
					if (s[k] == letter[j])
					{
						frequency[j]++;
					}
					else continue;

					letter[j] = s[k];
					frequency[k] = 1;
				}
			}

		}
	}
	system("pause");
	return 0;
}

