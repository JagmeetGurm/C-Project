#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

using namespace std;

class Shape{
protected:
	int length, width;
public:
	Shape(int a, int b){
		length = a;
		width = b;

	}

	int getArea(){
		cout << "the area is: ";
		return 0;
	}
};
#endif