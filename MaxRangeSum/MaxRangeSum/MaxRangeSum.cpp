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
	int numDays;
	ifstream infile;
	infile.open("inputSum.txt");
	string s;
	while (getline(infile, s)){
		vector<int>profit;
		int i = 0; 
		int j = 0;
		while (s[i] != ';'){
			j++;
			i++;
		}	
	
		string s1 = s.substr(0, j);
		//cout << s1<<endl;
		int day = stoi(s1);
		//cout << day << endl;
			numDays=day;
			int z = j+1;
		//	cout << s[j + 1];
			while (z  < s.length()){
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
			for (int i = 0; i < profit.size(); i++){
			//	cout << profit[i] << endl;
			}
			int maxSum = 0; 
			
			for (int i = 0; (profit.size()-i)>=numDays; i++){
				int Sum = 0;
				for (int j = i, l=0; l < numDays ; j++, l++){
					Sum = Sum + profit[j];
				}
				if (Sum > maxSum){
					maxSum = Sum;
				}
			}
			cout << maxSum<<endl;
	}
	
	
	system("pause");
	return 0;
}

