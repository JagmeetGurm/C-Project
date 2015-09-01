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
//#include <boost/algorithm/string.hpp>
//#include <boost/algorithm/string/predicate.hpp>
using namespace std;



int main()
{
	
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
	int l=0;
	for (int i = 0; i < v.size(); i++){
		string s = v[i];
		vector<char> letter; //array to store unique letters
		vector<int> frequency; //array to store frequency for each letter
		for (int k = 0; k < s.length(); k++){
		//	bool t=true;
			if (( (s[k]>=65) &&(s[k]<= 90)) || ((s[k]>=97) && (s[k] <= 122) ))
			{
				if (letter.size() == 0)
				{
					//cout << s[k];
					letter.push_back( s[k]);
					frequency.push_back( 1);
				}
				else {
					bool t=false;
					for (int j = 0; j < letter.size(); j++){
						//t = false;
						if (tolower(s[k]) == tolower(letter[j])) //case insensitive comparison
						{
							t = true;
							frequency[j]++;
						}
						else continue;
					}
						if (t == false)
						{
							letter.push_back(s[k]);
							frequency.push_back(1);
							//cout << letter[l] << " "<<frequency[l]<<endl;
							//l++;
						}
					
				}
			}


		}
	/*	cout << letter[0] << " " << frequency[0] << endl;
		cout << letter[1] << " " << frequency[1] << endl;
		cout << letter[2] << " " << frequency[2] << endl;
		cout << letter[3] << " " << frequency[3] << endl;
		//cout << letter[4] << " " << frequency[4] << endl;
		//cout << letter[5] << " " << frequency[5] << endl; 
		*/
		cout << endl << endl << endl;
		for (int i = 0; i < letter.size(); i++){
		//	cout << letter[i] << " " << frequency[i] << endl;

		}
	}
	
	system("pause");
	return 0;
}

