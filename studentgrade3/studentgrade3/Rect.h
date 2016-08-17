#ifndef Rect_H
#define Rect_H
#include "Shape.h"

class Rect : public Shape
{
public:
	Rect();
	void setHeight(double height);
	void setWidth(double width);

	double getHeight();
	double getWidth();

	bool checkValidity();
	double getArea();
private:
	double height;
	double width;
};

#endif
