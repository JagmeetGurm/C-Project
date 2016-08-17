#ifndef Triangle_H
#define Triangle_H
#include "Shape.h"

class Triangle :public Shape
{
public:
	Triangle();
	void setSideA(double a);
	void setSideB(double b);
	void setSideC(double c);

	double getSideA();
	double getSideB();
	double getSideC();

	bool checkValidity();
	double getArea();
private:
	double sideA;
	double sideB;
	double sideC;
};

#endif