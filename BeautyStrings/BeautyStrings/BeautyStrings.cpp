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

	string input;
	ifstream inputFile;
	vector<string> v;
	//reading a file line by line
	inputFile.open("beautyStrings.txt");

	if (!inputFile){ //if not able to open file 
		cout << "cannot open file";

	}
	else{
		
		while (!inputFile.eof())
		{
			getline(inputFile, input);

		//	cout << input << endl;
			v.push_back(input);
		}
	}
//	cout << v.size() << endl;
	
	for (int i = 0; i < v.size(); i++){
		string s = v[i];
		vector<char> letter; //array to store unique letters
		vector<int> frequency; //array to store frequency for each letter
		for (int k = 0; k < s.length(); k++){
			//	bool t=true;
			if (((s[k] >= 65) && (s[k] <= 90)) || ((s[k] >= 97) && (s[k] <= 122)))
			{
				if (letter.size() == 0)
				{
					//cout << s[k];
					letter.push_back(s[k]);
					frequency.push_back(1);
				}
				else {
					bool t = false;
					for (int j = 0; j < letter.size(); j++){
						
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
						
					}

				}
			}

		}

			cout << endl << endl << endl;
			for (int i = 0; i < letter.size(); i++){
				
				//sleection sort
				int	pos_max = i;//set pos_max to the current index of array

				for (int j = i + 1; j < letter.size(); j++)
				{

					if (frequency[j] > frequency[pos_max])
						pos_max = j;
					//pos_max will keep track of the index that min is in, this is needed when a swap happens
				}

				//if pos_max no longer equals i than a bigger value must have been found, so a swap must occur
				if (pos_max != i)
				{
					int temp = frequency[i];
					frequency[i] = frequency[pos_max];
					frequency[pos_max] = temp;
				}
				cout << frequency[i] << endl;
			}
			int sum = 0;
			for (int i = 0, val = 26; i < letter.size(); i++, val--){
				cout << letter[i] << " " << frequency[i] * val << endl; //calculated the beauty of each char 
				sum += frequency[i] * val;


			}
			cout << sum << endl;
		}
	
		system("pause");
		return 0;
	}
