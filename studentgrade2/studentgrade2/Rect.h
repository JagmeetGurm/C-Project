#ifndef RECT_H
#define RECT_H
#include "Shape.h"


class Rect : public Shape {
public:
	void SetSides(double l, double w);
	void CheckValidity(vector<Rect>& vt);
	double GetArea(vector<Rect>& vt);
private:
	double a;
	double b;
	long area;
};

#endif
