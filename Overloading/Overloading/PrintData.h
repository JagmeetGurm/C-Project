#ifndef PRINTDATA_H
#define PRINTDATA_H
#include <iostream>
using namespace std;
//function overloading example
class PrintData{
public:

	void print(int i)
	{
		cout << i << endl;
	}
	void print(float i){
		cout << i << endl;
	}
	void print(char* c){
		cout << c << endl;
	}

};
#endif