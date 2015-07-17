// ShapeProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Shape.h"
#include "Rect.h"
#include <iostream> 

using namespace std;

int main(int argc, _TCHAR* argv[])

{
	Rect* rectOne;  //one way : instance of Rect class
	rectOne = new Rect(5, 6);
	cout<<"Is rectangle?: "<<rectOne->checkValidity();
	cout << "\nThe old area: " << rectOne->getArea();
	rectOne->setLength(6);
	cout<<"\nThe new width of rectangle is: "<<rectOne->getWidth();
	cout << "\nThe new area is: " << rectOne->getArea();
	cout << endl;

	system("pause");

	return 0;
}

