// quiz1-part2.cpp : Defines the entry point for the console application.
//Here, I have done the problems given in the staircase document provided by Dr. Yeung.

#include "stdafx.h"
#include <iostream>

using namespace std;

int prob1(int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else
		return prob1(n - 1);

}


int prob2(int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else
		return prob2(n - 1)+prob2(n-2);

}

int prob3(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else
		return prob3(n - 1) + prob3(n - 2)+prob3(n-4);

}

int prob4(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	else if (n == 1)
		return 0;
	else
		return  prob4(n - 2) + prob4(n - 3);

}

int prob5(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else
		return  prob5(n - 1) + prob5(n - 100);

}

int prob6(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	else if (n == 1)
		return 0;
	else
		return  prob6(n - 3);

}

int prob7(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	else if (n == 1)
	return 1;
	else
		return  prob7(n - 1)+ prob7(n-5);

}

int prob8(int n)
{
	if (n < 0)
		return 1;
	if (n == 0)
		return 1;
	
	else
		return  prob8(n-1)+prob8(n - 3)+prob8(n-4);

}

int prob10(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;

	else
		return  prob10(n - 1) + prob10(n - 4);

}


int prob11(int n)
{
	if (n < 0)
		return 1;
	if (n == 0)
		return 1;

	else
		return  prob11(n - 1) + prob11(n-2)+prob11(n - 4);

}

int prob14(int n)
{
	if (n < 0)
		return 1;
	if (n == 0)
		return 1;

	else
		return  prob14(n - 1) + prob14(n - 2) + prob14(n - 4);
}
int main()
{
	int a;
	cout<<"staircase with 4 steps taking 1 step at a time, diff ways: "<<prob1(4)<<endl;
	cout << "staircase with 9 steps taking 1 or 2 steps at a time, diff ways: " << prob2(9) << endl;
	cout << "staircase with 4 steps taking 1 , 2 or 4 steps at a time, diff ways: " << prob3(4) << endl;
	cout << "staircase with 7 steps taking 2 or 3 steps at a time, diff ways: " << prob4(7) << endl;
	cout<<"staircase with 103 steps taking 1 or 100 steps at a time, diff ways: " << prob5(103) << endl;
	cout << "staircase with 1111 steps taking 3 steps at a time, diff ways: " << prob6(1111) << endl;
	cout << "staircase with 6 steps taking 1 or 5 steps at a time, diff ways: " << prob7(6) << endl;
	cout << "staircase with 4 steps taking 1, 3 or 4 steps at a time, diff ways: " << prob8(4) << endl;
	cout << "staircase with 6 steps taking 1, and 4 steps at a time, diff ways: " << prob10(6) << endl;
	cout << "staircase with 4 steps taking 1, 2 or 4 steps at a time, diff ways: " << prob11(4) << endl;
	cout << "enater the no. of steps for your problem: ";
	cin >> a;
	cout << "staircase with " <<a <<" steps taking 1, 2 or 4 steps at a time, diff ways: " << prob14(a) << endl;
	
	
	system("pause");
	return 0;
}

