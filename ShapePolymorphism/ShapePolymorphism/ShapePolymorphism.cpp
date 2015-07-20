// ShapePolymorphism.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Shape.h"
#include "Rect.h"

#include <iostream>


using namespace std;



int main()
{
	Rect rec(4, 5);
	Shape* r = &rec;

cout<<	r->getArea()<<endl;





	
	//Shape* rec = 
system("pause");
	return 0;
}

