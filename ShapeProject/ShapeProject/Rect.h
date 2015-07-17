#ifndef RECT_H
#define RECT_H
#include "Shape.h"

class Rect {
	//two private variables which will be accessed by the public functions 
	//this is using the encapsulation property of OOP.
private:
	double length, width;
public:
	//constructor , assigning parameter values to member variables
	Rect(double a, double b){
		length = a;
		width = b;

	}
	//set functions for changing the values of length and width
	void setLength(double a){
		length = a;
	}
	void setWidth(double  b){
		width = b;
	}
	//get functiions to return length and width of rectangle
	double getLength(){
		return length;
	}
	double getWidth(){
		return width;
	}

	double getArea(){
		return length*width;

	}

};
#endif