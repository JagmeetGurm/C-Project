#include <iostream>
#include <queue>
#include <string>

using namespace std;

//point class reflecting the coordinate position of each startup
class point{
public:
	point();
	point(double a, double b){
		x = a; //the x coordinate of point
		y = b; // the y coordinate of point
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


int main() {
	point p(4,5);
	cout<<p.X();
	return 0;
}
