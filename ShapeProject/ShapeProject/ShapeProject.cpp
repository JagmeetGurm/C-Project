// ShapeProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Shape.h"
#include "Rect.h"
#include "Triangle.h"
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


	///second way: instance of Triangle class
	 
	Triangle triOne(2, 6, 5);
	cout<<"\nIs triangle object valid? "<<triOne.checkValidity();
	cout << "\nthe new side: ";

		triOne.setB(5);
		cout << triOne.getB();
		cout << "\n the new area triangle: " <<triOne.getArea();
		cout << endl;





	system("pause");

	return 0;
}

