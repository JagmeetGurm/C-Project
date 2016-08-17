#include "stdafx.h"
#include "Triangle.h"
#include <iostream>
#include <math.h>
using namespace std;

Triangle::Triangle()
{

}
void Triangle::setSideA(double a)
{
	sideA = a;
}
void Triangle::setSideB(double b)
{
	sideB = b;
}
void Triangle::setSideC(double c)
{
	sideC = c;
}

double Triangle::getSideA()
{
	return sideA;
}
double Triangle::getSideB()
{
	return sideB;
}
double Triangle::getSideC()
{
	return sideC;
}

bool Triangle::checkValidity()
{
	if (sideA < 0 && sideB < 0 && sideC < 0)
		return false;

	else if (sideA + sideB < sideC || sideC + sideB < sideA || sideA + sideC < sideB)
		return false;

	else
		return  true;
}
double Triangle::getArea()
{
	double p = sideA + sideB + sideC / 2;
	double area = sqrt(p*(p - sideA)*(p - sideB)*(p - sideC));

	return area;
}