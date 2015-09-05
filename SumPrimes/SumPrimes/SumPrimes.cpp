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
	sum = 2;
	bool t = true;
	int count = 1;
	while (t){
		for (int i = 3;; i = i + 2){ // outer loop to go through all possible first primes
			int j;
			for (j = 2; j <= (i / 2); j++){ //inner loop to check if no is prime
				if (i%j == 0)
					j = (i / 2)+1;
				else continue;

			}
			if (j > (i / 2)){//that means no is prime

				sum += i;  //add prime no to total
				count++;
			}
			if (count == 1000){
				t = false;
			}

		}
	}
	cout << "total: " << sum;
	system("pause");
	return 0;
}

