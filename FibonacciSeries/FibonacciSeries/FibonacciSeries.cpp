// FibonacciSeries.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;
//first will read numbers from file line by line and 
//then print corresponding fibonacci number

//iterative version added
int fibo2(int n){
	
	if (n == 0)
		return n;
	if( n == 1)
		return n;
	int fib1 = 0, fib2=1, sum=0;

	for (int i = 0; i < n-1; i++){
		sum = fib1 + fib2;

		fib1 = fib2;
		fib2 = sum;
		}
	return sum;
}
int fibo(int n){
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else return fibo(n - 1) + fibo(n - 2);
}

//function to calculate factorial value
int fact(int n){
	//assert 
	assert(n >= 0 && "n is less than 0");
	if (n == 0)
		return 1;
	else return n*fact(n - 1);
}
//pass by reference
void swapByRef(int& a, int& b){
	int c;
	c = a;
	a = b;
	b = c;
	return;

}

int main(int argc, char* argv[])
{
	std::ifstream inputFile;
//	inputFile.open(argv[1]);
	int a;
	//while (inputFile >> a){
	//	std::cout << fibo(a) << std::endl;
	//	std::cout << fibo2(a) << std::endl;

//	}
	//lets check fact
	cout<<fact(5)<<endl;
	a = 5;
	int b = 10;
	//call swap by reference to swap values
	swap(a, b);
	//now a=10, b=5; lets see
	cout << "a: " << a << " " << "b: " << b << endl;
	system("pause");
	return 0;
}

