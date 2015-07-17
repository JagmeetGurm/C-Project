#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
#include <math.h>
class Triangle : public Shape{
private:
	double a, b, c;
public:
	Triangle(double s1, double s2, double s3){
		a = s1;
		b = s2;
		c = s3;

	}
	bool checkValidity(){
		if (a>0&&b>0&&c>0)
		return (((a + b) > c) && ((b + c) > a) && ((a + c) > b));


	}

	void setA(double a){
		this->a = a;

	}
	void setB(double b){
		this->b = b;
	}
	void setC(double c){
		this->c = c;
	}
	double getA(){
		return a;
	}
	double getB(){
		return b;
	}
	double getC(){
		return c;
	}
	double getArea(){
		
		double s = (a + b + c) / 2;
		return sqrt(s*(s - a)*(s - b)*(s - c));

	}


};
#endif