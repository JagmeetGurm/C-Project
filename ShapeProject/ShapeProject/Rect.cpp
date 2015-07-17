#include "stdafx.h"
#include "Rect.h"


	//two private variables which will be accessed by the public functions 
	//this is using the encapsulation property of OOP.

	//constructor , assigning parameter values to member variables
Rect::	Rect(double a, double b){
		length = a;
		width = b;

	}
	//set functions for changing the values of length and width
void Rect:: setLength(double a){
		length = a;
	}
	void Rect:: setWidth(double  b){
		width = b;
	}
	//get functiions to return length and width of rectangle
	double Rect:: getLength(){
		return length;
	}
	double Rect:: getWidth(){
		return width;
	}
	//function to return the area of the rectangle
	double Rect::getArea(){
		return length*width;


	}
	bool Rect::checkValidity(){
		return (length >= 0 && width >= 0);
	}
