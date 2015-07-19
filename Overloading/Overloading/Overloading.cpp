// Overloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PrintData.h"
#
#include <iostream>
using namespace std;

int main(int argc, _TCHAR* argv[])
{
	PrintData p;
	
	p.print(5); //this will give call to print integer as int is argument
	p.print("jim, hello!"); //the char print function
	p.print(4.5); //the float print function

	//box declarations
	Box b1;

	system("pause");

	return 0;
}

