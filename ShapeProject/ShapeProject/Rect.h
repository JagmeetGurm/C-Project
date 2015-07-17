#ifndef RECT_H
#define RECT_H
#include "Shape.h"

class Rect: public Shape{
	//two private variables which will be accessed by the public functions 
	//this is using the encapsulation property of OOP.
private:
	double length, width;
public:
	//constructor , assigning parameter values to member variables
	Rect(double a, double b);
	//set functions for changing the values of length and width
	void setLength(double a);
	void setWidth(double  b);
	//get functiions to return length and width of rectangle
	double getLength();
	
	double getWidth();

	double getArea();
};
#endif