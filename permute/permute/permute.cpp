// permute.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int>&v, int index, int last)  //swapping values
{
	int temp = v[index];
	v[index] = v[last];
	v[last] = temp;
}
void permutation(vector<int>&vec, int ind, int last)
{
	if (ind == last) //base step
	{
		for (int i = 0; i <= last; i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl;
	}
	else   //inductive step
	{
		for (int i = ind; i <= last; i++)
		{

			swap(vec, ind, i);
			permutation(vec, ind + 1, last);
			swap(vec, ind, i);
		}
	}
}

int main()
{
	vector<int>per;
	int number;
	cout << "please enter your positive natural no. for all permutations: ";
	cin >> number;
	for (int i = 1; i <= number; i++)
		per.push_back(i);
	permutation(per, 0, number-1);
	system("pause");
	return 0;
}



