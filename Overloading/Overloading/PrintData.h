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
		cout << i << endl;
	}
	//function to print float value
	void print(float i){
		cout << i << endl;
	}
	//function to print characters
	void print(char* c){
		cout << c << endl;
	}

};
#endif