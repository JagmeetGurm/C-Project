#include "stdafx.h"
#include "Triangle.h"

Triangle::Triangle(double s1,double s2, double s3){
	a = s1;
	b = s2;
	c = s3;

}
bool Triangle::checkValidity(){
	if (a>0 && b>0 && c>0)
		return (((a + b) > c) && ((b + c) > a) && ((a + c) > b));


}

void Triangle::setA(double a){
	this->a = a;

}
void Triangle::setB(double b){
	this->b = b;
}
void Triangle::setC(double c){
	this->c = c;
}
double Triangle::getA(){
	return a;
}
double Triangle::getB(){
	return b;
}
double Triangle::getC(){
	return c;
}
double Triangle::getArea(){

	double s = (a + b + c) / 2;
	return sqrt(s*(s - a)*(s - b)*(s - c));

}

