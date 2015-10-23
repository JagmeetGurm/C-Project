// InfixExpressions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <typeinfo>

using namespace std;



int main(int argc, char* argv[])

{
	string line;
	
	ifstream infile;
	infile.open("input.txt");
	//infile.open(argv[1]);
	while (getline(infile, line)){
		stack<string> operand; //
		//stack will contain all the operands which are read as string
		stack<char> operatorStack; //another stack holding the operators
		for (int i = 0; i < line.length(); i++){
			//readint the file 
			if ((line[i] == '+') || (line[i] == '*') || (line[i] == '/') ){
				operatorStack.push(line[i]); //pushing operators in operator stack
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
				float a = stod(operand.top(), &sz);
				operand.pop();
				float b = stod(operand.top(), &sz);
				operand.pop();
				float result;
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

	system("pause");
	return 0;
}

