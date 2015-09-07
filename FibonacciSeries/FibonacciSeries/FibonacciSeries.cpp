// FibonacciSeries.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

//using namespace std;
//first will read numbers from file line by line and 
//then print corresponding fibonacci number


int fibo(int n){
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else return fibo(n - 1) + fibo(n - 2);
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream inputFile;
	inputFile.open("Fibonacci.txt");
	int a;
	while (inputFile >> a){
	
		

	}
	system("pause");
	return 0;
}

