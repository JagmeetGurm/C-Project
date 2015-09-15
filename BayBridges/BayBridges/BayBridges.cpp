// BayBridges.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
// need an algo for finding intersection of two lines

//reading file 

//structure for coordinate values
//structure for points
class point{
public:
	point();
	point(double a, double b){
		x = a;
		y = b;
	}
	double X(){
		return x;
	}
	double Y(){
		return y;
	}
private:
	double x, y;
};
class lineSegment{
public:
	//line segment format: l1(x1, y1, x2, y2)
	//lineSegment(point A(double a1, double b1), point B(double a2, double b2)){
	lineSegment(point, point){

	}
	void aX(point a){
		cout<< a.X();
	}
	//void a(double a)
	void aY(point a){
		cout<<a.Y();
	}
	

};

int main(int argc, _TCHAR* argv[])
{
	point A(3.4, 5);
	point B(8, 9);
	
	//testing points 
	cout << A.X()<<endl; //this should print x coordinate of x.
	cout << A.Y()<<endl;
	lineSegment l1(A, B);
	cout << "lets see: ";
	 l1.aX(A);
	system("pause");
	return 0;
}

