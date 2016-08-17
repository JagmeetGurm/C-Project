// quiz1-part2.cpp : Defines the entry point for the console application.
//Here, I have done the problems given in the staircase document provided by Dr. Yeung.

#include "stdafx.h"
#include <iostream>

using namespace std;

//1. You are faced with a staircase of 4 steps.  How many different ways can you get to the top taking 1 step at a time?  
int prob1(int n)
{
	if (n == 0) //f(0)=1
		return 1;
	else if (n == 1) //f(1)=1 when one step left only one way.
		return 1;
	else
		return prob1(n - 1);

}

//2.	You are faced with a staircase of 9 steps.  How many different ways can you get to the top taking either 1 or 2 steps at a time?
int prob2(int n)
{
	if (n == 0) //f(0)=1
		return 1;
	else if (n == 1) //f(1)=1 when one step left only one way to go.
		return 1;
	else
		return prob2(n - 1)+prob2(n-2);

}



//3.	You are faced with a staircase of 4 steps.How many different ways can you get to the top taking 1, 2 or 4 steps at a time ?

int prob3(int n)
{
	if (n < 0) //f(-n)=0
		return 0;
	if (n == 0) //f(0)= 1
		return 1;
	else if (n == 1) //f(1)=1 when only 1 is left there is only one way
		return 1;
	else
		return prob3(n - 1) + prob3(n - 2)+prob3(n-4);

}

//4.	You are faced with a staircase of 7 step.  How many different ways can you get to the top taking either 2 or 3 steps at a time?  
int prob4(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)//f(0)=1
		return 1;
	else if (n == 1)//here f(1) = 0 because only 2 or 3 steps are allowed. so if one is left we cant go all the way up.
		return 0;
	else
		return  prob4(n - 2) + prob4(n - 3);

}


//5.	You are faced with a staircase of 103 steps.How many different ways can you get to the top taking either take 1 or jump 100 steps at a time ?
int prob5(int n)
{
	if (n < 0)
		return 0;
	if (n == 0) //f(0)=1
		return 1;
	else if (n == 1) //here f(1)=1 as one step at a time is allowed.
		return 1;
	else
		return  prob5(n - 1) + prob5(n - 100);

}
//6.	You are faced with a staircase of 1111 steps.  How many different ways can you get to the top taking 3 steps at a time?  
int prob6(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)//f(0)=1
		return 1;
	else if (n == 1) //here f(1)=0 as we are allowed ot take only 3 steps not 1
		return 0;
	else
		return  prob6(n - 3);

}

//7.	 compute the answer to the number of different ways you can get to the top for a staircase of 6 steps with actions of 1 and 5 step-skips
int prob7(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)//f(0)=1
		return 1;
	else if (n == 1) //f(1)=1 taking one step is allowed when left with only one step
	return 1;
	else
		return  prob7(n - 1)+ prob7(n-5);

}
//8.	You are faced with a staircase of 4 steps.  How many different ways can you get to the top taking either 1,3, 4 steps at a time under the condition that it doesn't matter how large the last action is (that is, there is a flat surface for you to land on)?
int prob8(int n)
{
	if (n < 0) //f(-n)=1 because the last action can be any large
		return 1;
	if (n == 0)
		return 1;
	
	else
		return  prob8(n-1)+prob8(n - 3)+prob8(n-4);

}
//
int prob9(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)

		return 1;
	if (n == 1 || n == 3 || n == 5)
		return prob9(n - 2);
	else return prob9(n - 2) + prob9(n - 3) + prob9(n - 6);
}
//10. compute the answer to the number of different ways you can get to the top for a staircase of 6 steps with actions of 1 and 4 step-skips.
int prob10(int n)
{
	if (n < 0)//f(-n)=0
		return 0;
	if (n == 0) //f(0)=1
		return 1;

	else
		return  prob10(n - 1) + prob10(n - 4);

}


//11.	You are faced with a staircase of 4 steps.  How many different ways can you get to the top taking either 1, 2, 4 steps at a time under the condition that it doesn't matter how large the last action is 
int prob11(int n)
{
	if (n < 0) //f(-n)=0
		return 1;
	if (n == 0) //f(0)=1
		return 1;
	
	else
		return  prob11(n - 1) + prob11(n-2)+prob11(n - 4);

}



//14.	Write a C function to compute the number of ways to go up a staircase taking 1-step, 2-step and 4-step skips where the landing at the top extends significantly to accept a final jump of any number of steps
int prob14(int n)
{
	if (n < 0)// f(-n)=1
		return 1;
	if (n == 0) //f(0)=0
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
	cout << "staircase with 7 steps taking 2, 3 or 6 steps at a time, diff ways: " << prob9(7) << endl;
	cout << "staircase with 6 steps taking 1, and 4 steps at a time, diff ways: " << prob10(6) << endl;
	cout << "staircase with 4 steps taking 1, 2 or 4 steps at a time, diff ways: " << prob11(4) << endl;

	cout << "enater the no. of steps for your problem: ";
	cin >> a;
	cout << "staircase with " <<a <<" steps taking 1, 2 or 4 steps at a time, diff ways: " << prob14(a) << endl;
	
	
	system("pause");
	return 0;
}

