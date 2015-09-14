// BayBridges.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// need an algo for finding intersection of two lines

//reading file 

//structure for coordinate values
//structure for points
class point{
	point(double a, double b){
		x = a;
		y = b;
	}
	double X(){
		return x;
	}
private:
	double x, y;
};
class lineSegment{
public:
	//line segment format: l1(x1, y1, x2, y2)
	lineSegment(double a1, double b1, double a2, double b2){
		x1 = a1;
		y1 = b1;
		x2 = a2;
		y2 = b2;
	}
	//void a(double a)
private:
	double x1, y1, x2, y2;
	

};

int _tmain(int argc, _TCHAR* argv[])
{
	lineSegment l1([2, 3], [4, 5]);
	return 0;
}

