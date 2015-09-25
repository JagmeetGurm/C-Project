// MaxRangeSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>





using namespace std;

int main(int argc, char* argv[])
{
	int numDays; //variable to store num of days for each line
	ifstream infile; //for reading the file
	infile.open("inputSum.txt"); //opening the file
	string s;   //string for storing each line
	while (getline(infile, s)){
		vector<int>profit;  //a vector for storing gain/loss for each line
		int i = 0; 
		int j = 0;
		//string parsing begins
		while (s[i] != ';'){   //rading the no. of days
			j++;
			i++;
		}	
	
		string s1 = s.substr(0, j);  //extracting the no. of days
		//cout << s1<<endl;
		int day = stoi(s1); //converting string to number
		//cout << day << endl;
			numDays=day; //
			int z = j+1;
		//	cout << s[j + 1];
			while (z  < s.length()){   //reading the loss/profit for each day
				int k = 0;
				j = z;
				while (z<s.length() && s[z] != ' '){
					k++;
					z++;
				}
				string s2 = s.substr(j , k);
				int value = stoi(s2);
				profit.push_back(value);
				//cout << value +100 << endl;
				
				z++;

			}
			
			int maxSum = 0;  //a variable to hold max sum at all time begin with 0 as initiation
			
			//looping through to get the max sum
			for (int i = 0; (profit.size()-i)>=numDays; i++){
				int Sum = 0;
				for (int j = i, l=0; l < numDays ; j++, l++){
					Sum = Sum + profit[j];
				}
				if (Sum > maxSum){
					maxSum = Sum;
				}
			}
			cout << maxSum<<endl; //printing the max sum
	}
	
	
	system("pause");
	return 0;
}

