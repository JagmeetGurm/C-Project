// ShapeProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Shape.h"
#include "Rect.h"
#include "Triangle.h"
#include <iostream> 
#include <vector>
#include <fstream>


using namespace std;

void saveRarea(vector<Shape*>v1){
	ofstream outputRect;
	outputRect.open("outRect.txt");
	for (int i = 0; i < v1.size(); i++){
		outputRect << "\narea Rectangle " << (i + 1) <<": "<< v1.at(i)->getArea();

	}
	outputRect.close();

}

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

	//3rd way: 
	Rect r1(1,2);
	
	Rect* rectTwo = &r1;
	
	cout<<"is this valid rectangle? "<<rectTwo->checkValidity();
	cout << "\n the old area of rectangle: " << rectTwo->getArea();
	cout << endl;




	///second way: instance of Triangle class
	 
	Triangle triOne(2, 6, 5);
	cout<<"\nIs triangle object valid? "<<triOne.checkValidity();
	cout << "\nthe old area: " << triOne.getArea();
	cout << "\nthe new side: ";

		triOne.setB(5);
		cout << triOne.getB();
		cout << "\n the new area triangle: " <<triOne.getArea();
		cout << endl;

		//4th way: instance of Triangle
		Triangle t1(1, 2, 3);
		t1.setA(4);
		Shape* triTwo = new Triangle(4,5, 8);
	cout<<"\nLet's see this: "<<	triTwo->checkValidity();
	cout<<"the area is: "<<triTwo->getArea();
//	triTwo->setA(4);

	vector<Shape*>recVector;
	double a, b;
	Shape* recNew;
	ifstream rectSides;
	rectSides.open("inpRect.txt");
	while (rectSides >> a >> b){
		recNew = new Rect(a, b);
		if (recNew->checkValidity())
			recVector.push_back(recNew);


	}
	rectSides.close();
	cout<<"\nnew area of 2nd rect: "<<recVector.at(1)->getArea();
	saveRarea(recVector);

	vector<Shape*>triVector;
	double c;
	ifstream triSides;
	Shape* triNew;
	triSides.open("inpTri.txt");
	while (triSides >> a >> b >> c){
		triNew = new Triangle(a, b, c);
		if (triNew->checkValidity())
			triVector.push_back(triNew);

	}
	triSides.close();
	cout << "\nnew area of 2nd tri: " << triVector.at(1)->getArea();

	system("pause");

	return 0;
}

