// ExceptionExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Box.h"

using namespace std;
double division(int a, int b){
	if (b == 0){
		throw "exception! can't divide by 0.";
	}
	return (a / b);
}


int main()
{
	int x = 45;
	int b = 0;
	try{
	int z=	division(40, 0);
	cout << z << endl;
	}
	catch (const char* a){
		cerr << a << endl;
	}
	double* pvalue = NULL; // Pointer initialized with null
	pvalue = new double;   // Request memory for the variable

	*pvalue = 29494.99;     // Store value at allocated address
	cout << "Value of pvalue : " << *pvalue << endl;

	delete pvalue;         // free up the memory.

	

	// box objects to create 
	Box* box1 = new Box[4]; //constructor will be called 4 times
	delete[] box1;//destructor will be callled 4 times
	system("pause");
	return 0;
}

