// InfixExpressions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

using namespace std;



int main(int argc, char* argv[])

{
	string line;
	stack<int> operand;
	stack<char> operatorStack;
	ifstream infile;
	while (getline(infile, line)){
		for (int i = 0; i < line.length(); i++){
			if ((line[i] == '+') || (line[i] == '*') || (line[i] == '/') || (line[i] == '-')){
				operatorStack.push(line[i]);
			}
		}
	}
	return 0;
}

