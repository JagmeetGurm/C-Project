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
	while (t){
		for (int i = 3;; i = i + 2){ // outer loop to go through all possible first primes
			for (int j = 2; j <= (i / 2); j++){
				//if (i%j)
			}

		}
	}
	return 0;
}

