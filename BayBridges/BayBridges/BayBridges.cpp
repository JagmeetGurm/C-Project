// BayBridges.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>


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


class lineSegment {
public:
	//line segment format: l1(x1, y1, x2, y2)
	//lineSegment(point A(double a1, double b1), point B(double a2, double b2)){
	lineSegment(point a, point b){
		z1 = new point(a.X(), a.Y()); //creating a new point to which z1 points
		z2 = new point(b.X(), b.Y());
	//	cout << "print pointer: ";
	//	cout << z1->Y();
		//z2 = b;
		//B = b;
	}
	void aX(point a){
		//z1 = a;
		cout<< a.X();
	}
	//void a(double a)
	void aY(point a){
		cout<<a.Y();
	}
	point* ptA(){
		return z1;
	}
	point* ptB(){
		return z2;
	}

private:
	point* z1;
	point* z2;

};

int main(int argc, _TCHAR* argv[])

{
	//now reading from file
	ifstream infile("inputCoordinate.txt");
	string s;

	while (getline(infile, s)){
		//istringstream iss(s);; 
	//	for(int i = 2; i < s.length(); i++){
			//if (s[i]==(' ')|| s[i]){
	//s = "1: ([37.788353, -122.387695], [37.829853, -122.294312])";
	for (int i = 3; i < s.length(); i++){
		if ((s[i]=='-')||(s[i]=='0') || (s[i] == '1') || (s[i] == '2') || (s[i] == '3') || (s[i] == '4') || (s[i] == '5') || (s[i] == '6') || (s[i] == '7') || (s[i] == '8') || (s[i] == '9'))
		{
			int j = i + 1;
			while ((s[j] != ',')&& s[j] != ']'){
				j++;
			}
			//j--;
			string s2 = s.substr(i, (j - i));
			i = j;
			double num = stod(s2);
			cout << num+100<<endl;
		}
	}
	cout << "next" << endl;
		}
		double a, b, c, d;
		
		
	//	cout << s << endl;
	//}
	point A(3.4, 5);
	point B(8, 9);
	
	//testing points 
	cout << A.X()<<endl; //this should print x coordinate of x.
	cout << A.Y()<<endl;
	lineSegment l1(A, B);
	cout << "lets see: ";
	 l1.aX(A); //this should print the x coordinate of point passed to line segment
	 cout << "now this should print y coordinate of point A: ";
	 cout<< l1.ptA()->Y();
	 cout << "print y coordinate of b: ";
	 cout << l1.ptB()->Y();
	//cout<< p.Y();
//	cout<< p.Y();
	system("pause");
	return 0;
}

