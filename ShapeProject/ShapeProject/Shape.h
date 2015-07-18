#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;
//abstract class shape
class Shape{

	//two public functions which will be overwritten by the inherited classes
public:
	//pure virtual functions
virtual	bool checkValidity()=0;
virtual double getArea()=0;
//double length, width;


};
#endif