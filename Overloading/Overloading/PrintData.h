#ifndef PRINTDATA_H
#define PRINTDATA_H
#include <iostream>
using namespace std;
//function overloading example
class PrintData{
public:

	//function to print integer value
	void print(int i)
	{
		cout <<"print integer: "<< i << endl;
	}
	//function to print float value
	void print(double i){
		cout << "printing double: :"<<i << endl;
	}
	//function to print characters
	void print(char* c){
		cout << "printing characters: "<<c << endl;
	}

};
#endif