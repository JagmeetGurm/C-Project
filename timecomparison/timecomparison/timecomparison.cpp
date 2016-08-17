// timecomparison.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "stdlib.h"
#include"time.h"
#include <vector>
#include "math.h"
using namespace std;


void sequential_search(vector<int>v, int search)//sequential search function
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == search)
			cout << endl;


	}

}
void binary_search(vector<int>v, int l, int h, int search)//binary search function
{
	int middle = (l + h) / 2;
	while (v[middle] != search&&l <= h)
	{
		if (v[middle] < search)
		
			l = middle + 1;
		else if (v[middle]>search)
			h = middle - 1;
		else break;
		middle = (l + h) / 2;
	}
	
	cout << endl;
}
int main()
{
	int N, choice;
	vector <int> v; //creating a vector 
	int search=0;
	int i;
	cout << "enter the ith value  less than 8: "; //enter the ith power for 10
	cin >> i;
	N = pow(10,i);
	cout << N;
	for (int i = 1; i <= N; i++) //storing elements in vector
	{
		v.push_back(i);
	}
	cout << "\nenter 1 for binary search and 2 for sequential search:"<<endl; //1 for binary, 2 for sequential
		cin >> choice;
		if (choice == 1) //if choice is binary
		{
			srand(time(NULL));

			int start = clock();
			for (int i = 0; i < 1000; i++)
			{
				search = rand() % N + 1;
				binary_search(v, 0, N - 1, search);		
			}
			int stop = clock();
			int difference = (stop - start) / double(CLOCKS_PER_SEC) * 1000;
			cout << "\nbinary time:" << difference << endl;
		}
		if (choice==2) //if choice is sequential
		{
			srand(time(NULL));
			int start2 = clock();
			for (int i = 0; i < 1000; i++)
			{
				search = rand() % N + 1;
				sequential_search(v, search);	
			}
			int stop2 = clock();
			int difference2 = (stop2 - start2) / double(CLOCKS_PER_SEC) * 1000;
			cout << "\nsequential time: " << difference2 << endl;
		}
		else cout << "\n sorry, try again" << endl;
	system("pause");
	return 0;
}

