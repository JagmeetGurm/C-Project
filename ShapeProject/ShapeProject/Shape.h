#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;
//abstract class shape
class Shape{

	//two public functions which will be overwritten by the inherited classes
protected:
	bool checkValidity();
double getArea();
//double length, width;


};
#endif