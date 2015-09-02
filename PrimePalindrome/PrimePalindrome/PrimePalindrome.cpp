// PrimePalindrome.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int j;
	for (int i = 1000; i > 2; i--){
		for (j = 2; j < (i / 2); j++){
			if (i%j == 0)

				j = i; //to make the inner loop quit
			else continue;
		}
		if (j == (i / 2))
			//check for palindrome

		{
			int temp = i;
			int mod;// = 0;
			int rev = 0;
			int q = 1;
			while (temp != 0){
				mod = temp % 10;
				rev = rev * 10 + mod;
				temp = temp / 10;
			}
			if (rev == i)
			{
				cout <<  i;
				i=0; //to make the outer loop quit and exit the program
			}
		}
	}
	//	system("pause");
	return 0;
}

