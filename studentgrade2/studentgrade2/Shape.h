#ifndef SHAPE_H
#define SHAPE_H
using namespace std;


class Shape {
public:
	virtual bool CheckValidity(double l, double w);	//"virtual" to let program determine which class to pull function from
	virtual double GetArea();
private:
	double a;
	double b;
};

#endif
