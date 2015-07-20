// Overloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PrintData.h"
#include "Box.h"
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
	Box b2;
	Box b3;

	//box 1 specification
	b1.setLength(5);
	b1.setWidth(7.9);
	b1.setHeight(2);
	cout << "volume of box 1: " << b1.getVolume()<<endl;


	//box 2 specification 

	b2.setLength(3);
	b2.setWidth(9);
	b2.setHeight(6);
	cout << "volume of box 2: " << b2.getVolume() << endl;
	//box 3 specification
	b3 = b1 + b2;
	

	cout << "volume of box 3: " << b3.getVolume();




	system("pause");

	return 0;
}

