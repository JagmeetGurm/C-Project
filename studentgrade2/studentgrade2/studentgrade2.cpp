#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

#include "Shape.h" 			//include file for parent class declaration "Shape"
#include "Shape.cpp"		//include file for Shape function definitions
#include "Rect.h"			//include file for child class declaration "Rect" (Rectangle)
#include "Rect.cpp"			//include file for Rect function definitions
#include "Triangle.h"		//include file for child class declaration "Triangle"
#include "Triangle.cpp"		//include file for Triangle function definitions

int main(){
	vector<Rect> rct;		//create vector for rectangle objects
	vector<Triangle> tri;	//create vector for triangle objects

	Rect r;					//new rect object to be inserted into vector
	r.CheckValidity(rct);	//set sides and check validity
	r.GetArea(rct);			//print areas of all rectangles in vector to Rareas.txt

	Triangle trin;			//new triangle object to be inserted into vector
	trin.CheckValidity(tri);//set sides and check validity
	trin.GetArea(tri);		//print areas of all triangles in vector to Tareas.txt

	return 0;				//end
}
