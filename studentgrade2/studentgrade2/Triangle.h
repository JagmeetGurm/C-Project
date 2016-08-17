#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"


class Triangle : public Shape {
public:
	void SetSides(double a, double b, double c);
	void CheckValidity(vector<Triangle>& vt);
	double GetArea(vector<Triangle>& vt);
private:
	double a;
	double b;
	double c;
	double tperim;
	double area;
};

#endif

