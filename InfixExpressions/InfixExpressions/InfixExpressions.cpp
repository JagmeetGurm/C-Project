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
	stack<string> operand;
	stack<char> operatorStack;
	ifstream infile;
	infile.open("inputTest.txt");
	while (getline(infile, line)){
		for (int i = 0; i < line.length(); i++){
			if ((line[i] == '+') || (line[i] == '*') || (line[i] == '/') || (line[i] == '-')){
				operatorStack.push(line[i]);
			}
			else if (line[i] == ' ')
			{	//do nothing;
			}
			else {
				string s;
				char c = line[i];
				stringstream ss;
				ss << c;
				ss >> s;


				operand.push(s);
			}
			if (operand.size() == 2){
				std::string::size_type sz;
				int a = stoi(operand.top(), &sz);
				operand.pop();
				int b = stoi(operand.top(), &sz);
				operand.pop();
				int result;
				switch (operatorStack.top()){
				case '+':
					result = a + b;
					break;
				case '*':
					result = a * b;
					break;
				case '/':
					result = a / b;
					break;
					
				}
			//	cout << result;
				operatorStack.pop();
				operand.push(to_string(result));

			}

		}
	}
	cout << operand.top()<<endl;
/*	while (!operatorStack.empty()){
		cout << "oepartor stack:";
	cout<<	operatorStack.top()<<endl;
	operatorStack.pop();
	}
	while (!operand.empty()){
		cout << "operand stack:";
		cout << operand.top() << endl;
		operand.pop();
	}
*/
	system("pause");
	return 0;
}

