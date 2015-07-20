#ifndef RECT_H
#define RECT_H
#include "Shape.h"
#include <iostream>
using namespace std;

class Rect: public Shape{
public:
	Rect(int a, int b):Shape(a,b){}
	int getArea(){
		return (length*width);

	}
	
};
#endif