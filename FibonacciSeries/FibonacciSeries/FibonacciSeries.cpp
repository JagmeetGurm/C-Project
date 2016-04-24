// FibonacciSeries.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>

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

//call by pointer
void swapByPointer(int *a, int *b){
	int c;
	c = *a;
	*a = *b;
	
	*b = c;
}

//pass array-1st way
void passArray(int* a, int len){
	int size = len;
	cout << "its 3rd element: " << a[2] << endl;
}
void passArray2(int a[]){
	cout <<" its 2nd element: "<< a[1] << endl;
}


//sort the array, sort function(sequential sort)
void sort(int* a, int l){
	int min = 1000;
	for (int j = 0; j < l; j++){
		min = j;
		for (int i = j+1; i < l; i++){
			//find min index
			if (a[min] > a[i])
				min = i;
		}
	//swap the min value 
		int temp = a[j];
		a[j] = a[min];
		a[min] = temp;
	}

}
int main(int argc, char* argv[])
{
	std::ifstream inputFile;
	inputFile.open("Fibonacci.txt");
	int a;
	string s;
	if (!inputFile){
		cout << "sorry can't open" << endl;
	}
/*	else{//one way of reading file
		while (inputFile >> a){
			cout << "a's fibonacci: ";
			cout << fibo(a) << endl;
			//cout<< fibo2(a) << std::endl;

		}
	}
	*/
	//reading file 2nd way
	else{
		while (!inputFile.eof()){
			getline(inputFile, s);
			string::size_type sz;
		cout<<	fibo(stoi(s));
			cout <<  endl;
		}
	}
	//lets check fact
	cout<<fact(5)<<endl;
	a = 5;
	int b = 10;
	//call swap by reference to swap values
	swap(a, b);
	//now a=10, b=5; lets see
	cout << "a: " << a << " " << "b: " << b << endl;

	swapByPointer(&a, &b);
	//the a and b values should be back to what they were
	cout << "a: " << a << " " << "b: " << b << endl;
	int arr[5] = {2,4, 3, 6, 3 };
	 passArray(arr,5);
	 passArray2(arr);
	 sort(arr, 5);
	 for (int i = 0; i < 5; i++){
		 cout << arr[i] << "    ";
	 }
	system("pause");
	return 0;
}

