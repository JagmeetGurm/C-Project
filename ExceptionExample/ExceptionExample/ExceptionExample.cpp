// ExceptionExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
double division(double a, double b){
	if (b == 0){
		throw "exception! can't divide by 0.";
	}
	return (a / b);
}


int _tmain(int argc, _TCHAR* argv[])
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
	system("pause");
	return 0;
}

