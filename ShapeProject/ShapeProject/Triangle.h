#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
#include <math.h>
class Triangle : public Shape{
private:
	double a, b, c;
public:
	Triangle(double s1, double s2, double s3);
	
	
	bool checkValidity(); 

	void setA(double a); 
	void setB(double b); 
	void setC(double c);
	double getA();
	double getB();
	double getC();
	
	double getArea();
	

	



};
#endif