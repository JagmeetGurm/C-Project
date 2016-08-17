// prefixExpressions.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <typeinfo>

using namespace std;


//prefix expression evaluation using  stack 
int main(int argc, char* argv[])

{
	string line;

	ifstream infile;
	infile.open("input.txt");
	//infile.open(argv[1]);
	while (getline(infile, line)){  //reading file line by line
		stack<string>operand;  //operand stack
		for (int i = line.length() - 1; i >= 0; i--){
			//parsing the line starting from end to start
			if (line[i] == ' '){
				//do nothing
			}
			else if ((line[i] == '+') || (line[i] == '*') || (line[i] == '/')){
				if (operand.size()>=2){
					std::string::size_type sz;
					float a = stod(operand.top(), &sz);
					operand.pop();
					float b = stod(operand.top(), &sz);
					operand.pop();
					float result;  //will hold the result to two operands
					switch (line[i]){
					case '+':
						result = a + b;
						break;
					case '*':
						result = a*b;
						break;
					case '/':
						result = a / b;
						break;

					}
					operand.push(to_string(result));
				}
			}
			else{
				string s;
				char c = line[i];
				stringstream ss;
				ss << c;
				ss >> s;


				operand.push(s);
				
			}


		}
		if (!operand.empty()){
			std::string::size_type sy;
			cout << stoi(operand.top(), &sy) << endl;
			operand.pop();
		}
		else{ 
			cout << "no operand" << endl;
		}
	}
	system("pause");
	return 0;
}




























	/*	stack<string> operand; //
		//stack will contain all the operands which are read as string
		stack<char> operatorStack; //another stack holding the operators
		for (int i = 0; i < line.length(); i++){
			//readint the file 
			if ((line[i] == '+') || (line[i] == '*') || (line[i] == '/')){
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
					result = b + a;
					break;
				case '*':
					result = b*a;
					break;
				case '/':
					result = b / a;
					break;

				}
				//cout << result;
				operatorStack.pop();
				operand.push(to_string(result));

			}

		}
	//	if (typeid(operand.top()) != typeid(int())){
			std::string::size_type sy;
			cout << stoi(operand.top(), &sy) << endl;
			operand.pop();
	//	}
	//	else{
	//		cout << operand.top() << endl;
	//		operand.pop();
	//	}
	}

	system("pause");
	return 0;



	
//}
/*
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	vector <string> firstNames;
	vector <string> lastNames;
	string firstName;
	string lastName;
	string minValue;
	char minIndex;
	bool done;
	int i = 0;
	int j = 0;

	done = false;
	while (!done){
		cout << "Enter First Name: ";
		getline(cin, firstName);
		if (!firstName.empty()){
			firstNames.push_back(firstName);
			cout << "Enter Last Name: ";
			getline(cin, lastName);
			lastNames.push_back(lastName);
			cout << firstName << " " << lastName;
			cout << endl;
		}

		else {
			done = true;
		}
	}
	// this sorter needs work

	for (i = 0; i < lastNames.size(); ++i) {
		minValue = lastNames.at(i);
		for (j = i; j < lastNames.size(); ++j) {
			if (lastNames.at(j) <= minValue) {
				minIndex = j;
				minValue = lastNames.at(j);
			}
		}
		lastNames.at(minIndex) = lastNames.at(i);
		lastNames.at(i) = minValue;
	}

	cout << endl << " --Sorted Names-- " << endl;

	for (i = 0; i < firstNames.size(); ++i) {
		cout << firstNames.at(i) << " " << lastNames.at(i) << endl;
	}
	system("pause");
	return 0;
}
*/