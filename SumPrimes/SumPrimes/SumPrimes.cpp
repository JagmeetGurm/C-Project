// SumPrimes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//program to give sum of first 1000 primes
int main()
{
	int sum; //int variable to hold sum of primes 
	sum = 5; //2 and 3 are already added
	bool t = true;
	int count = 2; //2,3 already counted
	
		for (int i = 5;t==true; i = i + 2){ // outer loop to go through all possible first primes
			int j;
			for (j = 2; j < (i / 2); j++){ //inner loop to check if no is prime
				if (i%j == 0)
					j = (i / 2)+1;
				else continue;

			}
			if (j ==(i / 2)){//that means no is prime
				//cout <<"printing primes"<< i << endl;
				sum += i;  //add prime no to total
				count++; //keep track of total no of primes
			}
			if (count == 10){
				t = false;
			}

		}
	
	cout << sum;
	system("pause");
	return 0;
}

