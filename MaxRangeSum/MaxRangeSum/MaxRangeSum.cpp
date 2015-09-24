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
	vector<int>numDays;
	ifstream infile;
	infile.open("inputSum.txt");
	string s;
	while (getline(infile, s)){

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
			numDays.push_back(day);
			cout << numDays[i]+10<<endl;
		
	}
	system("pause");
	return 0;
}

