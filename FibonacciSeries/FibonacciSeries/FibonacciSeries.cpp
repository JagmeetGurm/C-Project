// FibonacciSeries.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iosream>
#include <fstream>

using namespace std;
//first will read numbers from file line by line and 
//then print corresponding fibonacci number


int fibo(int n){

}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream inputFile;
	inputFile.open("Fibonacci.txt");
	int a;
	while (inputFile >> a){
		fibo(a);

	}
	return 0;
}

