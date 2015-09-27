// BoothSimulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <bitset>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a = b00100;
	int b = b00010;
	int c = a + b;
	bitset<5>x(c);
	cout << x;
	return 0;
}

