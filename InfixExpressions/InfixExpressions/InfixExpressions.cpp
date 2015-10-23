// InfixExpressions.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <typeinfo>

using namespace std;



int main(int argc, char* argv[])

{
	string line;
	//stack<string> operand;
	//stack<char> operatorStack;
	ifstream infile;
	//infile.open("input.txt");
	infile.open(argv[1]);
	while (getline(infile, line)){
		stack<string> operand;
		stack<char> operatorStack;
		for (int i = 0; i < line.length(); i++){
			if ((line[i] == '+') || (line[i] == '*') || (line[i] == '/') ){
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
				double a = stod(operand.top(), &sz);
				operand.pop();
				double b = stod(operand.top(), &sz);
				operand.pop();
				double result;
				switch (operatorStack.top()){
				case '+':
					result = b+a;
					break;
				case '*':
					result =  b*a;
					break;
				case '/':
					result =  b/a;
					break;
					
				}
				//cout << result;
				operatorStack.pop();
				operand.push(to_string(result));

			}

		}
		if (typeid(operand.top()) != typeid(int())){
			std::string::size_type sy;
			cout<< stoi(operand.top(), &sy)<<endl;
			operand.pop();
		}
		else{
			cout << operand.top() << endl;
			operand.pop();
		}
	}
	
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
	//system("pause");
	return 0;
}

